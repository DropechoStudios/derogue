#pragma once

#include "Types.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Items/Weapon.hpp"
#include "Entities/Items/Armor.hpp"
#include <list>

namespace derogue{
namespace creatures {

class Inventory
{
private:
    std::list<items::Weapon* > _weapons;
    std::list<items::Armor* > _armors;

    items::Weapon* _equippedWeapon;
    items::Armor* _equippedArmor;

public:
    void EquipWeapon(items::Weapon* weapon)
    {
        _equippedWeapon = weapon;
    }
    void EquipArmor(items::Armor* armor)
    {
        _equippedArmor = armor;
    }

    void PickUpItem(items::Item *item)
    {

    }
};

class Creature : public Entity
{
private:
    Inventory _inventory;
public:
    Creature(int x, int y, char symbol) : Entity(x,y,symbol){}
};

class Monster: public Creature
{
private:
    MonsterType _type;
public:
    Monster(MonsterType type) : Creature(1,1,MonsterTypesToSymbols[type]),_type(type){}
};


} //end namespace creatures
} //end namespace derogue
