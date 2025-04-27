#include <iostream>
#include <random>
#include <algorithm>
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Board::Player mark) : Player(mark) { }

std::string ComputerPlayer::getName() const { return "Computer"; }

int ComputerPlayer::getMove(const Board& board) 
{
    return findBestMove(board);
}

int ComputerPlayer::findBestMove(const Board& board) 
{
    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 0; i < 9; ++i) 
    {
        if (board.getCell(i) == Board::Player::NONE) 
        {
            Board tempBoard = board;
            tempBoard.makeMove(i, mark);
            int moveScore = minimax(tempBoard, 0, false);

            if (moveScore > bestScore) 
            {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

int ComputerPlayer::minimax(Board board, int depth, bool isMaximizing) 
{
    Board::Player winner = board.getWinner();

    if (winner == mark) 
    {
        return 10;
    }
    if (winner != Board::Player::NONE && winner != mark) 
    {
        return -10;
    }
    if (board.isBoardFull()) 
    {
        return 0;
    }

    if (isMaximizing) 
    {
        int bestScore = -1000;
        for (int i = 0; i < 9; ++i) 
        {
            if (board.getCell(i) == Board::Player::NONE) 
            {
                Board tempBoard = board;
                tempBoard.makeMove(i, mark);
                int score = minimax(tempBoard, depth + 1, false);
                bestScore = std::max(score, bestScore);
            }
        }
        return bestScore;
    } 
    else 
    {
        int bestScore = 1000;
        Board::Player opponentMark = (mark == Board::Player::X) ? Board::Player::O : Board::Player::X;
        for (int i = 0; i < 9; ++i) 
        {
            if (board.getCell(i) == Board::Player::NONE) 
            {
                Board tempBoard = board;
                tempBoard.makeMove(i, opponentMark);
                int score = minimax(tempBoard, depth + 1, true);
                bestScore = std::min(score, bestScore);
            }
        }
        return bestScore;
    }
}