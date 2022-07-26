#ifndef GAME_H_
#define GAME_H_
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"


class Game{
    Board *b;
    bool side, checkmate, started;
    Player* player1;
    Player* player2;
    int computer;
    float player1Score, player2Score;
    void endGame(char);
  public:
    void play();
    Game();
    ~Game();
};


#endif
