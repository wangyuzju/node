#include <node.h>
#include <libnotify/notify.h>
#include "notification.h"

Notification::~Notification() {
}

void Notification::New(const v8::FunctionCallbackInfo<Value>& info){
	notify_init ("Hello world!");
	NotifyNotification * Hello = notify_notification_new ("Hello world", "This is an example notification.", "dialog-information");
	notify_notification_show (Hello, NULL);
	g_object_unref(G_OBJECT(Hello));
	notify_uninit();
}

void Notification::Update(const v8::FunctionCallbackInfo<Value>&info ){

}
