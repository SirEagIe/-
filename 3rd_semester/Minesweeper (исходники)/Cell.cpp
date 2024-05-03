#include "Cell.h"
#include <QPainter>
#include <QPixmap>
#include "Window.h"

Cell::Cell()
{
    _isOpen = false;
    _isMarked = false;
}

Cell::~Cell() {;}

void Cell::mark()
{
    if(!_isOpen && !_isMarked)
        _isMarked = true;
    else
        _isMarked = false;
}

void Cell::open()
{
    _isOpen = true;
}

bool Cell::isEmpty()
{
    return false;
}

bool Cell::isNumber()
{
    return false;
}

bool Cell::isBomb()
{
    return false;
}

bool Cell::isOpen()
{
    return _isOpen;
}

bool Cell::isMarked()
{
    return _isMarked;
}

bool CellEmpty::isEmpty()
{
    return true;
}

void CellEmpty::draw(QPixmap* windowPixmap, int num, int width)
{
    QPixmap *pixmap;
    if(this->_isOpen)
        pixmap = new QPixmap(".\\assets\\1.png");
    else if(this->_isMarked)
        pixmap = new QPixmap(".\\assets\\11.png");
    else
        pixmap = new QPixmap(".\\assets\\12.png");
    QPainter p(windowPixmap);
    p.drawPixmap((num%width)*25, (num/width)*25, 25, 25, *pixmap);
    delete pixmap;
}

bool CellNumber::isNumber()
{
    return true;
}

void CellNumber::draw(QPixmap* windowPixmap, int num, int width)
{
    QPixmap *pixmap;
    if(this->_isOpen)
    {
        QString strNum = QString::number(this->number + 1);
        pixmap = new QPixmap(".\\assets\\"+strNum+".png");
    }
    else if(this->_isMarked)
        pixmap = new QPixmap(".\\assets\\11.png");
    else
        pixmap = new QPixmap(".\\assets\\12.png");
    QPainter p(windowPixmap);
    p.drawPixmap((num%width)*25, (num/width)*25, 25, 25, *pixmap);
    delete pixmap;
}

CellNumber::CellNumber(int num)
{
    this->number = num;
}

bool CellBomb::isBomb()
{
    return true;
}

void CellBomb::draw(QPixmap* windowPixmap, int num, int width)
{
    QPixmap *pixmap;
    if(this->_isOpen)
        pixmap = new QPixmap(".\\assets\\10.png");
    else if(this->_isMarked)
        pixmap = new QPixmap(".\\assets\\11.png");
    else
        pixmap = new QPixmap(".\\assets\\12.png");
    QPainter p(windowPixmap);
    p.drawPixmap((num%width)*25, (num/width)*25, 25, 25, *pixmap);
    delete pixmap;
}
