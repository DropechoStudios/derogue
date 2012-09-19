#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "libtcod.hpp"
#include "defines.hpp"
#include "Components/IEngineComponent.hpp"

#include "stlextensions.hpp"

namespace derogue {

class Engine{
private:
    std::vector<IEngineComponent*> _components;

    TCOD_key_t _key;
    TCOD_mouse_t _mouse;
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
    if(GetComponent<T>() != NULL)
    {
        return;
    }

    IEngineComponent* component = static_cast<IEngineComponent*>(new T());
    if(component)
    {
        _components.push_back(component);
    }
}

template<class T>
T* Engine::GetComponent()
{
    IEngineComponent* comp = filter(_components,[](IEngineComponent* component){ return dynamic_cast<T*>(component) != NULL; });
    return comp
        ? static_cast<T*>(comp)
        : NULL;
}

} //end namespace derogue

#endif
