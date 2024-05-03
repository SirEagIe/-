#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmap>
#include "Field.h"
#include "Controller.h"

class Window : public QMainWindow {
    Q_OBJECT
    int settingW;
    int settingH;
    int settingBomb;
    Field* field;
    QPixmap *pixmapPaint;
    Controller* controller;
public:
    Window();
    ~Window();
    void restart();
    void restart(int, int, int);
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
public slots:
    void settings();
    void slotRestart();
    void slotRestart1();
    void slotRestart2();
    void slotRestart3();
};

#endif // WINDOW_H
