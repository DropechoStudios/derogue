#include "WorldComponent.hpp"
#include "PlayerComponent.hpp"
#include "PathfindingComponent.hpp"
#include "engine.hpp"

using namespace derogue;

void Engine::Init()
{
    TCODSystem::setFps(25);
    TCODConsole::initRoot(WINDOW_X,WINDOW_Y, "DeRogue v0.2", false);
    for_each(_components,[this](IEngineComponent* comp){ comp->Init(this); });
}

void Engine::Run()
{
    auto map = GetComponent<WorldComponent>()->GetMap();
    auto player = GetComponent<PlayerComponent>()->GetPlayer();
    auto pathFinder = GetComponent<PathfindingComponent>();

    int pathx = 0;
    int pathy = 0;

    TCOD_key_t key;
    TCOD_mouse_t mouse;

    while(true){
        TCODConsole::root->clear();
        TCODSystem::checkForEvent((TCOD_event_t)(TCOD_KEY_PRESSED|TCOD_EVENT_MOUSE),&key,&mouse);

        for(int x = 0; x < WINDOW_X; x++){
            for(int y = 0; y < WINDOW_Y; y++){
                if(map->isInFov(x,y)){
                    bool wall = map->isWalkable(x,y);
					TCODColor light=(wall ? lightWall : lightGround);
                    TCODConsole::root->setCharBackground(x,y,light, TCOD_BKGND_SET );
                }
                else
                {
                    bool wall = map->isWalkable(x,y);
					TCODColor light=(wall ? darkWall : darkGround);
                    TCODConsole::root->setCharBackground(x,y,light, TCOD_BKGND_SET );
                }
            }
        }

        for_each(_components,[&key,&mouse](IEngineComponent* comp){ comp->Run(&key,&mouse); });

        pathFinder->ComputePath(1,player->X,player->Y,mouse.cx,mouse.cy);
        pathFinder->DrawPath(1);

        if(TCODConsole::isKeyPressed(TCODK_ESCAPE))
        {
           return;
        }

        TCODConsole::flush();
    }
}


