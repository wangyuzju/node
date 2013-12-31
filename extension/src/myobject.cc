/*
 * myobject.cc
 *
 *  Created on: Dec 26, 2013
 *      Author: wangyu
 */

#include <node.h>
#include "myobject.h"

//using namespace v8;

//Persistent<Function> MyObject::constructor;

MyObject::MyObject(double value) : value_(value) {
}

MyObject::~MyObject() {
}
void Plus(const v8::FunctionCallbackInfo<Value>& args);

void MyObject::Init(Handle<Object> target){
	Isolate* isolate = Isolate::GetCurrent();
//	target->Set(String::NewSymbol("name"), String::NewSymbol("wangyu"));

	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
	tpl->SetClassName(String::New("MyObejct"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	tpl->PrototypeTemplate()->Set(String::New("add"), FunctionTemplate::New(Add)->GetFunction());
//	constructor = Persistent<Function>::New(tpl->GetFunction());
	target->Set(String::NewSymbol("MyObject"), tpl->GetFunction());

}

void MyObject::New(const v8::FunctionCallbackInfo<Value>& args){
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	if (args.IsConstructCall()){
		double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
//		printf("%f", value);
		MyObject* obj = new MyObject(value);
		obj->Wrap(args.This());
//		args.GetReturnValue().Set();
	}else {
		const int argc = 1;
		Local<Value> argv[argc] = {
				args[0]
		};
		args.GetReturnValue().Set(String::New("hello wangyu ~"));
	}
}

void MyObject::Add(const v8::FunctionCallbackInfo<Value>& args){
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	MyObject *obj = ObjectWrap::Unwrap<MyObject>(args.This());
	obj->value_ += 1;
	args.GetReturnValue().Set(Number::New(obj->value_));
}

void Plus(const v8::FunctionCallbackInfo<Value>& info){
//	printf("hello C++!");
	info.GetReturnValue().Set(String::New("hello C++!"));
}
