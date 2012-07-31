#include "engine.hpp"

using namespace derogue;


void Engine::Init()
{
    for(auto it = _components.begin(); it != _components.end(); it++)
    {
        (*it)->Init();
    }
    TCODSystem::setFps(25);
}

void Engine::Run()
{
    TCODConsole::initRoot(WINDOW_X,WINDOW_Y, "DeRogue v0.1", false);
    TCODConsole::root->setBackgroundColor(TCODColor::blue);


    int playX = WINDOW_X / 2;
    int playY = WINDOW_Y / 2;

    while(true){
        for(auto it = _components.begin(); it != _components.end(); it++)
        {
            (*it)->Run();
        }

        TCODConsole::root->clear();
        TCODConsole::root->putChar(playX,playY,'@');

        TCODConsole::flush();

        TCOD_key_t key = TCODConsole::waitForKeypress(true);
        //TCOD_key_t key = TCODConsole::checkForKeypress();
        if(key.vk == TCODK_ESCAPE)
        {
           break;
        }

        switch(key.c){
            case 'w': playY--; break; // up
            case 'a': playX--; break; // left
            case 's': playY++; break; // down
            case 'd': playX++; break; // right
        }
    }
}
