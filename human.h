#include "player.h"

#ifndef HUMAN_H_
#define HUMAN_H_

class Human : public Player{
    bool side;
public:
    Human(bool);
    bool getSide() override;
    ChessMove getNextMove(Board*) override;
};

#endif
