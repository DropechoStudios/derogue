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
        _mobs = engine->GetComponent<MobComponent>();

        while(!_map->isWalkable(_player->GetPosition().X,_player->GetPosition().Y))
        {
            _player->SetPosition(rand() % DUNGEON_X, rand() % DUNGEON_Y);
        }
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
        auto playerPos = _player->GetPosition();

        switch(key->c){
            case 'W':  case 'w': TryWalk(playerPos.X, playerPos.Y - 1); break; // up
            case 'A':  case 'a': TryWalk(playerPos.X - 1, playerPos.Y); break; // left
            case 'S':  case 's': TryWalk(playerPos.X, playerPos.Y + 1); break; // down
            case 'D':  case 'd': TryWalk(playerPos.X + 1, playerPos.Y); break; // right
        }

        _player->DrawToConsole();
    };

    void TryWalk(int x, int y)
    {
        if(_map->isWalkable(x,y))
        {
            _player->SetPosition(Position2d(x,y));
        }
        else
        {
           TryAffect(x,y);
        }
    }

    void TryAffect(int targetX, int targetY)
    {
        auto effectedThing = TCODConsole::root->getChar(targetX,targetY);
        switch(effectedThing)
        {
            case ' ': TCODConsole::root->print(0,60, "walked into a wall."); break;
            default: TCODConsole::root->print(0,60, "walked into something.");
        }

    }
};

} //end namespace derogue
#endif
