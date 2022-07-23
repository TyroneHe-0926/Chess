#ifndef MOVE_H_
#define MOVE_H_
#include <vector>
#include "types.h"
#include "observer.h"


class Move : public Observer{
    std::vector<moveinfo> history;
    void pop();
  public:
    chessmove getLastMove();
    void notify(Observer&);
    void getSubType();
};

#endif