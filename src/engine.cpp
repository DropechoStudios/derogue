#include "WorldComponent.hpp"
#include "PlayerComponent.hpp"
#include "PathfindingComponent.hpp"
#include "engine.hpp"

using namespace derogue;

void Engine::Init()
{
    TCODSystem::setFps(25);
    TCODConsole::initRoot(WINDOW_X, WINDOW_Y, "DeRogue v0.2", false);
    for_each(_components,[this](IEngineComponent* comp){ comp->Init(this); });
}

void Engine::Run()
{
    while(true){
        TCODSystem::checkForEvent(eventType,&_key,&_mouse);
        if(TCODConsole::isKeyPressed(TCODK_ESCAPE)) { return; }

        TCODConsole::root->clear();
            for_each(_components,[&_key,&_mouse](IEngineComponent* comp){ comp->Run(&_key,&_mouse); });
        TCODConsole::flush();
    }
}


/*
pathFinder->ComputePath(1,player->X,player->Y,_mouse.cx,_mouse.cy);
pathFinder->DrawPath(1);

pathFinder->ComputePath(2,0,0,_mouse.cx,_mouse.cy);
pathFinder->DrawPath(2,TCODColor::darkerAmber);
*/
