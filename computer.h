#include "player.h"

#ifndef COMPUTER_H_
#define COMPUTER_H_

class Computer : public Player{
    int side, difficulty;
public:
    Computer(int, int);
    int getSide() override;
    int getDiff();
    std::pair<std::pair<char, int>, std::pair<char, int>> getNextMove();
};

#endif
