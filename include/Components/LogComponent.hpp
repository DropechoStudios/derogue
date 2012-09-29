#pragma once
#include "IEngineComponent.hpp"
#include <queue>

namespace derogue{

class LogComponent : public IEngineComponent
{
private:
    std::queue<char*> _logLines;

public:
    virtual void Init(Engine* engine){};
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for(auto it = _logLines.begin(), auto i = 0; _logLines.end(); ++it, ++i)
        {
            TCODConsole::root->print(0,60 + i,(*it));
        }
    }

    void Log(char* logLine)
    {
        _logLines.push(logLine);
        if(_logLines.size() > 6)
        {
            _logLines.pop();
        }
    }
};

} //end namespace derogue
