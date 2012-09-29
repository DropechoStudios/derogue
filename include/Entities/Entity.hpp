#pragma once
#include "libtcod.hpp"

namespace derogue
{

struct Position2d
{
    Position2d():X(0),Y(0){};
    Position2d(int x, int y):X(x),Y(y){};

    int X;
    int Y;
};

struct Symbol
{
    Symbol(char c, TCODColor color = TCODColor::white): Char(c),Color(color){};

    char Char;
    TCODColor Color;
};

class Entity
{
    private:
        Position2d _position;
        Symbol _symbol;

    public:
        Entity()
        :_position(0,0),_symbol(' '){};

        Entity(char symbol)
        :_position(0,0),_symbol(symbol){};

        Entity(int x, int y, char symbol, TCODColor color = TCODColor::white)
        :_position(x,y),_symbol(symbol,color){};

        Position2d GetPosition()
        {
            return _position;
        }

        void SetPosition(Position2d pos)
        {
            _position = pos;
        }

        void SetPosition(int x, int y)
        {
            _position.X = x;
            _position.Y = y;
        }

        Symbol GetSymbol()
        {
            return _symbol;
        }

        void DrawToConsole()
        {
            TCODConsole::root->putChar(_position.X,_position.Y,_symbol.Char);
            TCODConsole::root->setCharForeground(_position.X,_position.Y,_symbol.Color);
        };
};

} //end namespace derogue
