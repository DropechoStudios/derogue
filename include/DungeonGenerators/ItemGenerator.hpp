#pragma once

#include "libtcod.hpp"
#include "defines.hpp"
#include "Entities/IGameEntity.hpp"
#include "ItemGenerators/Types.hpp"

namespace derogue {
namespace dungeon {

class ItemGenerator: public ITCODBspCallback {

private:
    TCODMap *_map;
    int _wallThickness;
    int _minRoomSize;

public :
    bool visitNode(TCODBsp *node, void *userData)
    {
        std::vector<IEntity*>* _items = (std::vector<IEntity*>*)userData;
        if(node->isLeaf())
        {
            auto itemX = (node->x + _wallThickness + (rand() % (node->w - _wallThickness)));
            auto itemY = (node->y + _wallThickness + (rand() % (node->h - _wallThickness)));

            auto hasItem = !(rand()%4); //25% chance of item in room.
            if(hasItem)
            {
                auto type = (items::WeaponType)(rand()%items::WT_COUNT);
                _items->push_back(new IEntity(itemX,itemY,items::WeaponTypesToSymbols[type]));
            }

        }
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



