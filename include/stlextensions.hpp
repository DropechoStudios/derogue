#pragma onc
#include <algorithm>
#include <vector>

namespace derogue
{
    template<typename T, typename Function>
    Function for_each(std::vector<T> vec, Function f)
    {
        std::for_each(begin(vec),end(vec),f);
    }
}
