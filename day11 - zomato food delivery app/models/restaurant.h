#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "menu.h"
using namespace std;
class restaurant
{
private:
    static int nextRestaurant_id;
    int restaurant_id;
    string name;
    string location;
    vector<menu>menu_item;

public:
    restaurant(const string &name, const string &location) 
    : name(name), location(location) { restaurant_id = ++nextRestaurant_id;};

    ~restaurant(){
        cout<<"Destroying Restaurant "<<name<<" , and clearing its menu item"<<endl;

    }

    //getter setter for name

    void getName()
        {
            cout<<endl<<"Restaurant Name :"<<name;
        }
    void setName(string name){this->name = name;};


        //getter setter for location
    
    void getLocation(){
        cout<<"Restaurant Location "<<location <<endl;
        
    }
    void setLocation(){this->location = location;};


    //getter setter for menuItem  
    void setMenu(const menu &menuPit)
        {menu_item.push_back(menuPit);}

    const vector<menu> &getMenu(){
        return menu_item;
    }



};

int restaurant::nextRestaurant_id=0;

#endif