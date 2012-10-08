#pragma once
#include "PlayerComponent.hpp"
#include "MobComponent.hpp"
#include "ItemComponent.hpp"
#include "WorldComponent.hpp"
#include "LogComponent.hpp"

namespace derogue
{

class InteractionComponent : public IEngineComponent
{
public:
    virtual void Init(Engine* engine);
    virtual void Run(TCOD_key_t *key,TCOD_mouse_t *mouse);
    void TryInteract(int x, int y);

private:
    TCODMap* _map;
    Entity* _player;
    CreatureList _mobs;
    LogComponent* _logger;
    ItemComponent* _items;

    void InteractWithWall(int x, int y);
    void InteractWithMob(int x, int y);
    void InteractWithItem(int x, int y);
};

} //end namespace derogue
