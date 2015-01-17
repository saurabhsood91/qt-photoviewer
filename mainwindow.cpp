#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create UI
    menuBar = new QMenuBar();
    fileMenu = new QMenu(tr("File"));
    menuBar->addMenu(fileMenu);
    this->setMenuBar(menuBar);

    //Set Window Title
    this->setWindowTitle(tr("Photo Viewer"));

    this->show();
}
