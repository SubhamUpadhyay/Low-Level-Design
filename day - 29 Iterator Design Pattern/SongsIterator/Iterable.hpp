#pragma once
#include "Iterator.hpp"

class Iterable {
public:
    virtual Iterator* getIterator() = 0;
    virtual ~Iterable() {}
};
