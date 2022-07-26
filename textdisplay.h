#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_
#include <vector>
#include <iostream>
#include "observer.h"

class TextDisplay : public Observer{
    std::vector<std::vector<char>> display;
  public:
    void notify(Cell&) override;
    friend std::ostream& operator<<(std::ostream&, const TextDisplay&);
    char atPos(int, int);
    TextDisplay();
    virtual ~TextDisplay(){};
};

#endif
