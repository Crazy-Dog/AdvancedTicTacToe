#ifndef GUIELEMENTS_H
#define GUIELEMENTS_H

#include "points.h"
#include "line.h"
#include "squarexoroitem.h"

/**
 * @brief The GuiElements class
 * lines count = (area size - 1)^2 + 4 * area size
 * squares count = sum(1 to (area size - 1) / 2) * 4 + 1
 */

class GuiElements
{
public:
    GuiElements(int _areaSize, int _pointsStep);
    std::vector<std::shared_ptr<Line> > getLines() const;
    std::vector<std::shared_ptr<SquareXOrOItem> > getSquares() const;
protected:
    bool lineExists(const Line &line);
    void initLines(std::shared_ptr<std::multimap<int, int> > points);
    void initSquares();
    void linkLinesAndSquares(std::shared_ptr<Line> line, std::shared_ptr<Line> opposite, std::shared_ptr<SquareXOrOItem> item);
    void setGameFieldBoundaries();
private:
    std::unique_ptr<int> pointsStep;
    std::unique_ptr<int> areaSize;

    std::vector<std::shared_ptr<Line> >  lines;
    std::vector<std::shared_ptr<SquareXOrOItem> >  squares;
};

#endif // GUIELEMENTS_H
