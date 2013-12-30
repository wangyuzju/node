/*
 * myobject.cc
 *
 *  Created on: Dec 26, 2013
 *      Author: wangyu
 */


#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <node_object_wrap.h>
#include "myobject.h"

using namespace v8;

Persistent<Function> MyObject::constructor;

MyObject::MyObject(double value) : value_(value) {
}

MyObject::~MyObject() {
}

void MyObject::Init(Handle<Object> target){


	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::New("MyObejct"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	tpl->PrototypeTemplate()->Set(String::New("add"), FunctionTemplate::New(Plus)->GetFunction());
	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("MyObject"), constructor);
}

void MyObject::New(const FunctionCallback<Value>& args){
	HandleScope
}
