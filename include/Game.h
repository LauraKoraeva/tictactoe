#pragma once
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Game 
{
    Board board;
    Player* player1;
    Player* player2;
    Board::Player currentPlayerMark;

    void switchPlayer();
    bool isValidMove(int move);
    bool isGameOver();
    void printResult();
    void initPlayers(int gameMode);

public:
    Game();
    ~Game();
    void play();
};
