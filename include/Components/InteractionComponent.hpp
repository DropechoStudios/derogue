#pragma once
#include "PlayerComponent.hpp"
#include "MobComponent.hpp"
#include "ItemComponent.hpp"
#include "WorldComponent.hpp"
#include "LogComponent.hpp"

namespace derogue
{

class InteractionComponent : public IEngineComponent
{
private:
    TCODMap* _map;
    Entity* _player;
    CreatureList _mobs;
    LogComponent* _logger;

    void InteractWithWall(int x, int y)
    {
        _logger
            ->AppendLogPart("walked into a wall at x: ")->AppendLogPart(x)
            ->AppendLogPart(" y: ")->AppendLogPart(y)
            ->CloseLogPart();
    }

    void InteractWithMob(int x, int y)
    {
        auto mob = filter(_mobs,[x,y](Entity* mob){
               auto pos = mob->GetPosition();
               return pos.X == x && pos.Y == y;
        });

        if(mob)
        {
            _logger
                ->AppendLogPart("walked into mob named ")->AppendLogPart(mob->GetSymbol().Char)
                ->CloseLogPart();

            _logger
                ->AppendLogPart("walked into a mob at x: ")->AppendLogPart(x)
                ->AppendLogPart(" y: ")->AppendLogPart(y)
                ->CloseLogPart();
        }

    }

public:
    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();
        _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
        _mobs = engine->GetComponent<MobComponent>()->GetMobs();
        _logger = engine->GetComponent<LogComponent>();
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
