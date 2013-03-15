#pragma once
#ifndef WORLDCOMPONENT_H
#define WORLDCOMPONENT_H

#include "IEngineComponent.hpp"
#include "defines.hpp"

namespace derogue
{

class WorldComponent : public IEngineComponent
{
    private:
        TCODMap * _map;

    public:
        WorldComponent()
        {
            _map = new TCODMap(80,60);
        }

        virtual void Init(Engine* engine){};
        virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse){};

        TCODMap* GetMap(){
            return _map;
        }
};

}//end namespace derogue

#endif
