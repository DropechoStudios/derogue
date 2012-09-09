#pragma once

#include "libtcod.hpp"

namespace derogue {

class MobComponent : public IEngineComponent{
    private:
        TCODMap * _map;
        Player * _player;
        PathfindingComponent * _pathFinding;

        int _testX;
        int _testY;

        float _timeSinceLastMobUpdate;
    public:
        MobComponent()
        {
            _timeSinceLastMobUpdate = 0;
            _testX = 0;
            _testY = 0;
        }

        virtual void Init(Engine * engine)
        {
            _map = engine->GetComponent<WorldComponent>()->GetMap();
            _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
            _pathFinding = engine->GetComponent<PathfindingComponent>();

            while(!_map->isWalkable(_testX,_testY))
            {
                _testX = rand() % WINDOW_X;
                _testY = rand() % WINDOW_Y;
            }
        };

        virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
        {
            _timeSinceLastMobUpdate += TCODSystem::getLastFrameLength();

            if(_timeSinceLastMobUpdate > 1) // if > 1 second has elapsed, update path
            {
                _pathFinding->ComputeAndWalkPath(5,&_testX,&_testY,_player->X,_player->Y);
                _timeSinceLastMobUpdate = 0;
            }


            if(_pathFinding->GetPath(5)) //Draw / walk path.
            {
                TCODConsole::root->putChar(_testX,_testY,'D');
                _pathFinding->DrawPath(5,TCODColor::lime);
            }

        };
};

}
