#include "channel.h"    
#include "subscriber.h"
int main()
    {
        channel techChannel("TechnTuts");
        subscriber s1("Alice ", &techChannel);
        subscriber s2("bob ", &techChannel);

        techChannel.subscribe(&s1);
        techChannel.subscribe(&s2);

        techChannel.uploadVideo("Observer Pattern in c++");
        techChannel.unsubscribe(&s1);

        techChannel.uploadVideo("Factory Pattern Explained");

        return 0;
    }