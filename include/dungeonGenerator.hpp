#pragma once
#include "libtcod.hpp"
#include "libtcod.hpp"
#include "defines.hpp"
#include "Components/IEngineComponent.hpp"

namespace derogue {
namespace dungeon {

class DungeonGenerator : public ITCODBspCallback {

private:
    TCODMap *_map;

    bool BuildWalls(TCODBsp *node);
    bool BuildDoors(TCODBsp *node);

public :
    bool visitNode(TCODBsp *node, void *userData);

    DungeonGenerator(TCODMap* map){
        _map = map;
    }
};
} //end namespace dungeon
} //end namespace derogue

