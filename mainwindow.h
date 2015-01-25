#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QMenuBar>
#include <QMenu>
#include "imagewidget.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);
private:
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAction;
    QAction *exitAction;
    QAction *aboutAction;

    ImageWidget *image;

    //List stores the retrieved images
    QStringList selectedImages;

private slots:
    void openFileDialog();

public slots:

};

#endif // MAINWINDOW_H
