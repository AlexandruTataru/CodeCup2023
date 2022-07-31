#pragma once

#include <iostream>

#include "player.hpp"

class Order : public Player
{
    std::string answer;

public:
    Order() : Player()
    {
    }
    virtual void parse(const std::string &input) override
    {
        current_color = std::stoi(input.substr(0, 1));
        board[input[1] - 'A'][input[2] - 'a'] = current_color;
        answer = input.substr(1, 3) + input.substr(1, 3);
    }

    virtual void respond() override
    {
        std::cout << answer;
    }
};