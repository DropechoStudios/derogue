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

    void BuildRoom(TCODBsp *node){
        auto minX = node->x + _wallThickness - 1;
        auto minY = node->y + _wallThickness - 1;
        auto maxX = node->x + node->w;
        auto maxY = node->y + node->h;

        auto minSize = (_wallThickness + _minRoomSize);
        bool hasRoom = node->w > minSize && node->h > minSize;

        for(int x = node->x; x <= (node->x + node->w); x++){
            for(int y = node->y; y <= (node->y + node->h); y++){
                if(hasRoom){
                    if(((x > minX && x < maxX && x != DUNGEON_X -1) || (x <= _wallThickness && x >= 1)) &&
                       ((y > minY && y < maxY && y != DUNGEON_Y -1) || (y <= _wallThickness && y >= 1)))
                    {
                        _map->setProperties(x,y,true,true);
                    }
                }
                else{
                    _map->setProperties(x,y,false,false);
                }
            }
        }
    };

public :
    bool visitNode(TCODBsp *node, void *userData)
    {
        if(node->isLeaf()){
            BuildRoom(node);
        }
        return true;
    }

    BasicRoomGenerator(TCODMap* map, int WallThickness = 1, int minRoomSize = 2):
        _map(map),
        _wallThickness(WallThickness),
        _minRoomSize(minRoomSize)
        {};

};

} //end namespace dungeon
} //end namespace derogue

