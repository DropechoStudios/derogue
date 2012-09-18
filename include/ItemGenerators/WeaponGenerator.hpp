#pragma once

#include "ItemGenerators/Types.hpp"
#include "Entities/Item.hpp"

namespace derogue {

class WeaponGenerator
{
    public:
        Weapon* GenerateWeapon()
        {
            auto materialType = rand() % (MT_COUNT);
            auto weaponType = (rand() % (WT_COUNT);

            return new Weapon(weaponType,materialType);
        }
}

} // end namespace derogue
