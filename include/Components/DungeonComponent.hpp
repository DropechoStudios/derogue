#pragma once
#ifndef DUNGEONCOMPONENT_H
#define DUNGEONCOMPONENT_H

#include "DungeonGenerators/BasicRoomGenerator.hpp"
#include "DungeonGenerators/HallGenerator.hpp"
#include "IEngineComponent.hpp"

namespace derogue {

class DungeonComponent : public IEngineComponent
{
private:
    TCODBsp *_dungeon;
    TCODMap *_map;

public:
    DungeonComponent()
    {
        _dungeon = new TCODBsp(0,0,WINDOW_X,WINDOW_Y);
        _dungeon->splitRecursive(NULL,7,3,3,1.5f,1.5f);
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();

        //Clear the map, set everything to filled.
        for(int x = 0; x < WINDOW_X; x++)
        {
            for(int y = 0; y < WINDOW_Y; y++)
            {
                _map->setProperties(x,y,false,false);
            }
        }

        auto roomgenerator = new dungeon::BasicRoomGenerator(_map,1,2);
        auto hallgenerator = new dungeon::HallGenerator(_map,1,2);

        _dungeon->traversePostOrder(roomgenerator,NULL);
        _dungeon->traverseInvertedLevelOrder(hallgenerator,NULL);
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
    };
};

} //end namespace derogue

#endif
