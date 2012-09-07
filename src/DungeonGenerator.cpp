#include "dungeonGenerator.hpp"

using namespace derogue;
using namespace dungeon;

bool DungeonGenerator::BuildWalls(TCODBsp *node){
    for(int x = node->x; x < (node->x + node->w); x++){
        for(int y = node->y; y < (node->y + node->h); y++){
           if(x == node->x || x == (node->x + node->w) || x == WINDOW_X -1 ||
              y == node->y || y == (node->y + node->h) || y == WINDOW_Y -1 )
            {
                _map->setProperties(x,y,false,false);
            }
        }
    }
}

bool DungeonGenerator::BuildDoors(TCODBsp *node)
{
    _map->setProperties((node->x + (node->w /2)),node->y,true,true);
}

bool DungeonGenerator::visitNode(TCODBsp *node, void *userData)
{
    if(node->isLeaf()){
        for(int x = node->x; x < (node->x + node->w); x++){
            for(int y = node->y; y < (node->y + node->h); y++){
                _map->setProperties(x,y,true,true);
            }
        }
        BuildWalls(node);
        BuildDoors(node);
    }
    return true;
}
