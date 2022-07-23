#ifndef GAME_H_
#define GAME_H_
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"


class Game{
    Board *b;
    bool side;
    Player* player1;
    Player* player2;
    int computer;
  public:
    Game();
    void play();
};


#endif
