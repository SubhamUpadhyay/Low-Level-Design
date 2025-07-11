#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H
#include<bits/stdc++.h>
using namespace std;
class Isubscriber{
    public:
    virtual void update()=0;
    ~Isubscriber(){};
};
#endif