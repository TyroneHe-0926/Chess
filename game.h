#ifndef GAME_H_
#define GAME_H_
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"


class Game{
    Board *b;
    bool side, checkmate;
    Player* player1;
    Player* player2;
    int computer, player1Score, player2Score;
  public:
    void play();
    bool isWon();
    Game();
    ~Game();
};


#endif
