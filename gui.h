#ifndef GUI_H_
#define GUI_H_
#include "observer.h"

class GUI : public Observer{
    void notify(Observer&);
    void getSubType();
    
};

#endif
