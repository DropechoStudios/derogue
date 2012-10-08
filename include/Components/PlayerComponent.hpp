#pragma once
#ifndef PLAYERCOMPONENT_H
#define PLAYERCOMPONENT_H

#include "Entities/Entity.hpp"
#include "WorldComponent.hpp"
#include "Engine.hpp"

namespace derogue {

class PlayerComponent : public IEngineComponent
{
private:
    Entity* _player;
    TCODMap * _map;

public:
    PlayerComponent()
    {
        _player = new Entity('@');
    }

    virtual Entity* GetPlayer(){
        return _player;
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();

        while(!_map->isWalkable(_player->GetPosition().X,_player->GetPosition().Y))
        {
            _player->SetPosition(rand() % DUNGEON_X, rand() % DUNGEON_Y);
        }
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
        _player->DrawToConsole();
    };
};

} //end namespace derogue
#endif
