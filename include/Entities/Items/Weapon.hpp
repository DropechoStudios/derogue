#pragma once
#include "Entities/Items/Item.hpp"

namespace derogue {
namespace items {

enum WeaponType
{
    WT_STICK = 0,
    WT_DAGGER = 1,
    WT_SWORD = 2,
    WT_AXE = 3,
    WT_COUNT //convenice for rand mod against
};

static std::map<WeaponType,char> WeaponTypesToSymbols = {
    {WT_STICK,  '|'},
    {WT_DAGGER, ';'},
    {WT_SWORD,  't'},
    {WT_AXE,    'p'}
};

class Weapon : public Item
{
    private:
        WeaponType _weaponType;

    public:
        Weapon(WeaponType weaponType, MaterialType materialType)
        : Item(materialType,WeaponTypesToSymbols[weaponType]), _weaponType(weaponType){}

        int GetDamage()
        {
            return 1 + _weaponType + GetAmount();
        }
};

} //end namespace items
} //end namespace derogue
