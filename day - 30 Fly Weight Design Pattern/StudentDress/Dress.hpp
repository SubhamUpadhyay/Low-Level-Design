#pragma once
#include<bits/stdc++.h>
using namespace std;

//Shared part - Student Dress 
class Dress{
    private:
        string style;
        string color;
    public:
        Dress(string style , string color):style(style),color(color){};
        void wear(string size)
            {
                cout<<"Wearing a "<<color<<" "<<style<<" dress of size "<<size<<"\n";
            }
};

