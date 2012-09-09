#pragma once

#include "libtcod.hpp"
#include "defines.hpp"
#include "Components/IEngineComponent.hpp"

namespace derogue {
namespace dungeon {

class BasicRoomGenerator : public ITCODBspCallback {

private:
    TCODMap *_map;
    int _wallThickness;
    int _minRoomSize;

    void BuildWalls(TCODBsp *node);

public :
    bool visitNode(TCODBsp *node, void *userData);

    BasicRoomGenerator(TCODMap* map, int WallThickness = 1, int minRoomSize = 2):
        _map(map),
        _wallThickness(WallThickness),
        _minRoomSize(minRoomSize)
        {};

};

} //end namespace dungeon
} //end namespace derogue

