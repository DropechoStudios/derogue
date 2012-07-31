#pragma once
#include "libtcod.hpp"
#include "Defines.hpp"
#include "IEngineComponent.hpp"

#include <vector>
namespace derogue {

class Engine{
private:
    std::vector<IEngineComponent*> _components;
public:
    template<class T>
    void RegisterComponent();

    void Init();
    void Run();
};

template<class T>
void Engine::RegisterComponent()
{
    IEngineComponent* component = dynamic_cast<IEngineComponent*>(new T());
    if(component)
    {
        _components.push_back(component);
    }
}

} //end namespace derogue
