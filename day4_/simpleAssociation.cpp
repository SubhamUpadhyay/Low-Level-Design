#include<bits/stdc++.h>
using namespace std;

class teacher
    {
        public:
        teacher()
            {
                cout<<"Teacher is teaching ";
            }
    };
class student
    {
        public:
         student(teacher *t)
            {
                t = new teacher{};
                cout<<endl<<"Student learns";
            }


    };

int main()
{
    teacher *t1;
    student *s1 = new student(t1);
    return 0;
}