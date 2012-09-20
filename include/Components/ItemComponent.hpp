#pragma once
#ifndef ITEMCOMPONENT_H
#define ITEMCOMPONENT_H

#include "libtcod.hpp"
#include "Components/DungeonComponent.hpp"
#include "DungeonGenerators/ItemGenerator.hpp"

namespace derogue {

class Engine; //Forward declaration.

class ItemComponent: public IEngineComponent{
    std::vector<Entity*> _items;
public:
    virtual void Init(Engine * engine)
    {
        auto dungeon = engine->GetComponent<DungeonComponent>()->GetDungeon();
        dungeon->traverseInvertedLevelOrder(new dungeon::ItemGenerator(NULL,1,2), &_items);
    };
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for_each(_items,[](Entity* entity){ entity->DrawToConsole(); });
    };
};

} //end namespace derogue

#endif
