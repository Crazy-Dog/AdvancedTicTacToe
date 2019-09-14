#pragma once

#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>

#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <array>
#include <memory>
#include "squarexoroitem.h"

class SquareXOrOItem;

class Line : public QGraphicsItem
{
public:
    Line(int _x1, int _y1, int _x2, int _y2);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setPermanent(bool state);
    void setFirstSquare(std::shared_ptr<SquareXOrOItem> square);
    void setSecondSquare(std::shared_ptr<SquareXOrOItem> square);

    int getX() const;
    int getY() const;

    bool operator<(const Line &line) const;
    bool operator==(const Line &line) const;
    bool isPermanentSet() const;
    bool isHorizontal() const;
    bool hasBothSquares() const;
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private: 
    int x1, y1, x2, y2, w, h;
    QPen *pen;
    bool isPermanent{false};
    std::pair<std::shared_ptr<SquareXOrOItem>, std::shared_ptr<SquareXOrOItem> > squares;
};
