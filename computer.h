#include "player.h"

#ifndef COMPUTER_H_
#define COMPUTER_H_

class Computer : public Player{
    bool side;
    int difficulty;
public:
    Computer(bool, int);
    bool getSide() override;
    int getDiff();
    ChessMove getNextMove(Board*) override;
    PlayerType getPlayerType() override;
    ~Computer(){};
};

#endif
