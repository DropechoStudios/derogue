#pragma once

#include "Types.hpp"
#include "Entities/Entity.hpp"

namespace derogue{
namespace creatures {

class Creature : public Entity
{
private:
    MonsterType _type;
public:
    Creature(MonsterType type) : Entity(1,1,MonsterTypesToSymbols[type]),_type(type){}
};

} //end namespace creatures
} //end namespace derogue
