#include "Components/WorldComponent.hpp"
#include "Components/PlayerComponent.hpp"
#include "Components/PathfindingComponent.hpp"
#include "engine.hpp"

using namespace derogue;

void Engine::Init()
{
    TCODSystem::setFps(25);
    TCODConsole::initRoot(WINDOW_X, WINDOW_Y, "DeRogue v0.3", false);
    for_each(_components,[this](IEngineComponent* comp){ comp->Init(this); });
}

void Engine::Run()
{
    while(true)
    {
        TCODSystem::checkForEvent(eventType,&_key,&_mouse);
        if(TCODConsole::isKeyPressed(TCODK_ESCAPE)) { return; }

        TCODConsole::root->clear();
            for_each(_components,[this](IEngineComponent* comp){ comp->Run(&this->_key,&this->_mouse); });
        TCODConsole::flush();
    }
}
