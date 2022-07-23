#ifndef GUI_H_
#define GUI_H_
#include "observer.h"

class GUI : public Observer{
  public:
    void notify(Cell&) override;
    GUI();
    virtual ~GUI(){};
};

#endif
