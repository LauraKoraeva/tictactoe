#include <iostream>
#include "Board.h"

Board::Board() : board(9, Player::NONE) { }

bool Board::makeMove(int position, Player player) 
{
    if (position < 0 || position >= 9 || board[position] != Player::NONE) 
    {
        return false;
    }
    board[position] = player;
    return true;
}

Board::Player Board::getWinner() const 
{
    int winningCombinations[8][3] = {
        {0, 1, 2}, 
        {3, 4, 5}, 
        {6, 7, 8},
        
        {0, 3, 6}, 
        {1, 4, 7}, 
        {2, 5, 8}, 

        {0, 4, 8}, 
        {2, 4, 6}
    };

    for (int i = 0; i < 8; ++i) 
    {
        Player p = board[winningCombinations[i][0]];
        if (p != Player::NONE &&
            p == board[winningCombinations[i][1]] &&
            p == board[winningCombinations[i][2]]) 
        {
            return p;
        }
    }

    return Player::NONE; 
}

bool Board::isBoardFull() const 
{
    for (Player cell : board) 
    {
        if (cell == Player::NONE) 
        {
            return false; 
        }
    }
    return true; 
}

Board::Player Board::getCell(int position) const 
{
    return board[position];
}

void Board::printBoard() const 
{
    std::cout << "\n=========================\n";
    for (int i = 0; i < 9; ++i) 
    {
        switch (board[i]) 
        {
            case Player::X: std::cout << "X"; break;
            case Player::O: std::cout << "O"; break;
            case Player::NONE: std::cout << "."; break;
        }
        if ((i + 1) % 3 == 0) 
        {
            std::cout << '\n';
        }
    }
    std::cout << "=========================\n";
}

void Board::clearBoard() 
{
    board.assign(9, Player::NONE);
}