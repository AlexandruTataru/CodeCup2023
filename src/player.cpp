#include <iostream>
#include <string>
#include <sstream>

#define KEYWORD_START "Start"
#define KEYWORD_QUIT "Quit"

#define ROW_TO_LETTER(r) char('A' + t)
#define COL_TO_LETTER(c) char('a' + c)

#define LETTER_TO_ROW(l) int(l - 'A')
#define LETTER_TO_COL(l) int(l - 'a')

using namespace std;

class Player
{
protected:
    unsigned short current_color;
    unsigned short board[7][7];

public:
    Player() : current_color(-1)
    {
        cerr << "Clearing out the board" << endl;
        memset(board, 0, sizeof(board));
    }

    virtual void parse(const string &input) = 0;
    virtual void respond() = 0;

    virtual ~Player() {}
};

class Order : public Player
{
    string answer;

public:
    Order() : Player()
    {
        cerr << "Order: Constructor called" << endl;
    }
    virtual void parse(const string &input) override
    {
        current_color = std::stoi(input.substr(0, 1));
        cerr << "Order: Received color " << current_color << endl;
        board[input[1] - 'A'][input[2] - 'a'] = current_color;
        answer = input.substr(1, 3) + input.substr(1, 3);
    }

    virtual void respond() override
    {
        cerr << "Answering with " << answer << endl;
        cout << answer;
    }
};

class Chaos : public Player
{
    bool is_update;

public:
    Chaos() : Player(), is_update(false)
    {
        cerr << "Chaos: Constructor called" << endl;
    }
    virtual void parse(const string &input) override
    {
        if (isdigit(input[0]))
        {
            current_color = std::stoi(input);
            cerr << "Chaos: Received color " << current_color << endl;
            is_update = false;
        }
        else
        {
            swap(board[input[0] - 'A'][input[1] - 'a'], board[input[2] - 'A'][input[3] - 'a']);
            cerr << "Recorded move done by the oponent" << endl;
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
                    stringstream ss;
                    ss << static_cast<char>('A' + r);
                    ss << static_cast<char>('a' + c);
                    cerr << "Answering with " << ss.str() << endl;
                    cout << ss.str();
                    return;
                }
            }
        }
    }
};

int main()
{
    std::string input;
    std::cin >> input;
    cerr << "RECEIVED INPUT: " << input << endl;

    Player *player;

    if (input.compare(KEYWORD_START) == 0)
    {
        player = new Chaos();
        cin >> input;
        cerr << "RECEIVED INPUT: " << input << endl;
    }
    else
    {
        player = new Order();
    }

    while (input.compare(KEYWORD_QUIT) != 0)
    {
        player->parse(input);
        player->respond();
        cin >> input;
    }

    return 0;
}