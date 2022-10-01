#include <lib.hpp>

#include <memory>

int main()
{
    std::string input;
    std::cin >> input;

    std::unique_ptr<Player> player;

    if (input.compare(KEYWORD_START) == 0)
    {
        player = std::unique_ptr<Player>(std::make_unique<Chaos>());
        std::cin >> input;
    }
    else
    {
        player = std::unique_ptr<Player>(std::make_unique<Order>());
    }

    while (input.compare(KEYWORD_QUIT) != 0)
    {
        std::string response = player->process(input);

        if (!response.empty())
        {
            std::cout << response << std::endl
                      << std::flush;
        }
        std::cin >> input;
    }

    return 0;
}