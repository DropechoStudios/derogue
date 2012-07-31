#include "dungeonGenerator.hpp"
#include "engine.hpp"

using namespace derogue;
using namespace dungeon;

int main(){

Engine* engine = new Engine();

engine->RegisterComponent<DungeonGenerator>();

engine->Init();
engine->Run();

return 0;
}
