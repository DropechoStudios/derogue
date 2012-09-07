#pragma once
#ifndef LIGHTINGCOMPONENT_H
#define LIGHTINGCOMPONENT_H

#include "DungeonComponent.hpp"
#include "libtcod.hpp"

namespace derogue {

class LightingComponent : public IEngineComponent {
private:
    TCODMap * _map;

public:
    virtual void Init(Engine * engine)
    {
        _map = engine->GetComponent<WorldComponent>()->GetMap();
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for(int x = 0; x < WINDOW_X; x++){
            for(int y = 0; y < WINDOW_Y; y++){
                bool isWall = _map->isWalkable(x,y);

                TCODColor light = _map->isInFov(x,y)
                    ? (isWall ? lightWall : lightGround)
                    : (isWall ? darkWall : darkGround);

                TCODConsole::root->setCharBackground(x,y,light, TCOD_BKGND_SET );
            }
        }
    };
};

}

#endif
