#pragma once
#include "libtcod.hpp"
#include "Defines.hpp"
#include "IEngineComponent.hpp"

#include "stlextensions.hpp"

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
    for_each(_components, [](IEngineComponent* component)
    {
        auto castComp = dynamic_cast<T*>(component);
        if(castComp)
        {
            return castComp;
        }
    });
    return NULL;
}
} //end namespace derogue
