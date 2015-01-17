#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create UI

    //Adding Menubar
    menuBar = new QMenuBar();

    //Adding Menus
    fileMenu = new QMenu(tr("File"));
    helpMenu = new QMenu(tr("Help"));

    //Adding the menus to the menubars
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);

    //Set the menubar to the mainwindow layout
    this->setMenuBar(menuBar);

    //Set Window Title
    this->setWindowTitle(tr("Photo Viewer"));

    this->show();
}
