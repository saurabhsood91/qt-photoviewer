#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QPushButton>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
    void setImage(QString path);
    void updateFileList(QStringList list);

private:
    //UI Elements
    QGraphicsView *imageView;
    QGraphicsScene *imageScene;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QStringList items;
    int currentIndex;

    void resizeEvent(QResizeEvent*e);

private slots:
    void previousClicked();
    void nextClicked();

};

#endif // IMAGEWIDGET_H
