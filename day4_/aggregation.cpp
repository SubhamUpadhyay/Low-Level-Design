#include<bits/stdc++.h>
using namespace std;

/*One class has another class object
    but the lifetime is independent 
    usually implemented with pointer or references
*/

class Department{
    public:
        void show()
            {
                cout<<endl<<"Department Info !";
            }
};

class university{
    private:
    Department *dept;   //->Aggregration (External reference);
    public:
        university(Department *d):dept(d){};
                //this could be written as 
                    /*  
                        university(Department *d)
                            dept  = d;
                    */

        void info()
            {
                dept->show();
                cout<<endl<<"Univeristy Info!";
            }
};
int main()
    {
        Department *de;
        university *d = new university(de);
        d->info();

    }