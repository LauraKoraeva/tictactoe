#pragma once
#include "Player.h"
#include "Board.h"

class ComputerPlayer : public Player 
{
    int findBestMove(const Board& board);
    int minimax(Board board, int depth, bool isMaximizing);

public:
    ComputerPlayer(Board::Player mark);
    std::string getName() const override;
    int getMove(const Board& board) override;
};

