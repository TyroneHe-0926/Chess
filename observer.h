#ifndef OBSERVER_H_
#define OBSERVER_H_

class Cell;
class Observer{
  public:
    virtual void notify(Cell&)=0;
};

#endif
