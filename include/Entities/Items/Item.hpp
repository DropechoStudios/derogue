#pragma once
#include "Entities/Entity.hpp"
#include "Entities/Items/Types.hpp"

namespace derogue {
namespace items {

class Item
{
    private:
        MaterialType _materialType;
        Symbol _symbol;

    protected:
        Item(MaterialType materialType, char symbol = 0) : _materialType(materialType),_symbol(symbol) {}

        int GetAmount()
        {
            return _materialType;
        }

    public:
        Symbol GetSymbol()
        {
            return _symbol;
        }
};

} //end namespace items
} //end namespace derogue
