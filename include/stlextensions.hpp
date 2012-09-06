#pragma once
#ifndef EXTENSIONS_H
#define EXTENSIONS_H
#include <algorithm>
#include <vector>

namespace derogue
{
    template<typename T, typename Function>
    Function for_each(std::vector<T> vec, Function eachFunc)
    {
        return std::for_each(begin(vec),end(vec),eachFunc);
    }

    template<typename T, typename Function>
    T filter(std::vector<T> vec, Function filterFunc)
    {
        for(auto it = vec.begin(); it != vec.end(); it++)
        {
            if(filterFunc(*it))
            {
                return *it;
            }
        }
        return NULL;
    }
}
#endif
