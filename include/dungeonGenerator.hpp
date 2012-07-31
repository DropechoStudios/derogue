#pragma once
#include "libtcod.hpp"
#include "IEngineComponent.hpp"

namespace derogue {
namespace dungeon {

//class BspListener : public ITCODBspCallback {
//public :
//	bool visitNode(TCODBsp *node, void *userData) {
//        TCODConsole::root->rect(node->x,node->y, node->w, node->h, true);
//		return true;
//	}
//};

class DungeonGenerator : public IEngineComponent
{
public:
    virtual void Init() {};
    virtual void Run() {};
};

} //end namespace dungeon
} //end namespace derogue

