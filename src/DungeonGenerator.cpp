#include "dungeonGenerator.hpp"

using namespace derogue;
using namespace dungeon;

bool DungeonGenerator::BuildWalls(TCODBsp *node,int x,int y){
    if(x == node->x || x == (node->x + node->w) || x == WINDOW_X -1 ||
       y == node->y || y == (node->y + node->h) || y == WINDOW_Y -1 )
    {
        _map->setProperties(x,y,false,false);
        return true;
    }
    return false;
}

void DungeonGenerator::BuildDoors(TCODBsp *node,int x,int y){
    if(x == (node->x + node->w / 2) && y == node->y ||
       y == (node->y + node->h / 2) && x == node->x )
    {
        _map->setProperties(x,y,true,true);
    }
}

bool DungeonGenerator::visitNode(TCODBsp *node, void *userData) {
    if(node->isLeaf()){
        for(int x = node->x; x < (node->x + node->w); x++){
            for(int y = node->y; y < (node->y + node->h); y++){
                if(BuildWalls(node,x,y))
                {
                    BuildDoors(node,x,y);
                }
                else
                {
                    _map->setProperties(x,y,true,true);
                }
            }
        }
    }
    return true;
}
