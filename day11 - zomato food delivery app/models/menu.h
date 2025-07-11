#ifndef MENU_H
#define MENU_H
#include <bits/stdc++.h>
using namespace std;
class menu
{
private:
    string item_no;
    string name;
    int price;
public:
    menu( const string &item_no, const string &name, int price)
        : item_no(item_no), name(name), price(price) {}

    string getItem_NO() const { return item_no; }
    void setItem_NO(const string& code) { item_no = code; }

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getPrice() const { return price; }
    void setPrice(int price) { this->price = price; }
};
#endif