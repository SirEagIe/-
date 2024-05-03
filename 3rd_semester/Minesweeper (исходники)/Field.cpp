#include "Field.h"
#include "Cell.h"
#include "Window.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Field::Field(int width, int height, int numBomb)
{
    _width = width;
    _height = height;
    _numBomb = numBomb;
    cell = new Cell*[_width*_height];
    for(int i = 0; i < _width*_height; i++)
    {
        cell[i] = new CellEmpty;
    }
}

Field::~Field()
{
    for(int i = 0; i < _width*_height; i++)
        delete cell[i];
    delete[] cell;
}

void Field::generate()
{
    srand(time(0));
    int bombCoord;
    for(int i = 0; i < _numBomb; i++)
    {
        bombCoord = rand()%(_width*_height);
        if(!cell[bombCoord]->isBomb())
        {
            delete cell[bombCoord];
            cell[bombCoord] = new CellBomb;
        }
        else
            i--;
    }
    int count;
    for(int i = 0; i < _height; i++)
    {
        for(int j = 0; j < _width; j++)
        {
            count = 0;
            if(cell[i*_width+j]->isEmpty())
            {
                if(i != 0 && cell[(i-1)*_width+j]->isBomb())
                    count++;
                if(i != _height-1 && cell[(i+1)*_width+j]->isBomb())
                    count++;
                if(j != 0 && cell[i*_width+(j-1)]->isBomb())
                    count++;
                if(j != _width-1 && cell[i*_width+(j+1)]->isBomb())
                    count++;
                if(i != 0 && j != 0 && cell[(i-1)*_width+(j-1)]->isBomb())
                    count++;
                if(i != _height-1 && j != 0 && cell[(i+1)*_width+(j-1)]->isBomb())
                    count++;
                if(i != 0 && j != _width-1 && cell[(i-1)*_width+(j+1)]->isBomb())
                    count++;
                if(i != _height-1 && j != _width-1 && cell[(i+1)*_width+(j+1)]->isBomb())
                    count++;
            }
            if(count > 0)
            {
                delete cell[i*_width+j];
                cell[i*_width+j] = new CellNumber(count);
            }
        }
    }
}

void Field::draw(QPixmap* windowPixmap)
{
    for(int i = 0; i < _width*_height; i++)
        cell[i]->draw(windowPixmap, i, _width);
}

int Field::width()
{
    return _width;
}

int Field::height()
{
    return _height;
}

int Field::numBomb()
{
    return _numBomb;
}

Cell** Field::getCell()
{
    return cell;
}
