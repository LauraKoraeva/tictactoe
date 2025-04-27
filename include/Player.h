#pragma once
#include <string>
#include "Board.h"

class Player 
{
protected:
    Board::Player mark;
    std::string name;

public:
    Player(Board::Player mark);
    void setName(std::string inName);
    virtual std::string getName() const;
    virtual int getMove(const Board& board) = 0; 
    Board::Player getMark() const;
};
