#pragma once
#ifndef DEFINES_H
#define DEFINES_H

#include <cstdio>
#include "libtcod.hpp"

namespace derogue {

const int DUNGEON_X = 80;
const int DUNGEON_Y = 60;

const int WINDOW_X = 80;
const int WINDOW_Y = 80;

const TCODColor darkWall(50,50,150);
const TCODColor darkGround(0,0,100);

//const TCODColor darkWall(0,0,0);
//const TCODColor darkGround(0,0,0);

const TCODColor lightWall(130,110,50);
const TCODColor lightGround(200,180,50);

const int LightDistance = 10;

const TCOD_event_t eventType = (TCOD_event_t)(TCOD_KEY_PRESSED|TCOD_EVENT_MOUSE);

struct Player {
    int X;
    int Y;
};


} //end namespace derogue

#endif
