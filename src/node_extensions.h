// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SRC_NODE_EXTENSIONS_H_
#define SRC_NODE_EXTENSIONS_H_

#if HAVE_OPENSSL
# define NODE_EXT_LIST_SSL(ITEM)                                              \
    ITEM(node_crypto)                                                         \
    ITEM(node_tls_wrap)
#else
# define NODE_EXT_LIST_SSL(ITEM)
#endif  // HAVE_OPENSSL

#define NODE_EXT_LIST(START, ITEM, END)                                       \
    START                                                                     \
    ITEM(node_buffer)                                                         \
    NODE_EXT_LIST_SSL(ITEM)                                                   \
    ITEM(node_contextify)                                                     \
    ITEM(node_fs)                                                             \
    ITEM(node_http_parser)                                                    \
    ITEM(node_os)                                                             \
    ITEM(node_smalloc)                                                        \
    ITEM(node_zlib)                                                           \
                                                                              \
    ITEM(node_uv)                                                             \
    ITEM(node_timer_wrap)                                                     \
    ITEM(node_tcp_wrap)                                                       \
    ITEM(node_udp_wrap)                                                       \
    ITEM(node_pipe_wrap)                                                      \
    ITEM(node_cares_wrap)                                                     \
    ITEM(node_tty_wrap)                                                       \
    ITEM(node_process_wrap)                                                   \
    ITEM(node_fs_event_wrap)                                                  \
    ITEM(node_signal_wrap)                                                    \
                                                                              \
    END                                                                       \

#endif  // SRC_NODE_EXTENSIONS_H_

/**
 * 	NODE_EXT_LIST(NODE_EXT_LIST_START, NODE_EXT_LIST_ITEM, NODE_EXT_LIST_END)
 *
 * 	# step 1
 * 	NODE_EXT_LIST(
 * 		node::node_module_struct *node_module_list[] = {,
 * 		NODE_EXT_STRING,
 * 		NULL};
 * 		)
 *
 * 	# step 2
 * 	node::node_module_struct *node_module_list[] = {
 * 		NODE_EXT_STRING(node_buffer)
 * 		NODE_EXT_STRING(node_contextify)
 * 		...
 * 	}
 *
 * 	# step 3
 * 	node::node_module_struct *node_module_list[] = {
 * 		...
 * 		&node_contextify_module,
 * 		...
 * 	}
 *
 * 	# step 4
 * 	// defined in node.h line:237
 * 	node::node_module_struct node_contextify_module = {
 *
 * 	}
 *
 * 	## step 4.1
 * 	#define NODE_MODULE_CONTEXT_AWARE(modname, regfunc)        \
 * 		extern 'C' {                                           \
 * 			node::node_module_struct modname ## _module = {    \
 * 				NODE_MODULE_VERSION,   						   \	//int version;
 * 				NULL,										   \	//void *dso_handle;
 * 				__FILE__,									   \	//const char *filename;
 * 				NULL,										   \  	//node::addon_register_func register_func;
 * 				(regfunc),				 					   \	//node::addon_context_register_func register_context_func;
 * 				NODE_STRINGIFY(modname) 					   \  	//const char *modname
 * 			}
 * 		}
 */