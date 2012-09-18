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
                _paths[pathId] = new TCODPath(_map,0.0f);
            }

            return _paths[pathId];
        }

        bool ComputeAndWalkPath(int pathId, int* x, int* y, int dx, int dy, int stopping = 1, bool mustBeVisible = false, int sightRadius = 1)
        {
            auto isPathable = ComputePath(pathId,*x,*y,dx,dy);
            auto inRange = GetPath(pathId)->size() <= stopping;
            auto isVisible = true;

            if(isPathable)
            {
                if(mustBeVisible)
                {
                    _map->computeFov(*x,*y,sightRadius);
                    isVisible = _map->isInFov(dx,dy);
                }

                if(!inRange || !isVisible)
                {
                    GetPath(pathId)->walk(x,y,false);
                }
            }


            return isPathable;
        }

        void DrawPath(int pathId, TCODColor color =  TCODColor::copper)
        {
            auto path = _paths[pathId];
            int pathx, pathy;
            for(int i = 0; i < path->size(); i++)
            {
                path->get(i,&pathx,&pathy);
                TCODConsole::root->setCharBackground(pathx,pathy,color);
            }
        }
};

}

#endif
