#pragma once

namespace derogue {
namespace items {

    enum ItemType
    {
        IT_WEAPON   = 0,
        IT_ARMOR    = 1,
        IT_POTION   = 2
    };

    enum MaterialType
    {
        MT_WOOD = 0,
        MT_COPPER = 1,
        MT_IRON = 2,
        MT_STEEL = 3,
        MT_MITHRIL = 4,
        MT_COUNT //convenice for rand mod against
    };

    enum WeaponType
    {
        WT_STICK = 0,
        WT_DAGGER = 1,
        WT_SWORD = 2,
        WT_AXE = 3,
        WT_COUNT //convenice for rand mod against
    };

    std::map<WeaponType,char> WeaponTypesToSymbols = {
        {WT_STICK,  '|'},
        {WT_DAGGER, ';'},
        {WT_SWORD,  't'},
        {WT_AXE,    'p'}
    };
}//end namespace items
}//end namespace derogue
