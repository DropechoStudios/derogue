#pragma once
#include "Entities/Items/Item.hpp"

namespace derogue {
namespace items {

class Armor : public Item
{
    public:
        Armor(MaterialType materialType) : Item(materialType) {}

        int GetDamageReduceAmount()
        {
            return 1 + GetAmount();
        }
};

} //end namespace items
} //end namespace derogue

