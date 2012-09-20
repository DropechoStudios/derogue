#pragma once

#include "libtcod.hpp"
#include "defines.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Items/Types.hpp"
#include "Entities/Items/Weapon.hpp"
#include "ItemGenerators/WeaponGenerator.hpp"

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
        std::vector<Entity*>* _items = (std::vector<Entity*>*)userData;
        if(node->isLeaf())
        {
            auto itemX = (node->x + _wallThickness + (rand() % (node->w - _wallThickness)));
            auto itemY = (node->y + _wallThickness + (rand() % (node->h - _wallThickness)));

            auto hasItem = !(rand()%4); //25% chance of item in room.
            if(hasItem)
            {
                auto weapon = items::WeaponGenerator::GenerateWeapon();
                _items->push_back(new Entity(itemX,itemY,weapon->GetSymbol().Char));
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



