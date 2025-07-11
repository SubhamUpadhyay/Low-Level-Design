#ifndef CHANNEL_H
#define CHANNEL_H
#include "Ichannel.h"
#include<bits/stdc++.h>
using namespace std;
class channel : public Ichannel{
    private:
        string channel_name;
        string latest_video;
        vector<Isubscriber *>list;

    public:

        channel(const string &name):channel_name(name){};
        void subscribe(Isubscriber *subscriber_account) override{
            if(find(list.begin(),list.end(),subscriber_account)==list.end())
                {
                    list.push_back(subscriber_account);
                }
        }

        void unsubscribe(Isubscriber *subscriber_account) override{
            auto it = find(list.begin(),list.end(),subscriber_account);
            if(it != list.end())
                {
                    list.erase(it);
                }
        }


        void notify() override{
            for(Isubscriber *it :list )
                {
                    it->update();
                }
        }

        void uploadVideo(const string &title)
            {
                latest_video = title;
                cout<<endl<<"new video uploaded :"<<title<<endl; 
                notify();
            } 

        string getVideoDATA(){
            return "\n checkout our new video : "+latest_video+" click on the title to watch \n";
        }
};

#endif