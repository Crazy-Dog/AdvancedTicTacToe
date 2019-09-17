#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPen>

#include <array>

#include "game.h"
#include "line.h"

class Line;

/**
 * @brief The SquareXOrOItem class
 * using game->getPlayerColor() to set item color in checkForSides() method
 */

class SquareXOrOItem
{
public:
    SquareXOrOItem(int _x, int _y, int _size);
    virtual ~SquareXOrOItem();
    QGraphicsItem *getItem();
    void setToNotActive(bool state);
    bool checkForSides();
    bool isFilled() const;

    void setABSide(std::shared_ptr<Line> line);
    void setBCSide(std::shared_ptr<Line> line);
    void setCDSide(std::shared_ptr<Line> line);
    void setACSide(std::shared_ptr<Line> line);
private:
    int x, y, size;
    QPen *pen;
    bool filled; //unused yet

    QGraphicsItem *item;
    std::array<std::shared_ptr<Line>, 4> sides;
};
