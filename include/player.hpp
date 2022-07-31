#pragma once
#include <string>

class Player
{
protected:
    unsigned short current_color;
    unsigned short board[7][7];

public:
    Player() : current_color(-1)
    {
        memset(board, 0, sizeof(board));
    }

    virtual void parse(const std::string &input) = 0;
    virtual void respond() = 0;

    virtual ~Player() {}
};