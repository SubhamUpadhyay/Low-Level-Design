#include<bits/stdc++.h>
using namespace std;
#include "models/restaurant.h"  
#include "models/menu.h"
int main()
    {
        restaurant r1("Red Spice","Delhi");

        menu m1("1","curry",250);
        menu m2("2","desert",300);
        menu m3("3","dinner",500);
        

        r1.setMenu(m1);
        r1.setMenu(m2);
        r1.setMenu(m3);

        vector<menu>menu_item = r1.getMenu();
        for(auto it : menu_item)
            {
                cout<<"Item no :"<<it.getItem_NO();
                cout<<"name :"<<it.getName();
                cout<<"price :"<<it.getPrice();

                cout<<"\n\n\n";
            }



            return 0;
    }