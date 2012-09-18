#pragma once
#ifndef ITEMCOMPONENT_H
#define ITEMCOMPONENT_H

#include "libtcod.hpp"
#include "Components/DungeonComponent.hpp"
#include "DungeonGenerators/ItemGenerator.hpp"

namespace derogue {

class Engine; //Forward declaration.

class ItemComponent: public IEngineComponent{
public:
    virtual void Init(Engine * engine)
    {
        auto dungeon = engine->GetComponent<DungeonComponent>()->GetDungeon();
        dungeon->traverseInvertedLevelOrder(new dungeon::ItemGenerator(NULL,0,2), NULL);
    };
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        TCODConsole::root->setChar(50,50,'t');
    };
};

} //end namespace derogue

#endif
