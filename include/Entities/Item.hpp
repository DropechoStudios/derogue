#pragma once

namespace derogue {

class Item
{
    private:
        ItemType _itemType;
        MaterialType _materialType;

    protected:
        Item(ItemType itemType, MaterialType materialType):
        _itemType(itemType),_materialType(MaterialType){}

        int GetAmount()
        {
            return _materialType;
        }
};

class Weapon : public Item
{
    private:
        WeaponType _weaponType;
    public:
        Weapon(WeaponType weaponType, MaterialType materialType)
        : Item(IT_WEAPON,materialType), _weaponType(weaponType){}

        int GetDamage()
        {
            return 1 + _weaponType + GetAmount();
        }
};

} //end namespace derogue
