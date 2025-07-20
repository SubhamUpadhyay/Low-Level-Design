#pragma once
#include "Resume.hpp"

class MyResume : public Resume {
private:
    string name;
    string phone;
    string email;
    string position;
public:
    MyResume(const string& n, const string& p, const string& e)
        : name(n), phone(p), email(e), position("Not Set") {}

    // Copy constructor
    MyResume(const MyResume& other)
        : name(other.name), phone(other.phone), email(other.email), position(other.position) {}

    Resume* clone() const override {
        return new MyResume(*this);  // Deep copy    //passing my reference that have name , phone , email
    }

    void setPosition(const string& pos) override {
        position = pos;
    }

    void print() const override {
        cout << "============================\n";
        cout << "Name: " << name << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "Email: " << email << "\n";
        cout << "Position Applied For: " << position << "\n";
        cout << "=============================\n";

    }
};


/*
===========================================
💡 What happens when you call clone():
===========================================

Step 1: You call clone() on a Resume pointer:
    Resume* frontend = blockchain->clone();

Step 2: Because clone() is virtual, it calls the derived class's version:
    MyResume::clone()

Step 3: Inside MyResume::clone(), this line is executed:
    return new MyResume(*this);

        → This triggers the copy constructor:
            MyResume(const MyResume& other)

        → A new object is created on the heap using 'new'
        → The data from the current object (*this) is copied into the new one

Step 4: You get a Resume* pointing to the new, cloned MyResume object

        ✅ So yes, clone() → copy constructor is triggered
        ✅ Both objects (original and clone) live at different memory locations
        ✅ You can now safely change fields (like position) without affecting the original

🧪 Proof:
    Printing memory addresses of 'blockchain' and 'frontend' will show they are different.

📌 Summary:
    clone() → calls new MyResume(*this) → triggers copy constructor → returns pointer to new object

*/
