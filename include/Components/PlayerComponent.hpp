#pragma once
#ifndef PLAYERCOMPONENT_H
#define PLAYERCOMPONENT_H

#include "WorldComponent.hpp"
#include "Engine.hpp"

namespace derogue {

class PlayerComponent : public IEngineComponent
{
private:
    Player* _player;
    TCODMap * _map;

public:
    PlayerComponent()
    {
        _player = new Player();
        _player->X = WINDOW_X/2;
        _player->Y = WINDOW_X/2;
    }

    virtual Player* GetPlayer(){
        return _player;
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {

        switch(key->c){
            case 'w': _map->isWalkable(_player->X, _player->Y - 1) ? _player->Y-- : 0; break; // up
            case 'a': _map->isWalkable(_player->X - 1, _player->Y) ? _player->X-- : 0; break; // left
            case 's': _map->isWalkable(_player->X, _player->Y + 1) ? _player->Y++ : 0; break; // down
            case 'd': _map->isWalkable(_player->X + 1, _player->Y) ? _player->X++ : 0; break; // right
        }

        _map->computeFov(_player->X,_player->Y, 10);
        TCODConsole::root->putChar(_player->X,_player->Y,'@');
    };
};

} //end namespace derogue
#endif
