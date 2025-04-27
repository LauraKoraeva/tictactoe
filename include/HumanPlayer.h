#pragma once
#include <string>
#include "Player.h"
#include "Board.h"

class HumanPlayer : public Player 
{
public:
    HumanPlayer(Board::Player mark);
    int getMove(const Board& board) override;
};
