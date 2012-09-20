#pragma once
#include "Entities/Item.hpp"

namespace derogue {
namespace items {



class Potion : public Item
{
    public:
        Potion(MaterialType materialType) : Item(materialType) {}

        int GetEffectAmount()
        {
            return 1 + GetAmount();
        }
};

} //end namespace items
} //end namespace derogue
