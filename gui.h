#ifndef GUI_H_
#define GUI_H_
#include "sdl_wrap.h"
#include "observer.h"

class GUI : public Observer{
    const Colour light = {(char)255,(char)228,(char)181};
    const Colour dark = {(char)131, (char)42, (char)13};
    const int dispsize = 702;
    //Screen s;
    void drawBoard();
    int updates;
  public:
    void notify(Cell&) override;
    void update();
    GUI();
    virtual ~GUI(){};
};

#endif
