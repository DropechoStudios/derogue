#pragma once
#include "IEngineComponent.hpp"
#include <queue>

namespace derogue{

class LogComponent : public IEngineComponent
{
private:
    std::deque<char*> _logLines;

public:
    virtual void Init(Engine* engine){};
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for(auto i = 0; i < _logLines.size(); ++i)
        {
            TCODConsole::root->print(0,60 + i, _logLines[i]);
        }
    }

    void Log(const char* logLine)
    {
        if(_logLines.size() > 10)
        {
            _logLines.pop_back();
        }
        _logLines.push_front(const_cast<char *>(logLine));
    }

    void Log(char* logLine)
    {
        if(_logLines.size() > 10)
        {
            _logLines.pop_back();
        }
        _logLines.push_front(logLine);
    }
};

} //end namespace derogue
