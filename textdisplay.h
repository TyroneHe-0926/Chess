#ifndef TEXTDISPLAY_H_
#define TEXTDISPLAY_H_
#include <vector>
#include <iostream>
#include "observer.h"

class TextDisplay{
    std::vector<std::vector<char>> display;
  public:
    void notify(Observer&);
    friend std::ostream& operator<<(std::ostream&, const TextDisplay&);
    TextDisplay();
};

#endif
