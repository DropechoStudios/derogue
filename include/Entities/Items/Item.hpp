#pragma once
#include "Entities/Items/Types.hpp"

namespace derogue {
namespace items {

class Item
{
    private:
        MaterialType _materialType;

    protected:
        Item(MaterialType materialType) : _materialType(materialType){}

        int GetAmount()
        {
            return _materialType;
        }
};

} //end namespace items
} //end namespace derogue
