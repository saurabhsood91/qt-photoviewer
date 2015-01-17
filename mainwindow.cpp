#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create UI
    this->setMinimumSize(500, 500);
    //Adding Menubar
    menuBar = new QMenuBar();

    //Adding Menus
    fileMenu = new QMenu(tr("File"));
    helpMenu = new QMenu(tr("Help"));

    //Adding actions
    openAction = new QAction(tr("Open"), 0);
    exitAction = new QAction(tr("Exit"), 0);
    aboutAction = new QAction(tr("About"), 0);

    fileMenu->addAction(openAction);
    fileMenu->addAction(exitAction);
    helpMenu->addAction(aboutAction);

    //Adding the menus to the menubars
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);

    //Set the menubar to the mainwindow layout
    this->setMenuBar(menuBar);

    //Set Window Title
    this->setWindowTitle(tr("Photo Viewer"));

    //Signal Slot Connections
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    image = new ImageWidget;
    setCentralWidget(image);

    this->show();
}
