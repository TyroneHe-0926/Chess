#include "player.h"

#ifndef HUMAN_H_
#define HUMAN_H_

class Human : public Player{
    bool side;
public:
    Human(bool);
    bool getSide() override;
    bool checkMove(Board* b, ChessMove nextmove);
    ChessMove getNextMove(Board*) override;
    ~Human(){};
};

#endif
