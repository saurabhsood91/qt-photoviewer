#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QMenuBar>
#include <QMenu>

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);
private:
    QMenuBar *menuBar;
    QMenu *fileMenu;

signals:

public slots:

};

#endif // MAINWINDOW_H
