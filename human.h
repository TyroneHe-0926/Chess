#include "player.h"

#ifndef HUMAN_H_
#define HUMAN_H_

class Human : public Player{
    bool side;
public:
    Human(bool);
    bool getSide() override;
    bool checkMove(Board* b, ChessMove nextmove);
    bool checkStale(Board* b);
    ChessMove getNextMove(Board*) override;
    PlayerType getPlayerType() override;
    ~Human(){};
};

#endif
