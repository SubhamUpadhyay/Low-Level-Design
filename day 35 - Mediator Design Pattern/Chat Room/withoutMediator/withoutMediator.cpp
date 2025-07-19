#include<bits/stdc++.h>
using namespace std;
// Each User knows *all* the others directly.
// If you have N users, you wind up wiring N*(N–1)/2 connections,
// and every new feature (mute, private send, logging...) lives in User too.


class User{
    private:
        string name;
        vector<User*>peers;
        vector<string>mutedUsers;
    public:
        User(const string &n):name(n){};
        void addPeer(User *u)
            {
                peers.push_back(u);
            }
        void mute(const string& userToMute)
            {
                mutedUsers.push_back(userToMute);
            }

            //broadcast to all
        void send(const string &msg)
            {
                for(auto *it:peers)
                    {
                        if(!it->isMuted(name))
                            {
                                it->receive(name,msg);
                            }
                    }
            }


            bool isMuted(string userName)
                {
                    for(auto name : mutedUsers)
                        {
                            if(name==userName)
                                return true;
                        }
                    return false;
                }

            //private send - duplicated in every class
            void sendTo(User *target , const string&msg)
                {
                    cout<<name<<" -> "<<target->name<<"   "<<msg<<endl;
                }

            void receive(const string &from , const string &msg)
                {
                    cout<<name<<" got message:  "<<msg<<endl;
                }

};

int main()
{

    User *user1 = new User("Rohan");
    User *user2 = new User("Neha");
    User *user3 = new User("Mohan");


    user1->addPeer(user2);
    user2->addPeer(user1);
    user1->addPeer(user3);
    user3->addPeer(user1);
    user2->addPeer(user3);
    user3->addPeer(user2);


    user1->mute("Mohan");
    user1->send("Hello Everyone");
    user3->sendTo(user2,"Hey Neha !");

    delete user1;
    delete user2;
    delete user3;
    return 0;
}