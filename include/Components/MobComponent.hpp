#pragma once

#include "libtcod.hpp"
#include "PlayerComponent.hpp"
#include "PathfindingComponent.hpp"
#include "stlextensions.hpp"

namespace derogue {

class MobComponent : public IEngineComponent{
    private:
        TCODMap * _map;
        Entity * _player;
        PathfindingComponent * _pathFinding;

        CreatureList _mobs;

        float _timeSinceLastMobUpdate;

        void PathToOtherMob(Entity* mob, Entity* target)
        {
            auto mobPos = mob->GetPosition();
            auto targetPos = target->GetPosition();

            Position2d prevPos = Position2d(mobPos.X,mobPos.Y);

            _pathFinding->ComputeAndWalkPath(5,&mobPos.X,&mobPos.Y,targetPos.X,targetPos.Y);

            if(prevPos.X != mobPos.X || prevPos.Y != mobPos.Y)
            {
                _map->setProperties(prevPos.X,prevPos.Y,true,true);
                _map->setProperties(mobPos.X,mobPos.Y,false,false);
            }

            mob->SetPosition(mobPos);
        }

    public:
        MobComponent()
        {
            _timeSinceLastMobUpdate = 0;
        }

        CreatureList& GetMobs()
        {
            return _mobs;
        }

        virtual void Init(Engine * engine)
        {
            _map = engine->GetComponent<WorldComponent>()->GetMap();
            _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
            _pathFinding = engine->GetComponent<PathfindingComponent>();

            _mobs.push_back(new creatures::Creature(creatures::MT_GOBLIN));
        };

        virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
        {
            _timeSinceLastMobUpdate += TCODSystem::getLastFrameLength();

            if(_timeSinceLastMobUpdate > 1) // if > 1 second has elapsed, update path
            {
                for_each(_mobs,[_player,this](Entity* mob){PathToOtherMob(mob,_player); });
                _timeSinceLastMobUpdate = 0;
            }

            for_each(_mobs,[](Entity* mob){ mob->DrawToConsole(); });
        };
};

}
