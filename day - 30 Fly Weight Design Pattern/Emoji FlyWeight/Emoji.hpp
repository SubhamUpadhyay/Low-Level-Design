#pragma once
#include <string>
#include <iostream>
using namespace std;

// Flyweight: shared emoji object
class Emoji {
private:
    string image;  // Intrinsic (shared): graphic/icon

public:
    Emoji(const string& img) : image(img) {}

    void render(const string& username, const string& timestamp, int positionY) {
        cout << "[" << timestamp << "] " << username
             << " sent emoji '" << image << "' at Y=" << positionY << endl;
    }
};
