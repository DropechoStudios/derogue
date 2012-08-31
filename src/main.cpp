#include "PlayerComponent.hpp"
#include "engine.hpp"

using namespace derogue;

int main(){

Engine* engine = new Engine();

engine->RegisterComponent<PlayerComponent>();

engine->Init();
engine->Run();

return 0;
}
