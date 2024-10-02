#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Illusions");
    w.setWindowState(Qt::WindowFullScreen);
    w.setFixedSize(1080, 1200);
    w.show();
    return a.exec();
}
