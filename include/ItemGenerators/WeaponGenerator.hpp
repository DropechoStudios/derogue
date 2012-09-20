#pragma once

#include "Entities/Items/Types.hpp"
#include "Entities/Items/Weapon.hpp"

namespace derogue {
namespace items {

class WeaponGenerator
{
    public:
        static Weapon* GenerateWeapon()
        {
            auto materialType = (MaterialType)(rand() % (MT_COUNT));
            auto weaponType = (WeaponType)(rand() % (WT_COUNT));

            return new Weapon(weaponType,materialType);
        }
};

} // end namespace items
} // end namespace derogue
