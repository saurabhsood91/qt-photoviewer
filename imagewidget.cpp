#include "imagewidget.h"
#include <QHBoxLayout>

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    //Create UI Widgets
    imageScene = new QGraphicsScene;
    imageView = new QGraphicsView(imageScene);
    previousButton = new QPushButton(tr("<"));
    nextButton = new QPushButton(tr(">"));

    //Create Layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(previousButton);
    mainLayout->addWidget(imageView);
    mainLayout->addWidget(nextButton);

    setLayout(mainLayout);

    this->show();

}

void ImageWidget::setImage(QString path)
{
    imageScene->addPixmap(QPixmap(path));
    imageView->setScene(imageScene);
}
