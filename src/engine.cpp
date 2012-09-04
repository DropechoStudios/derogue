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

    while(true){
        TCODConsole::root->clear();

        for_each(_components,[](IEngineComponent* comp){
             comp->Run();
        });

        if(TCODConsole::isKeyPressed(TCODK_ESCAPE))
        {
           return;
        }

        TCODConsole::flush();
    }
}


