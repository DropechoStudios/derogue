#pragma once
#include "IEngineComponent.hpp"
#include <queue>
#include <string>
#include <sstream>
namespace derogue{

class LogComponent : public IEngineComponent
{
private:
    std::deque<std::string> _logLines;
    std::ostringstream  _currentLinePart;

public:
    virtual void Init(Engine* engine){};
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse)
    {
        for(int i = 0; i < _logLines.size(); ++i)
        {

            TCODConsole::root->print(0,60 + i,_logLines[i].c_str());
        }
    }

    void Log(std::string logLine)
    {
        if(19 < _logLines.size())
        {
            _logLines.pop_back();
        }
        _logLines.push_front(logLine);
        _currentLinePart.str("");
    }

    LogComponent* AppendLogPart(const char* linePart)
    {
        _currentLinePart << linePart;
        return this;
    }

    LogComponent* AppendLogPart(int linePart)
    {
        _currentLinePart << linePart;
        return this;
    }

    LogComponent* AppendLogPart(float linePart)
    {
        _currentLinePart << linePart;
        return this;
    }

    LogComponent* AppendLogPart(char linePart)
    {
        _currentLinePart << linePart;
        return this;
    }

    void CloseLogPart()
    {
        _currentLinePart << std::endl;
        Log(_currentLinePart.str());
    }

};

} //end namespace derogue
