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
        auto minX = node->x + _wallThickness;
        auto minY = node->y + _wallThickness;
        auto maxX = node->x + node->w - _wallThickness;
        auto maxY = node->y + node->h - _wallThickness;

        bool hasRoom = node->w > _wallThickness + _minRoomSize && node->h > _wallThickness + _minRoomSize;

        for(int x = node->x; x < (node->x + node->w); x++){
            for(int y = node->y; y < (node->y + node->h); y++){
                if(hasRoom){
                    if((x > minX && x < maxX && x != WINDOW_X -1) &&
                       (y > minY && y < maxY && y != WINDOW_Y -1))
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

