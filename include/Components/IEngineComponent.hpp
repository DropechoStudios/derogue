#pragma once
#include "libtcod.hpp"

namespace derogue {

class Engine; //Forward declaration.

class IEngineComponent{
public:
    virtual void Init(Engine * engine) = 0;
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) = 0;
};

}
