#include<bits/stdc++.h>
using namespace std;
class Telegram{
    public:
       virtual  void PostStory() = 0;
       ~Telegram(){};
};
class RealStory : public Telegram{
    public:
        void PostStory() override{
            cout<<"Story Posted On Telegram"<<endl;
        }
};

class StoryProxy : public Telegram{
    private:
    bool isPremium ;
    RealStory *realstory;
    public:
        StoryProxy(bool premium):isPremium(premium),realstory(nullptr){};
        void PostStory() override{
            if(isPremium)
                {
                    if(realstory == nullptr)
                        realstory = new RealStory();
                    realstory->PostStory();
                }
            else
                {
                    cout<<"Premium Required !!!!"<<endl;
                }
        }
    ~StoryProxy(){
        delete realstory;
    };

};


int main()
{
    Telegram *user1 = new StoryProxy(false);
    Telegram *user2 = new StoryProxy(true);
    cout<<endl<<" When Premium = False"<<endl;
    user1->PostStory();

    cout<<endl<<"When Premium = True"<<endl;
    user2->PostStory();

    delete user1,user2;
    return 0;
}