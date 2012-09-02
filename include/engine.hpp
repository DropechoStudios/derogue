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

    template<class T>
    T* GetComponent();

    void Init();
    void Run();
};

template<class T>
void Engine::RegisterComponent()
{
    if(GetComponent<T>())
    {
        return;
    }
    IEngineComponent* component = dynamic_cast<IEngineComponent*>(new T());
    if(component)
    {
        _components.push_back(component);
    }
}

template<class T>
T* Engine::GetComponent()
{
    for(auto it = _components.begin(); it != _components.end(); it++)
    {
        auto component = dynamic_cast<T*>((*it));
        if(component)
        {
            return component;
        }
    }
    return NULL;
}
} //end namespace derogue
