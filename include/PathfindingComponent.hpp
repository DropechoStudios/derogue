#pragma once
#ifndef PATHFINDINGCOMPONENT_H
#define PATHFINDINGCOMPONENT_H

#include "libtcod.hpp"
#include <map>

namespace derogue {

class PathfindingComponent : public IEngineComponent{
    private:
        std::map<int,TCODPath *> _paths;

        TCODMap* _map;
    public:
        virtual void Init(Engine * engine)
        {
            _map = engine->GetComponent<WorldComponent>()->GetMap();
        };

        virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse){};

        bool ComputePath(int pathId, int ox, int oy, int dx, int dy)
        {
            return GetPath(pathId)->compute(ox,oy,dx,dy);
        }

        TCODPath* GetPath(int pathId)
        {
            if(_paths.count(pathId) == 0)
            {
                _paths[pathId] = new TCODPath(_map);
            }
            return _paths[pathId];
        }

        void DrawPath(int pathId)
        {
            auto path = _paths[pathId];
            int pathx, pathy;
            for(int i = 0; i < path->size(); i++)
            {
                path->get(i,&pathx,&pathy);
                TCODConsole::root->setCharBackground(pathx,pathy,TCODColor::copper);
            }
        }
};

}

#endif
