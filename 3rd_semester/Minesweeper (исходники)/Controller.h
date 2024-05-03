#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Field.h"

class Controller {
    bool _isGameOver;
    bool _isWin;
public:
    Controller();
    void open(int, int, Field*);
    void mark(int, int, Field*);
    bool isGameOver();
    bool isWin();
    void winCheck(Field*);
    void looseCheck(int x, int y, Field*);
};

#endif // CONTROLLER_H
