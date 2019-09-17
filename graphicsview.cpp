#include "graphicsview.h"

GraphicsView::GraphicsView(Game *game, QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene;
    setScene(scene);
    scene->setBackgroundBrush(QBrush(Qt::black,Qt::BrushStyle::SolidPattern));

    guiElements.reset(new GuiElements(game->getAreaSize(), pointsStep));
    auto lines = guiElements->getLines();
    auto squares = guiElements->getSquares();

    for(auto line : lines)
    {
        scene->addItem(line.get());
    }
    for(auto square : squares)
    {
        scene->addItem(square->getItem());
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




