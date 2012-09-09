#include "DungeonGenerators/BasicRoomGenerator.hpp"

using namespace derogue;
using namespace dungeon;

void BasicRoomGenerator::BuildWalls(TCODBsp *node){
    auto minX = node->x + _wallThickness;
    auto minY = node->y + _wallThickness;
    auto maxX = node->x + node->w - _wallThickness;
    auto maxY = node->y + node->h - _wallThickness;

    bool hasRoom = node->w > _wallThickness + _minRoomSize && node->h > _wallThickness + _minRoomSize;

    for(int x = node->x; x < (node->x + node->w); x++){
        for(int y = node->y; y < (node->y + node->h); y++){
            if(hasRoom){
                if(x < minX || x > maxX || x == WINDOW_X -1 ||
                   y < minY || y > maxY || y == WINDOW_Y -1 )
                {
                    _map->setProperties(x,y,false,false);
                }
            }
            else{
                _map->setProperties(x,y,false,false);
            }
        }
    }
}

bool BasicRoomGenerator::visitNode(TCODBsp *node, void *userData)
{
    if(node->isLeaf()){
        for(int x = node->x; x < (node->x + node->w); x++){
            for(int y = node->y; y < (node->y + node->h); y++){
                _map->setProperties(x,y,true,true);
            }
        }
        BuildWalls(node);
    }
    return true;
}
