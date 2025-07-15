#pragma once
#include "Dress.hpp"   
#include <map>
#include <string>


class DressFactory{
    private:
        map<string,Dress*>pool;
    public:
        Dress *getDress(const string & style , const string &color)
            {
                string key = style+" _ "+color;
                if(pool.find(key)==pool.end())
                    {
                        pool[key] = new Dress(style,color);
                    }
                return pool[key];
            }

};