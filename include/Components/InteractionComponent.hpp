#pragma once

#include "IEngineComponent.hpp"
#include "PlayerComponent.hpp"
#include "MobComponent.hpp"
#include "ItemComponent.hpp"
#include "WorldComponent.hpp"


namespace derogue
{

class InteractionComponent : public IEngineComponent
{
private:
    TCODMap* _map;
    Entity* _player;

    void InteractWithWall(int x, int y)
    {
        TCODConsole::root->print(0,60, "walked into a wall at x: %d y: %d.",x,y);
    }

    void InteractWithMob(int x, int y)
    {
        TCODConsole::root->print(0,60, "walked into a mob at x: %d y: %d.",x,y);
    }

public:
    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();
        _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
        auto playerPos = _player->GetPosition();

        switch(key->c){
            case 'W':  case 'w': TryInteract(playerPos.X, playerPos.Y - 1); break; // up
            case 'A':  case 'a': TryInteract(playerPos.X - 1, playerPos.Y); break; // left
            case 'S':  case 's': TryInteract(playerPos.X, playerPos.Y + 1); break; // down
            case 'D':  case 'd': TryInteract(playerPos.X + 1, playerPos.Y); break; // right
        }
    };

    void TryInteract(int x, int y)
    {
        if(_map->isWalkable(x,y))
        {

        }
        else
        {
            auto effectedThing = TCODConsole::root->getChar(x,y);
            switch(effectedThing)
            {
                case ' ': InteractWithWall(x,y);  break;
                default: InteractWithMob(x,y);
            }
        }

    }

};

} //end namespace derogue
