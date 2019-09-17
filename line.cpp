#include "line.h"

Line::Line(int _x1, int _y1, int _x2, int _y2) : QGraphicsItem()
{
    x1 = std::min(_x1, _x2);
    x2 = std::max(_x1, _x2);
    y1 = std::min(_y1, _y2);
    y2 = std::max(_y1, _y2);
    w = std::abs(x1 - x2);
    h = std::abs(y1 - y2);
    pen = new QPen{Qt::gray};
    pen->setWidthF(2);

    setAcceptHoverEvents(true);
}

QRectF Line::boundingRect() const
{
    qreal pw = std::max(h,w) / 2;
    return QRectF(x1 - pw/2, y1 - pw/2, w + pw, h + pw);

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(*pen);
    painter->drawLine(x1, y1, x2, y2);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Line::setPermanent(bool state)
{
    isPermanent = state;
    if(state)
    {
        pen->setWidthF(4);
        pen->setColor(Qt::green);
    }
    else
    {
        pen->setWidthF(2);
        pen->setColor(Qt::gray);
    }
    update();
}

void Line::setFirstSquare(std::shared_ptr<SquareXOrOItem> square)
{
    squares.first = square;
}

void Line::setSecondSquare(std::shared_ptr<SquareXOrOItem> square)
{
    squares.second = square;
}

int Line::getX() const
{
    return x1;
}

int Line::getY() const
{
    return y1;
}

bool Line::operator<(const Line &line) const
{
    if(x1 == line.x1 && y1 < line.y1)
    {
        return true;
    }
    if(x1 < line.x1 && y1 == line.y1)
    {
        return true;
    }
    if(x2 == line.x2 && y2 < line.y2)
    {
        return true;
    }
    if(x2 < line.x2 && y2 == line.y2)
    {
        return true;
    }

    return false;
}

bool Line::operator==(const Line &line) const
{
    if((x1 == line.x1 && y1 == line.y1) && (x2 == line.x2 && y2 == line.y2))
    {
        return true;
    }
    return false;
}

bool Line::isPermanentSet() const
{
    return isPermanent;
}

bool Line::isHorizontal() const
{
    if(y1 == y2) return true;
    return false;
}

bool Line::hasBothSquares() const
{
    if(squares.first && squares.second) return true;
    return false;
}

void Line::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    if(!isPermanent)
    {
        pen->setWidthF(4);
        pen->setColor(Qt::white);
        update();
    }
}

void Line::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event)
    if(!isPermanent)
    {
        pen->setWidthF(2);
        pen->setColor(Qt::gray);
        update();
    }
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(!isPermanent)
        {
            isPermanent = true;
            pen->setWidthF(4);
            pen->setColor(Qt::green);
            update();
            if(squares.first->checkForSides())
            {
                squares.second->checkForSides();
                return;
            }
            else if(squares.second->checkForSides())
            {
                return;
            }
            Game::getInstance()->nextPlayerTurn();
        }
    }
}
