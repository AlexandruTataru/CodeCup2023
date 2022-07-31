#pragma once

#include <iostream>
#include <sstream>

#include "player.hpp"

class Chaos : public Player
{
    bool is_update;

public:
    Chaos() : Player(), is_update(false)
    {
    }
    virtual void parse(const std::string &input) override
    {
        if (isdigit(input[0]))
        {
            current_color = std::stoi(input);
            is_update = false;
        }
        else
        {
            std::swap(board[input[0] - 'A'][input[1] - 'a'], board[input[2] - 'A'][input[3] - 'a']);
            is_update = true;
        }
    }

    virtual void respond() override
    {
        if (is_update)
            return;
        for (unsigned short r = 0; r < 7; ++r)
        {
            for (unsigned short c = 0; c < 7; ++c)
            {
                if (board[r][c] == 0)
                {
                    board[r][c] = current_color;
                    std::stringstream ss;
                    ss << static_cast<char>('A' + r);
                    ss << static_cast<char>('a' + c);
                    std::cout << ss.str();
                    return;
                }
            }
        }
    }
};