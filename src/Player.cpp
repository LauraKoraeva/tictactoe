#include "Player.h"

Player::Player(Board::Player mark) : mark(mark) { }

void Player::setName(std::string inName)
{
    name = inName;
}
std::string Player::getName() const { return name; }

Board::Player Player::getMark() const 
{
    return mark;
}