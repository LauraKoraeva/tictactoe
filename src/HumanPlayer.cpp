#include <iostream>
#include <limits>
#include <numeric>
#include "HumanPlayer.h"
#include "Utility.h"

HumanPlayer::HumanPlayer(Board::Player mark) : Player(mark) { }

int HumanPlayer::getMove(const Board& board) 
{
    int move;
    do
    {
        std::cout << name << ", your move (0-8): ";
        std::cin >> move;
    } while (!correctInput(move));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return move;
}