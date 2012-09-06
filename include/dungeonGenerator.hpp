#pragma once
#include "libtcod.hpp"
#include "libtcod.hpp"
#include "defines.hpp"
#include "IEngineComponent.hpp"

namespace derogue {
namespace dungeon {

class DungeonGenerator : public ITCODBspCallback {

private:
    TCODMap *_map;

    bool BuildWalls(TCODBsp *node,int x,int y);
    void BuildDoors(TCODBsp *node,int x,int y);

public :
    bool visitNode(TCODBsp *node, void *userData);

    DungeonGenerator(TCODMap* map){
        _map = map;
    }
};
} //end namespace dungeon
} //end namespace derogue

