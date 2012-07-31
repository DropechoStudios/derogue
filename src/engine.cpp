#include "engine.hpp"

using namespace derogue;

class BspListener : public ITCODBspCallback {
public :
	bool visitNode(TCODBsp *node, void *userData) {
        TCODConsole::root->rect(node->x,node->y, node->w, node->h, true);
		return true;
	}
};

void Engine::BuildBSP(){
    _bsp = new TCODBsp(0,0,WINDOW_X,WINDOW_Y);

    _bsp->splitRecursive(NULL,6,.9,.9,20,20);
}

void Engine::Init(){
    _map = new TCODMap(WINDOW_X,WINDOW_Y);

    for(int x = 0; x < WINDOW_X; x++)
    {
        for(int y = 0; y <WINDOW_Y; y++){
            _test[x][y] = ' ';
        }
    }

    BuildBSP();
    TCODSystem::setFps(0);
}

void Engine::Run(){
    TCODConsole::initRoot(WINDOW_X,WINDOW_Y, "DeRogue v0.1", false);
    TCODConsole::root->setBackgroundColor(TCODColor::blue);


    long int offset = 0;

    while(true){
        TCODNoise * noise2d = new TCODNoise(2);
        for(int x = 0; x < WINDOW_X; x++){
            for(int y = 0; y < WINDOW_Y; y++){
                float p[2]={float(x)/50.0f,float(y)/50.0f};
                float val = noise2d->getFbmSimplex(p,8);
                //TCODConsole::root->setBack(x - offset,y,TCODColor::lerp(TCODColor::darkGrey,TCODColor::lightRed,CLAMP(0.0f,1.0f,val)));
                int code = (int)(CLAMP(0.0f,255.0f,val* 255)) % 3;
                if(code == 1) code--;
                TCODConsole::root->putChar(x,y,code);
            }
        }

        TCODConsole::flush();

        TCOD_key_t key = TCODConsole::waitForKeypress(true);
        //TCOD_key_t key = TCODConsole::checkForKeypress();
        if(key.vk == TCODK_ESCAPE)
        {
           break;
        }
        delete noise2d;
    }
}
