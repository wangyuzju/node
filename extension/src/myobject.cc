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
	target->Set(String::NewSymbol("foo"), String::New("bar"));
}
