#include "Components/InteractionComponent.hpp"

using namespace derogue;

void InteractionComponent::Init(Engine* engine) {
    _map = engine->GetComponent<WorldComponent>()->GetMap();
    _items = engine->GetComponent<ItemComponent>();
    _player = engine->GetComponent<PlayerComponent>()->GetPlayer();
    _mobs = engine->GetComponent<MobComponent>()->GetMobs();
    _logger = engine->GetComponent<LogComponent>();
};

void InteractionComponent::Run(TCOD_key_t *key,TCOD_mouse_t *mouse) {
    auto playerPos = _player->GetPosition();

    switch(key->c){
        case 'W':  case 'w': TryInteract(playerPos.X, playerPos.Y - 1); break; // up
        case 'A':  case 'a': TryInteract(playerPos.X - 1, playerPos.Y); break; // left
        case 'S':  case 's': TryInteract(playerPos.X, playerPos.Y + 1); break; // down
        case 'D':  case 'd': TryInteract(playerPos.X + 1, playerPos.Y); break; // right
        case 'G':  case 'g': InteractWithItem(playerPos.X, playerPos.Y); break; // Pick up Item
    }
};

void InteractionComponent::TryInteract(int x, int y)
{
    if(_map->isWalkable(x,y))
    {
        _player->SetPosition(x,y);
    }
    else
    {
        auto effectedThing = TCODConsole::root->getChar(x,y);
        switch(effectedThing)
        {
            case ' ': InteractWithWall(x,y);  break;
            default: InteractWithMob(x,y);
        }
    }
}

void InteractionComponent::InteractWithWall(int x, int y)
{
    _logger
        ->AppendLogPart("walked into a wall at x: ")->AppendLogPart(x)
        ->AppendLogPart(" y: ")->AppendLogPart(y)
        ->CloseLogPart();
}

void InteractionComponent::InteractWithMob(int x, int y)
{
    auto mob = filter(_mobs,[x,y](Entity* mob){
           auto pos = mob->GetPosition();
           return pos.X == x && pos.Y == y;
    });

    if(mob)
    {
        _logger
            ->AppendLogPart("walked into mob named ")->AppendLogPart(mob->GetSymbol().Char)
            ->CloseLogPart();

        _logger
            ->AppendLogPart("walked into a mob at x: ")->AppendLogPart(x)
            ->AppendLogPart(" y: ")->AppendLogPart(y)
            ->CloseLogPart();
    }
}

void InteractionComponent::InteractWithItem(int x, int y)
{
    auto item = _items->GetItemAt(x,y);
    if(item)
    {
        _logger->AppendLogPart("picked up a thing.")->CloseLogPart();
    }
    else
    {
        _logger->AppendLogPart("nothing to pick up.")->CloseLogPart();
    }
}
