/*
 * Notify.h
 *
 *  Created on: Jan 3, 2014
 *      Author: wangyu
 */


#include <node.h>
#include <node_object_wrap.h>

using namespace v8;

class Notification: public node::ObjectWrap {
public:
	static void New(const v8::FunctionCallbackInfo<v8::Value>& );
	static void Update(const v8::FunctionCallbackInfo<v8::Value>& );

private:
	~Notification();
	// show notification with title, content, icon
	static void Show(char *, char *, char * = "dialog-information");

	void* pNotify_;
};
