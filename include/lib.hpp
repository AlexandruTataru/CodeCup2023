#pragma once
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

#include <time.h>

#define KEYWORD_START "Start"
#define KEYWORD_QUIT "Quit"

#define ROW_TO_LETTER(r) char('A' + r)
#define COL_TO_LETTER(c) char('a' + c)

#define LETTER_TO_ROW(l) int(l - 'A')
#define LETTER_TO_COL(l) int(l - 'a')

class ColorManager
{
    std::array<unsigned short, 7> availableColors = {7, 7, 7, 7, 7, 7, 7};

public:
    ColorManager() = default;
    bool isFirst(int color)
    {
        return availableColors[color - 1] == 7;
    }
    void subtract(int color)
    {
        --availableColors[color - 1];
    }
    // highestProbabibility
    // subtract color
    //
};

struct CellInfo
{
    std::array<int, 7> weights{0, 0, 0, 0, 0, 0, 0};
    int color = 0; /* 0 for free */
};

class BoardManager
{
    std::array<std::array<CellInfo, 7>, 7> board;

    void addWeightForCenter()
    {
        std::cerr << "addWeightForCenter" << std::endl;
        for (auto i = 0; i < board.size(); ++i)
        {
            for (auto j = 0; j < board[0].size(); ++j)
            {
                if (0 != board[i][j].color)
                {
                    for (auto &weight : board[i][j].weights)
                    {
                        weight = -1;
                    }
                    continue;
                }
                for (auto &weight : board[i][j].weights)
                {
                    weight = 3 - std::max(abs(3 - i), abs(3 - j));
                }
            }
        }
    }

    void calculateWeights(int color)
    {
        addWeightForCenter();
    }

    std::pair<int, int> getMaxWeight(int color)
    {
        std::pair<int, int> maxWeightPosition{0, 0};
        int maxWeight = board[0][0].weights[color - 1];
        for (auto i = 0; i < board.size(); ++i)
        {
            for (auto j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j].weights[color - 1] > maxWeight)
                {
                    maxWeight = board[i][j].weights[color - 1];
                    maxWeightPosition = std::make_pair(i, j);
                }
            }
        }
        if (maxWeight == board[0][0].weights[color - 1])
        {
            std::cerr << "Incoming color: " << color << std::endl;

            for (auto i = 0; i < board.size(); ++i)
            {
                for (auto j = 0; j < board[0].size(); ++j)
                {
                    std::cerr << board[i][j].weights[color - 1] << " ";
                }
                std::cerr << std::endl;
            }
        }
        std::cerr << "Best choosen position is " << maxWeightPosition.first << " " << maxWeightPosition.second << std::endl;
        return maxWeightPosition;
    }

public:
    BoardManager() = default;

    void placeColor(const std::pair<int, int> &pos, int color)
    {
        board[pos.first][pos.second].color = color;
        std::cerr << "Placing color " << color << " in position " << pos.first << " " << pos.second << std::endl;
        for (auto &weight : board[pos.first][pos.second].weights)
        {
            weight = -1;
        }
    }

    void move(const std::pair<int, int> &src, const std::pair<int, int> &dst)
    {
        std::swap(board[src.first][src.second], board[dst.first][dst.second]);
    }

    std::pair<int, int> bestPositionForColor(int color)
    {
        std::cerr << "Getting best position for color" << std::endl;
        calculateWeights(color);
        return getMaxWeight(color);
    }
};

class Player
{
private:
    virtual void parse(const std::string &input) = 0;
    virtual void createAnswer() = 0;

protected:
    std::string answer;
    unsigned short current_color;
    ColorManager colors;
    BoardManager board;

public:
    Player() : current_color(-1)
    {
    }

    virtual std::string process(const std::string &input)
    {
        parse(input);
        createAnswer();
        return answer;
    }
    virtual ~Player() {}
};

class Order : public Player
{

    void parse(const std::string &input) override
    {
        current_color = std::stoi(input.substr(0, 1));
        board.placeColor(std::make_pair(LETTER_TO_ROW(input[1]), LETTER_TO_COL(input[2])), current_color);
        answer = input.substr(1, 3) + input.substr(1, 3);
    }

    void createAnswer() override
    {
    }

public:
    Order() : Player()
    {
    }
};

class Chaos : public Player
{
    bool is_update;
    void parse(const std::string &input) override
    {
        if (isdigit(input[0]))
        {
            current_color = std::stoi(input);
            is_update = false;
        }
        else
        {
            board.move(std::make_pair(LETTER_TO_ROW(input[0]), LETTER_TO_COL(input[1])), std::make_pair(LETTER_TO_ROW(input[2]), LETTER_TO_COL(input[3])));
            is_update = true;
        }
    }

    void createAnswer() override
    {
        if (is_update)
        {
            answer.clear();
            return;
        }
        auto bestMove = board.bestPositionForColor(current_color);
        board.placeColor(bestMove, current_color);
        std::stringstream ss;
        ss << ROW_TO_LETTER(bestMove.first);
        ss << COL_TO_LETTER(bestMove.second);
        answer = ss.str();
    }

public:
    Chaos() : Player(), is_update(false)
    {
    }
};
