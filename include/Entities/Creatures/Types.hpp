#pragma once

namespace derogue{
namespace creatures{

enum MonsterType
{
    MT_GOBLIN,
    MT_DRAGON,
    MT_ORC
}

std::map<MonsterType,char> MonsterTypesToSymbols = {
    {MT_GOBLIN,  'g'},
    {MT_DRAGON, 'D'},
    {MT_ORC,  'O'}
};


}
}
