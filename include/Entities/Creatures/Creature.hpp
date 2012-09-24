#pragma once

#include "Entities/Entity.hpp"
#include "Types.hpp"

namespace derogue{

class Creature : public Entity
{
private:
    MonsterType _type;
public:
    Creature(MonsterType type) : _type(type){}
};

} //end namespace derogue
