#include <iostream>

#include <player.hpp>
#include <order.hpp>
#include <chaos.hpp>
#include <utils.hpp>

int main()
{
    std::string input;
    std::cin >> input;

    Player *player;

    if (input.compare(KEYWORD_START) == 0)
    {
        player = new Chaos();
        std::cin >> input;
    }
    else
    {
        player = new Order();
    }

    while (input.compare(KEYWORD_QUIT) != 0)
    {
        player->parse(input);
        player->respond();
        std::cin >> input;
    }

    return 0;
}