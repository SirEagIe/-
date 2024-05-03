#ifndef CELL_H
#define CELL_H

#include <QPixmap>

class Cell {
protected:
    bool _isOpen;
    bool _isMarked;
    int number;
public:
    Cell();
    virtual ~Cell();
    void open();
    void mark();
    virtual bool isEmpty();
    virtual bool isNumber();
    virtual bool isBomb();
    bool isOpen();
    bool isMarked();
    virtual void draw(QPixmap*, int, int) = 0;
};

class CellEmpty: public Cell {
public:
    bool isEmpty();
    void draw(QPixmap*, int, int);
};

class CellNumber: public Cell {
public:
    CellNumber(int);
    bool isNumber();
    void draw(QPixmap*, int, int);
};

class CellBomb: public Cell {
public:
    bool isBomb();
    void draw(QPixmap*, int, int);
};

#endif // CELL_H
