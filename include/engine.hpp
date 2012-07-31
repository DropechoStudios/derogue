#pragma once
#include "libtcod.hpp"

namespace derogue {

const int WINDOW_X = 80;
const int WINDOW_Y = 60;

class Engine{
private:
    TCODMap* _map;
    TCODBsp* _bsp;

    char _test[WINDOW_X][WINDOW_Y];

    void BuildBSP();
public:
    void Init();
    void Run();
};




} //end namespace derogue
