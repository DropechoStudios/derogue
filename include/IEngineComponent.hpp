#pragma once

namespace derogue {

class IEngineComponent{
public:
    virtual void Init() = 0;
    virtual void Run() = 0;
};

}
