#include "Controller.h"
#include "Field.h"

Controller::Controller()
{
    _isGameOver = false;
    _isWin = false;
}

void Controller::open(int x, int y, Field* field)
{
    if(field->getCell()[x*field->width()+y]->isMarked())
        return;
    looseCheck(x, y, field);
    if(_isGameOver)
        return;
    field->getCell()[x*field->width()+y]->open();
    if(field->getCell()[x*field->width()+y]->isEmpty()) {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                if((x+i) > -1 && (x+i) < field->height() && (y+j) > -1 && (y+j) < field->width() && !(field->getCell()[(x+i)*field->width()+(y+j)]->isBomb()) && !(field->getCell()[(x+i)*field->width()+(y+j)]->isOpen()))
                    open(x+i, y+j, field);
            }
        }
    }
    winCheck(field);
}

void Controller::mark(int x, int y, Field* field)
{
    field->getCell()[x*field->width()+y]->mark();
    winCheck(field);
}

bool Controller::isGameOver()
{
    return _isGameOver;
}

bool Controller::isWin()
{
    return _isWin;
}

void Controller::winCheck(Field* field)
{
    bool winFlag = 1;
    for(int i = 0; i < field->width()*field->height(); i++)
    {
        if((!field->getCell()[i]->isBomb() && !field->getCell()[i]->isOpen()) || (field->getCell()[i]->isBomb() && !field->getCell()[i]->isMarked()))
            winFlag = 0;
    }
    if(winFlag == 1)
    {
        _isGameOver = true;
        _isWin = true;
    }
}

void Controller::looseCheck(int x, int y, Field* field)
{
    if(field->getCell()[x*field->width()+y]->isBomb())
    {
        _isGameOver = true;
        for(int i = 0; i < field->width()*field->height(); i++)
            if(field->getCell()[i]->isBomb())
                field->getCell()[i]->open();
    }
}
