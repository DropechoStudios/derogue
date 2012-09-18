#pragma once

#include "libtcod.hpp"
#include "stlextensions.hpp"

namespace derogue {

class MobComponent : public IEngineComponent{
    private:
        TCODMap * _map;
        IEntity * _player;
        PathfindingComponent * _pathFinding;

        std::vector<IEntity*> _mobs;

        float _timeSinceLastMobUpdate;

        void PathToOtherMob(IEntity* mob, IEntity* target)
        {
            auto mobPos = mob->GetPosition();
            auto targetPos = target->GetPosition();

            _pathFinding->ComputeAndWalkPath(5,&mobPos.X,&mobPos.Y,targetPos.X,targetPos.Y);
            mob->SetPosition(mobPos);
        }

    public:
        MobComponent()
        {
            _timeSinceLastMobUpdate = 0;
        }

        virtual void Init(Engine * engine)
        {
            _map = engine->GetComponent<WorldComponent>()->GetMap();
            _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
            _pathFinding = engine->GetComponent<PathfindingComponent>();


        };

        virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
        {
            _timeSinceLastMobUpdate += TCODSystem::getLastFrameLength();

            if(_timeSinceLastMobUpdate > 1) // if > 1 second has elapsed, update path
            {
                for_each(_mobs,[_player,this](IEntity* mob){PathToOtherMob(mob,_player);});
                _timeSinceLastMobUpdate = 0;
            }

            if(_pathFinding->GetPath(5)) //Draw / walk path.
            {
                _pathFinding->DrawPath(5,TCODColor::lime);
            }
        };
};

}
