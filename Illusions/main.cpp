#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Illusions");
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    a.setOverrideCursor(Qt::BlankCursor);
    return a.exec();
}
