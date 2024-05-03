#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include <QPixmap>

class Field {
    int _width;
    int _height;
    int _numBomb;
    Cell** cell;
public:
    Field(int, int, int);
    ~Field();
    void generate();
    void draw(QPixmap*);
    int width();
    int height();
    int numBomb();
    Cell** getCell();
};

#endif // FIELD_H
