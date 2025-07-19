#pragma once
#include<string>
using namespace std;

class Colleague;
class Mediator{
    public:
        virtual void sendMessage(const string&msg,Colleague*sender ) = 0;
        virtual ~Mediator(){};
};