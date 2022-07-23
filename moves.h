#ifndef MOVE_H_
#define MOVE_H_
#include <vector>
#include "types.h"
#include "observer.h"


class Move : public Observer{
    std::vector<MoveInfo> history;
    void pop();
  public:
    ChessMove getLastMove();
    void notify(Observer&);
};

#endif