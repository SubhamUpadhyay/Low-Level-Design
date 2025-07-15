#pragma once
#include <string>
#include <iostream>
using namespace std;

class Song {
public:
    string title;
    string artist;

    Song(string t = "", string a = "") : title(t), artist(a) {}

    void display() const {
        cout << "" << title << " by " << artist << endl;
    }

    bool operator<(const Song& other) const {
        return title < other.title;
    }
};
