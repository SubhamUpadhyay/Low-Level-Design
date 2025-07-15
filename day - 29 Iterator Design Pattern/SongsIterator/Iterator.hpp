#pragma once
#include "Song.hpp"

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual Song next() = 0;
    virtual ~Iterator() {}
};
