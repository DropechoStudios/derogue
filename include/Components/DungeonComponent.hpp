#pragma once
#ifndef DUNGEONCOMPONENT_H
#define DUNGEONCOMPONENT_H

#include "DungeonGenerators/BasicRoomGenerator.hpp"
#include "IEngineComponent.hpp"

namespace derogue {

class DungeonComponent : public IEngineComponent
{
private:
    TCODBsp *_dungeon;
    TCODMap *_map;

    dungeon::BasicRoomGenerator* _generator;
public:
    DungeonComponent()
    {
        _dungeon = new TCODBsp(0,0,WINDOW_X,WINDOW_Y);
        _dungeon->splitRecursive(NULL,7,3,3,1.5f,1.5f);
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();

        _generator = new dungeon::BasicRoomGenerator(_map,1,4);
        _dungeon->traversePostOrder(_generator,NULL);
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
    };
};

} //end namespace derogue

#endif
