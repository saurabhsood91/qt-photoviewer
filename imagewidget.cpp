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
    //Enable the next button if not already enabled
    if(!this->nextButton->isEnabled()) {
        this->nextButton->setEnabled(true);
    }
}

void ImageWidget::nextClicked()
{
    //Increment index
    currentIndex++;
    //Load Image
    this->setImage(this->items.at(currentIndex));
    //If items equal to one less than length of items disable button
    if(currentIndex == this->items.length() - 1) {
        this->nextButton->setDisabled(true);
    }
    //Enable previous
    if(!this->previousButton->isEnabled()) {
        this->previousButton->setEnabled(true);
    }
}
