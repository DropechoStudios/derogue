#pragma once
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
        _dungeon = new TCODBsp(0,0,DUNGEON_X,DUNGEON_Y);
        _dungeon->splitRecursive(NULL,6,6,6,1.25f,1.25f);
    }

    virtual void Init(Engine* engine) {
        _map = engine->GetComponent<WorldComponent>()->GetMap();

        //Clear the map, set everything to filled.
        for(int x = 0; x < DUNGEON_X; x++)
        {
            for(int y = 0; y < DUNGEON_Y; y++)
            {
                _map->setProperties(x,y,false,false);
            }
        }

        auto wallthickness = 2;
        auto minimumRoomSize = 2;

        _dungeon->traversePostOrder(new dungeon::BasicRoomGenerator(_map,wallthickness,minimumRoomSize), NULL);
        _dungeon->traverseInvertedLevelOrder(new dungeon::HallGenerator(_map,wallthickness,minimumRoomSize), NULL);
    };

    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
    };

    virtual TCODBsp* GetDungeon()
    {
        return _dungeon;
    }
};

} //end namespace derogue
