#ifndef GRAPHICVIEW_H
#define GRAPHICVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

#include <set>
#include <memory>
#include <vector>
#include <algorithm>

#include "guielements.h"
#include "squarexoroitem.h"
#include <QDebug>

class GraphicsView : public QGraphicsView
{
public:
    explicit GraphicsView(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
protected slots:
    void addToScene(QGraphicsItem *item);
private:
    QGraphicsScene *scene;
    std::unique_ptr<GuiElements> guiElements;
//    std::unique_ptr<Points> points;
//    std::shared_ptr<std::multimap<int, int> > self;

    static constexpr int pointsStep{32};
};

#endif // GRAPHICVIEW_H
