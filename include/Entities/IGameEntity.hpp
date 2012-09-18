#pragma once
#include "libtcod.hpp"

namespace derogue
{

struct Position2d
{
    Position2d(){};
    Position2d(int x, int y):X(x),Y(y){};

    int X;
    int Y;
};

class IEntity
{
    private:
        Position2d _position;
        char _symbol;

    public:
        IEntity()
        :_position(Position2d(0,0)),_symbol(' '){};

        IEntity(char symbol)
        :_position(Position2d(0,0)),_symbol(symbol){};

        IEntity(int x, int y, char symbol)
        :_position(Position2d(x,y)),_symbol(symbol){};

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

        void SetSymbol(char symbol)
        {
            _symbol = symbol;
        }

        void SetSymbol(int symbol)
        {
            _symbol = (char)symbol;
        }

        char GetSymbol()
        {
            return _symbol;
        }

        void DrawToConsole()
        {
            TCODConsole::root->putChar(_position.X,_position.Y,_symbol);
        };
};

class IMobileEntity : public IEntity
{
};

} //end namespace derogue
