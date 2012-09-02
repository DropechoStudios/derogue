#pragma once
#include "libtcod.hpp"
#include "Defines.hpp"
#include "IEngineComponent.hpp"

namespace derogue {

class PlayerComponent : public IEngineComponent
{
private:
    int _playX;
    int _playY;

public:

    virtual void Init() {
        _playX = WINDOW_X / 2;
        _playY = WINDOW_Y / 2;
    };

    virtual void Run() {
        TCOD_key_t key = TCODConsole::waitForKeypress(true);
        //TCOD_key_t key = TCODConsole::checkForKeypress();
        //if(key.vk == TCODK_ESCAPE)
        //{
        //   break;
        //}

        switch(key.c){
            case 'w': _playY--; break; // up
            case 'a': _playX--; break; // left
            case 's': _playY++; break; // down
            case 'd': _playX++; break; // right
        }

        TCODConsole::root->putChar(_playX,_playY,'@');
    };
};

} //end namespace derogue



