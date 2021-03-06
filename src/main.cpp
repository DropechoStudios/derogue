#include "Components/PlayerComponent.hpp"
#include "Components/DungeonComponent.hpp"
#include "Components/PathfindingComponent.hpp"
#include "Components/LightingComponent.hpp"
#include "Components/MobComponent.hpp"
#include "Components/ItemComponent.hpp"
#include "Components/InteractionComponent.hpp"
#include "Components/LogComponent.hpp"
#include "engine.hpp"

using namespace derogue;

int main(){
Engine* engine = new Engine();

engine->RegisterComponent<WorldComponent>();
engine->RegisterComponent<DungeonComponent>();
engine->RegisterComponent<ItemComponent>();
engine->RegisterComponent<PlayerComponent>();
engine->RegisterComponent<PathfindingComponent>();
engine->RegisterComponent<MobComponent>();
engine->RegisterComponent<LightingComponent>();
engine->RegisterComponent<InteractionComponent>();
engine->RegisterComponent<LogComponent>();

engine->Init();
engine->Run();

return 0;
}
