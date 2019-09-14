#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    setScene(scene);
    scene->setBackgroundBrush(QBrush(Qt::black,Qt::BrushStyle::SolidPattern));

    int areaSize = 5;

    guiElements.reset(new GuiElements(areaSize, pointsStep));
    auto lines = guiElements->getLines();
    auto squares = guiElements->getSquares();

    for(auto line : lines)
    {
        scene->addItem(line.get());
    }
    for(auto square : squares)
    {
        scene->addItem(square->getItem());
        //connect(square.get(), SIGNAL(SquareXOrOItem::addItem(QGraphicsItem*)), this, SLOT(addToScene(QGraphicsItem*)));
    }
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QGraphicsView::mousePressEvent(event);
    }
}

void GraphicsView::addToScene(QGraphicsItem *item)
{
    scene->addItem(item);
}




