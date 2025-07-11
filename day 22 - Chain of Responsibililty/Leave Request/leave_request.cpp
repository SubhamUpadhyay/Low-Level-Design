#include <bits/stdc++.h>
using namespace std;
class Leave
{
protected:
    Leave *leave;

public:
    Leave() : leave(nullptr) {};
    void tryChain(Leave *next)
    {
        leave = next;
    }
    virtual void askLeave(int days) = 0;
    ~Leave() {};
};
class TeamLead : public Leave
{
public:
    void askLeave(int days) override
    {
        if (days <= 2)
        {
            cout << "Leave Approved by TeamLead";
            return;
        }
        else
        {
            cout << "Leave Request cannot be fulfilled byt the Team Lead trying the Manager" << endl;
            if (leave)
            {
                leave->askLeave(days);
            }
        }
    }
};
class Manager : public Leave
{
public:
    void askLeave(int days) override
    {
        if (days <= 4)
        {
            cout << "Leave Approved by Manager";
            return;
        }
        else
        {
            cout << "Leave Request cannot be fulfilled byt the Manager trying the Director" << endl;
            if (leave)
            {
                leave->askLeave(days);
            }
        }
    }
};
class Director : public Leave
{
public:
    void askLeave(int days) override
    {
        if (days <= 6)
        {
            cout << "Leave Approved by Director";
            return;
        }
        else
        {
            cout << "Leave Request cannot be fulfilled" << endl;
            return;
        }
    }
};
int main()
{
    Leave *p1 = new TeamLead();
    Leave *p2 = new Manager();
    Leave *p3 = new Director();
    p1->tryChain(p2);
    p2->tryChain(p3);
    vector<int> arr = {2, 4, 6, 8};
    for (auto val : arr)
    {
        cout<<"\n....................................\n";
        cout<<"Request leave days : "<<val<<endl;
        p1->askLeave(val);
        cout<<"\n....................................\n";
    }
    return 0;
}