#pragma once

#include "ItemGenerators/Types.hpp"
#include "Entities/Item.hpp"

namespace derogue {

class WeaponGenerator
{
    private:
        std::map<WeaponType,char> _weaponTypeToSymbol;
    public:
        WeaponGenerator()
        {
            _weaponTypeToSymbol.push_back(WT_STICK,'|');
            _weaponTypeToSymbol.push_back(WT_DAGGER,';');
            _weaponTypeToSymbol.push_back(WT_SWORD,'t');
            _weaponTypeToSymbol.push_back(WT_AXE,'p');
        }

        Weapon* GenerateWeapon()
        {
            auto materialType = rand() % (MT_COUNT);
            auto weaponType = (rand() % (WT_COUNT);

            return new Weapon(weaponType,materialType);
        }
}

} // end namespace derogue
