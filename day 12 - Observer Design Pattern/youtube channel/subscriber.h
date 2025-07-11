#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "Isubscriber.h"
#include "channel.h"
#include <bits/stdc++.h>
using namespace std;
class subscriber : public Isubscriber{
    private :
        string name ;
        channel *channel_obj;
    public:
        subscriber(const string &name,channel *channel_obj):name(name),channel_obj(channel_obj){};
        void update() override
            {
                cout<<"Hey ! "<<name <<"  "<<channel_obj->getVideoDATA();
            }
};
#endif