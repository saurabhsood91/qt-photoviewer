#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
    void setImage(QString path);

private:
    //UI Elements
    QGraphicsView *imageView;
    QGraphicsScene *imageScene;
    QPushButton *previousButton;
    QPushButton *nextButton;

signals:

public slots:

};

#endif // IMAGEWIDGET_H
