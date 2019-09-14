#include "squarexoroitem.h"

SquareXOrOItem::SquareXOrOItem(int _x, int _y, int _size)
{
    x = _x;
    y = _y;
    size = _size;
    pen = new QPen{Qt::gray};
    pen->setWidthF(2);
    filled = false;

    item = new QGraphicsRectItem(x + 2, y + 2, size - 4, size - 4);
}

SquareXOrOItem::~SquareXOrOItem()
{
    delete item;
}

QGraphicsItem *SquareXOrOItem::getItem()
{
    return item;
}

void SquareXOrOItem::setToNotActive(bool state)
{
    for(auto side : sides)
    {
        if(side->hasBothSquares())
        {
            side->setPermanent(state);
        }
    }
    if(item)
    {
        delete item;
    }
    item = new QGraphicsRectItem(x + 2, y + 2, size - 4, size - 4);
    (static_cast<QGraphicsRectItem*>(item))->setBrush(Qt::gray);
    pen->setWidthF(0);
    (static_cast<QGraphicsRectItem*>(item))->setPen(*pen);
    filled = state;
}

bool SquareXOrOItem::checkForSides()
{
    bool isFourSidesPermanent = true;
    for(auto side : sides)
    {
        if(!side->isPermanentSet())
        {
            isFourSidesPermanent = false;
            break;
        }
    }
    if(isFourSidesPermanent)
    {
        (static_cast<QGraphicsRectItem*>(item))->setBrush(Qt::gray);
        pen->setWidthF(0);
        (static_cast<QGraphicsRectItem*>(item))->setPen(*pen);
        (static_cast<QGraphicsRectItem*>(item))->update();
        filled = true;
    }
    return isFourSidesPermanent;
}

bool SquareXOrOItem::isFilled() const
{
    return filled;
}

void SquareXOrOItem::setABSide(std::shared_ptr<Line> line)
{
    sides[0] = line;
}

void SquareXOrOItem::setBCSide(std::shared_ptr<Line> line)
{
    sides[1] = line;
}

void SquareXOrOItem::setCDSide(std::shared_ptr<Line> line)
{
    sides[2] = line;
}

void SquareXOrOItem::setACSide(std::shared_ptr<Line> line)
{
    sides[3] = line;
}
