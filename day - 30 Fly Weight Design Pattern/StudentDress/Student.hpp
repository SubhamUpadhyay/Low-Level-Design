#pragma once
#include "Dress.hpp"    
#include <bits/stdc++.h>
using namespace std;
class Student{
    private:
        string name;
        string dressSize;
        Dress *dress;
    public:
        Student(string name , string size , Dress *dress):name(name),dressSize(size),dress(dress){};
        void show()
            {
                cout<<name<<" ";
                dress->wear(dressSize);
            } 

};