#include <player.hpp>
#include <order.hpp>
#include <chaos.hpp>
#include <utils.hpp>

// int main()
// {
//     std::string input;
//     std::cin >> input;
//     cerr << "RECEIVED INPUT: " << input << endl;

//     Player *player;

//     if (input.compare(KEYWORD_START) == 0)
//     {
//         player = new Chaos();
//         cin >> input;
//         cerr << "RECEIVED INPUT: " << input << endl;
//     }
//     else
//     {
//         player = new Order();
//     }

//     while (input.compare(KEYWORD_QUIT) != 0)
//     {
//         player->parse(input);
//         player->respond();
//         cin >> input;
//     }

//     return 0;
// }