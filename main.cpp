#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    mainwindow* window = new mainwindow();
    return app.exec();
}
