#ifndef SUBJECT_H_
#define SUBJECT_H_
#include "observer.h"


class Subject : public Observer{
  public:
    void notifyObservers();
    void attach(Observer*);
};

#endif
