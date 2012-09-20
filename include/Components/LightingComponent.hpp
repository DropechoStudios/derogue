#pragma once
#ifndef LIGHTINGCOMPONENT_H
#define LIGHTINGCOMPONENT_H

#include "DungeonComponent.hpp"
#include "libtcod.hpp"

namespace derogue {

class LightingComponent : public IEngineComponent {
private:
    TCODMap * _map;
    Entity* _player;
public:
    virtual void Init(Engine * engine)
    {
        _map = engine->GetComponent<WorldComponent>()->GetMap();
        _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        _map->computeFov(_player->GetPosition().X,_player->GetPosition().Y, LightDistance);
        for(int x = 0; x < WINDOW_X; x++){
            for(int y = 0; y < WINDOW_Y; y++){
                bool isWall = !_map->isWalkable(x,y);

                TCODColor light = _map->isInFov(x,y)
                    ? (isWall ? lightWall : lightGround )
                    : (isWall ? darkWall  : darkGround);

                TCODConsole::root->setCharBackground(x, y, light, TCOD_BKGND_SET );
                auto currentColor = TCODConsole::root->getCharBackground(x,y);

                if(currentColor == lightGround || currentColor == lightWall ||
                   currentColor == darkGround || currentColor == darkWall)
                {
                    if(!_map->isInFov(x,y))
                    {
                        TCODConsole::root->setCharForeground(x,y,darkGround);
                    }
                }
            }
        }
    };
};

}

#endif
