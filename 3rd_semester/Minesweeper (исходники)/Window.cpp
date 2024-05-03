#include "Window.h"
#include "Field.h"
#include "Controller.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

Window::Window()
{
    settingW = 16;
    settingH = 16;
    settingBomb = 40;
    restart();
}

Window::~Window()
{
    delete field;
    delete controller;
}

void Window::restart()
{
    field = new Field(settingW, settingH, settingBomb);
    pixmapPaint = new QPixmap(25*field->width(), 25*field->height());
    setFixedSize(25*field->width(), 25*field->height()+21);
    controller = new Controller();
    field->generate();
    field->draw(this->pixmapPaint);
    repaint();
}

void Window::restart(int width, int height, int bombs)
{
    settingW = width;
    settingH = height;
    settingBomb = bombs;
    restart();
}

void Window::mouseReleaseEvent(QMouseEvent *event)
{
    if(!controller->isGameOver())
    {
        QPoint pos = QWidget::mapFromGlobal(QCursor::pos());
        if(event->button() == Qt::LeftButton) {
            if((pos.y()-21)/25 > -1 && (pos.y()-21)/25 < field->height() && pos.x()/25 > -1 && pos.x()/25 < field->width())
            {
                controller->open((pos.y()-21)/25, pos.x()/25, field);
            }
        }
        if(event->button() == Qt::RightButton) {
            if((pos.y()-21)/25 > -1 && (pos.y()-21)/25 < field->height() && pos.x()/25 > -1 && pos.x()/25 < field->width())
            {
                controller->mark((pos.y()-21)/25, pos.x()/25, field);
            }
        }
        field->draw(this->pixmapPaint);
        repaint();
        if(controller->isGameOver())
        {
            QDialog dialog;
            QLabel label;
            if(!controller->isWin())
                label.setText("Вы проиграли!");
            if(controller->isWin())
                label.setText("Вы победили!");
            QPushButton btnRestart("Перезапустить");
            connect(&btnRestart, SIGNAL(clicked()), &dialog, SLOT(close()));
            connect(&btnRestart, SIGNAL(clicked()), this, SLOT(slotRestart()));
            QPushButton btnClose("Выйти");
            connect(&btnClose, SIGNAL(clicked()), &dialog, SLOT(close()));
            connect(&btnClose, SIGNAL(clicked()), this, SLOT(close()));
            QHBoxLayout layout;
            layout.addWidget(&label);
            layout.addWidget(&btnRestart);
            layout.addWidget(&btnClose);
            dialog.setLayout(&layout);
            dialog.exec();
            delete field;
            delete controller;
            restart();
        }
    }
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 21, 25*field->width(), 25*field->height(), *this->pixmapPaint);
}

void Window::settings()
{
    QDialog dialog;
    QLabel label("Выберите сложность");
    QRadioButton btn1("Лёгко");
    QRadioButton btn2("Нормально");
    QRadioButton btn3("Сложно");
    QPushButton btnClose("Закрыть");
    connect(&btn1, SIGNAL(clicked()), this, SLOT(slotRestart1()));
    connect(&btn2, SIGNAL(clicked()), this, SLOT(slotRestart2()));
    connect(&btn3, SIGNAL(clicked()), this, SLOT(slotRestart3()));
    connect(&btnClose, SIGNAL(clicked()), &dialog, SLOT(close()));
    QVBoxLayout layout;
    layout.addWidget(&label);
    layout.addWidget(&btn1);
    layout.addWidget(&btn2);
    layout.addWidget(&btn3);
    layout.addWidget(&btnClose);
    dialog.setLayout(&layout);
    dialog.exec();
}

void Window::slotRestart()
{
    delete field;
    delete controller;
    restart();
}

void Window::slotRestart1()
{
    delete field;
    delete controller;
    restart(9, 9, 10);
}

void Window::slotRestart2()
{
    delete field;
    delete controller;
    restart(16, 16, 40);
}

void Window::slotRestart3()
{
    delete field;
    delete controller;
    restart(30, 16, 99);
}
