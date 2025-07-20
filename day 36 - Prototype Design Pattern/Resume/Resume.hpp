#pragma once
#include <bits/stdc++.h>
using namespace std;

class Resume {
public:
    virtual ~Resume() {}
    virtual Resume* clone() const = 0;
    virtual void setPosition(const std::string& position) = 0;
    virtual void print() const = 0;
};
