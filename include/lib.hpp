#pragma once
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include <time.h>

#define KEYWORD_START "Start"
#define KEYWORD_QUIT "Quit"

#define ROW_TO_LETTER(r) char('A' + r)
#define COL_TO_LETTER(c) char('a' + c)

#define LETTER_TO_ROW(l) int(l - 'A')
#define LETTER_TO_COL(l) int(l - 'a')

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
        // board[input[1] - 'A'][input[2] - 'a'] = current_color;
        board[LETTER_TO_ROW(input[1])][LETTER_TO_COL(input[2])] = current_color;
        answer = input.substr(1, 3) + input.substr(1, 3);
    }

    virtual void respond() override
    {
        std::cout << answer << std::endl
                  << std::flush;
    }
};

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
            std::swap(board[LETTER_TO_ROW(input[0])][LETTER_TO_COL(input[1])], board[LETTER_TO_ROW(input[2])][LETTER_TO_COL(input[3])]);
            is_update = true;
        }
    }

    virtual void respond() override
    {
        if (is_update)
            return;
        std::vector<int> availableMoves;
        srand(time(NULL));
        for (unsigned short r = 0; r < 7; ++r)
        {
            for (unsigned short c = 0; c < 7; ++c)
            {
                if (board[r][c] == 0)
                {
                    availableMoves.push_back(r * 10 + c);
                }
            }
        }
        int randomFreeCell = availableMoves.at(rand() % availableMoves.size());
        int c = randomFreeCell % 10;
        int r = (randomFreeCell - c) / 10;
        board[r][c] = current_color;
        std::stringstream ss;
        ss << ROW_TO_LETTER(r);
        ss << COL_TO_LETTER(c);
        std::cout << ss.str() << std::endl
                  << std::flush;
    }
};
