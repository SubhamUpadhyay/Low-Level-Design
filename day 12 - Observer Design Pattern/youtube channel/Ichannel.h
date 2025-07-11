#ifndef ICHANNEL_H
#define ICHANNEL_H
#include "Isubscriber.h"
#include<bits/stdc++.h>
using namespace std;
class Ichannel{
    public:
    virtual void subscribe(Isubscriber *O)=0;
    virtual void unsubscribe(Isubscriber *O)=0;
    virtual void notify()=0;
    ~Ichannel(){};
};
#endif