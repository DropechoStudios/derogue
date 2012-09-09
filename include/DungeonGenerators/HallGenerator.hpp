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

    void BuildHallways(TCODBsp *node)
    {

    }

public :
    bool visitNode(TCODBsp *node, void *userData)
    {
        BuildHallways(node);

        return true;
    }

    BasicRoomGenerator(TCODMap* map):
        _map(map)
        {};

};

} //end namespace dungeon
} //end namespace derogue


