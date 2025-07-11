#include<bits/stdc++.h>
using namespace std;
class user{
    public:
        virtual void setPassword(string password)
            {
                if(password.length() < 8)
                    {
                        throw invalid_argument("parent Class :password must be atleast 8 character long");

                    }
                cout<<endl<<"parent class : Password set successfully !";
            }
};


class AdminUser : public user{
    public:
        void setPassword(string password) override{
            if(password.length() < 6)
                {
                    throw invalid_argument("Child Class :Password length should be atleast 6 character long");   

                }
            cout<<endl<<"child class : Password set successfully !";
        }
};

int main()
    {
        user *user = new AdminUser{};
        user -> setPassword("ABCDEF");

        return 0;
    }