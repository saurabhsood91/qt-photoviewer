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

    //disable previous and next buttons
    previousButton->setDisabled(true);
    nextButton->setDisabled(true);

    //Create Layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(previousButton);
    mainLayout->addWidget(imageView);
    mainLayout->addWidget(nextButton);

    connect(previousButton, SIGNAL(clicked()), this, SLOT(previousClicked()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextClicked()));

    this->currentIndex = 0;

    setLayout(mainLayout);

    this->show();

}

void ImageWidget::setImage(QString path)
{
    imageScene->addPixmap(QPixmap(path));
    imageView->setScene(imageScene);
    this->imageView->fitInView(imageScene->sceneRect(), Qt::KeepAspectRatio);

    if(this->items.length() > 1) {
        this->previousButton->setEnabled(true);
        this->nextButton->setEnabled(true);
    }

    if(currentIndex == 0) {
        this->previousButton->setDisabled(true);
        if(currentIndex == this->items.length() - 1) {
            this->nextButton->setDisabled(true);
        }
    } else if(currentIndex == this->items.length() - 1) {
        this->nextButton->setDisabled(true);
        if(currentIndex == 0) {
            this->previousButton->setDisabled(true);
        }
    }
}

void ImageWidget::updateFileList(QStringList list)
{
    this->items = list;
}

void ImageWidget::previousClicked()
{
    //If current index is 1, then disable the previous button as well
    if(currentIndex == 1) {
        this->previousButton->setDisabled(true);
    }
    currentIndex--;
    this->setImage(this->items.at(currentIndex));
}

void ImageWidget::nextClicked()
{
    //Increment index
    currentIndex++;
    //Load Image
    this->setImage(this->items.at(currentIndex));
}
