#pragma once
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
        dungeon->traverseInvertedLevelOrder(new dungeon::ItemGenerator(NULL,2,2), &_items);
    };
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for_each(_items,[](Entity* entity){ entity->DrawToConsole(); });
    };

    virtual Entity* GetItemAt(int x, int y)
    {
        return filter(_items,[x,y](Entity* item){
           auto pos = item->GetPosition();
           return pos.X == x && pos.Y == y;
        });
    }
};

} //end namespace derogue
