#pragma once
#ifndef PLAYERCOMPONENT_H
#define PLAYERCOMPONENT_H

#include "Entities/IGameEntity.hpp"
#include "WorldComponent.hpp"
#include "Engine.hpp"

namespace derogue {

class PlayerComponent : public IEngineComponent
{
private:
    IEntity* _player;
    TCODMap * _map;

public:
    PlayerComponent()
    {
        _player = new IEntity('@');
    }

    virtual IEntity* GetPlayer(){
        return _player;
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();

        while(!_map->isWalkable(_player->GetPosition().X,_player->GetPosition().Y))
        {
            _player->SetPosition(rand() % WINDOW_X, rand() % WINDOW_Y);
        }
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
        auto playerPos = _player->GetPosition();

        switch(key->c){
            case 'w': _map->isWalkable(playerPos.X, playerPos.Y - 1) ? playerPos.Y-- : 0; break; // up
            case 'a': _map->isWalkable(playerPos.X - 1, playerPos.Y) ? playerPos.X-- : 0; break; // left
            case 's': _map->isWalkable(playerPos.X, playerPos.Y + 1) ? playerPos.Y++ : 0; break; // down
            case 'd': _map->isWalkable(playerPos.X + 1, playerPos.Y) ? playerPos.X++ : 0; break; // right
        }

        _player->SetPosition(playerPos);
        _player->DrawToConsole();
    };
};

} //end namespace derogue
#endif
