#pragma once

#include "libtcod.hpp"
#include "defines.hpp"
#include "Components/IEngineComponent.hpp"

namespace derogue {
namespace dungeon {

class HallGenerator : public ITCODBspCallback {

private:
    TCODMap *_map;
    int _wallThickness;
    int _minRoomSize;

    void BuildHallways(TCODBsp *node)
    {
        if(!node->isLeaf())
        {
            auto left = node->getLeft();
            auto right = node->getRight();

            auto minSize = (_wallThickness + _minRoomSize);

            bool leftHasRoom  = (left->w > minSize && left->h > minSize );
            bool rightHasRoom = (right->w > minSize && right->h > minSize );

            if(leftHasRoom && rightHasRoom){
                auto startX = left->x + (left->w / 2)   < right->x + (right->w / 2)  ? left->x + (left->w / 2) : right->x + (right->w / 2);
                auto endX =   right->x + (right->w / 2) < left->x + (left->w / 2)    ? left->x + (left->w / 2) : right->x + (right->w / 2);
                auto startY = left->y + (left->h / 2)   < right->y + (right->h / 2)  ? left->y + (left->h / 2) : right->y + (right->h / 2);
                auto endY =   right->y + (right->h / 2) < right->y + (right->h / 2)  ? left->y + (left->h / 2) : right->y + (right->h / 2);

                int x = startX, y = startY;
                TCODLine::init(x,y,endX,endY);
                do {
                    _map->setProperties(x,y,true,true);
                } while (!TCODLine::step(&x,&y));
            }
        }
    }

public :
    bool visitNode(TCODBsp *node, void *userData)
    {
        BuildHallways(node);
        return true;
    }

    HallGenerator(TCODMap* map,int WallThickness = 1, int minRoomSize = 2):
        _map(map),
        _wallThickness(WallThickness),
        _minRoomSize(minRoomSize)
        {};

};

} //end namespace dungeon
} //end namespace derogue


