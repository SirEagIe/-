#include "Window.h"
#include <QApplication>
#include <QMenu>
#include <QMenuBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window *w = new Window;

    QMenu *fileMenu = new QMenu("&Меню");
    fileMenu->addAction("Н&астроки", w, SLOT(settings()));
    fileMenu->addAction("В&ыход", w, SLOT(close()));

    QMenuBar *mainMenu = new QMenuBar;
    mainMenu->addMenu(fileMenu);
    w->setMenuBar(mainMenu);

    w->show();
    return a.exec();
}
