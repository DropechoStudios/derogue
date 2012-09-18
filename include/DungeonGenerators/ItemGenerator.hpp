#pragma once

#include "libtcod.hpp"
#include "defines.hpp"
#include "ItemGenerators/Types.hpp"

namespace derogue {
namespace dungeon {

class ItemGenerator: public ITCODBspCallback {

private:
    TCODMap *_map;
    int _wallThickness;
    int _minRoomSize;

    void PlaceItems(TCODBsp *node)
    {
        if(node->isLeaf())
        {
            auto itemX = node->x + (rand() % node->w);
            auto itemY = node->y + (rand() % node->h);

            TCODConsole::root->setChar(itemX,itemY,'t');
        }
    }

public :
    bool visitNode(TCODBsp *node, void *userData)
    {
        PlaceItems(node);
        return true;
    }

    ItemGenerator(TCODMap* map,int WallThickness = 1, int minRoomSize = 2):
        _map(map),
        _wallThickness(WallThickness),
        _minRoomSize(minRoomSize)
        {};

};

} //end namespace dungeon
} //end namespace derogue



