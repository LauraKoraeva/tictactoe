#pragma once
#include <vector>

class Board 
{
public:
    enum class Player 
    {
        NONE,
        X,
        O
    };

    Board();

    bool makeMove(int position, Player player);
    Player getWinner() const;
    bool isBoardFull() const;
    Player getCell(int position) const;
    void printBoard() const;
    void clearBoard();

private:
    std::vector<Player> board;
};