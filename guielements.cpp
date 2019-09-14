#include "guielements.h"

GuiElements::GuiElements(int _areaSize, int _pointsStep) : pointsStep(new int{_pointsStep}), areaSize(new int{_areaSize})
{
    std::unique_ptr<Points> points(new Points(*areaSize, *pointsStep));

    initLines(points->getCalculatedPoints());
    initSquares();

    setGameFieldBoundaries();
//    qInfo() << lines.size();
//    qInfo() << squares.size();
}

std::vector<std::shared_ptr<Line> > GuiElements::getLines() const
{
    return lines;
}

std::vector<std::shared_ptr<SquareXOrOItem> > GuiElements::getSquares() const
{
    return squares;
}

bool GuiElements::lineExists(const Line &line)
{
    for(auto lineIt : lines)
    {
        if(*lineIt == line)
        {
            return true;
        }
    }
    return false;
}

void GuiElements::initLines(std::shared_ptr<std::multimap<int, int> > points)
{
    for(auto [x1, y1] : *points)
    {
        for(auto [x2, y2] : *points)
        {
            if((x1 == x2 && std::abs(y1-y2) == *pointsStep) ||
                    (y1 == y2 && std::abs(x1-x2) == *pointsStep))
            {
                std::shared_ptr<Line> line{new Line(x1,y1,x2,y2)};
                if(!lineExists(*line))
                {
                    lines.push_back(line);
                }
            }
        }
    }
}

void GuiElements::initSquares()
{
    for(auto verticalLine : lines)
    {
        if(!verticalLine->isHorizontal())
        {
            for(auto oppositeVLine : lines)
            {
                if(*oppositeVLine == Line(verticalLine->getX() + (*pointsStep), verticalLine->getY(), verticalLine->getX() + (*pointsStep), verticalLine->getY() + (*pointsStep)))
                {
                    std::shared_ptr<SquareXOrOItem> item{new SquareXOrOItem(verticalLine->getX(), verticalLine->getY(), *pointsStep)};
                    linkLinesAndSquares(verticalLine, oppositeVLine, item);
                    break;
                }
            }
        }
    }
}

void GuiElements::linkLinesAndSquares(std::shared_ptr<Line> verticalLine, std::shared_ptr<Line> oppositeVLine, std::shared_ptr<SquareXOrOItem> item)
{
    for(auto horizontalLine : lines)
    {
        if(*horizontalLine == Line(verticalLine->getX(), verticalLine->getY(), verticalLine->getX() + (*pointsStep), verticalLine->getY()))
        {
            item->setABSide(horizontalLine);
            horizontalLine->setFirstSquare(item);
            break;
        }
    }
    for(auto horizontalLine : lines)
    {
        if(*horizontalLine == Line(verticalLine->getX(), verticalLine->getY() + (*pointsStep), verticalLine->getX() + (*pointsStep), verticalLine->getY() + (*pointsStep)))
        {
            item->setCDSide(horizontalLine);
            horizontalLine->setSecondSquare(item);
            break;
        }
    }
    item->setACSide(verticalLine);
    verticalLine->setFirstSquare(item);
    item->setBCSide(oppositeVLine);
    oppositeVLine->setSecondSquare(item);
    squares.push_back(item);
}

void GuiElements::setGameFieldBoundaries()
{
    for(auto line : lines)
    {
        if(!line->hasBothSquares())
        {
            line->setPermanent(true);
        }
    }
    squares[0]->setToNotActive(true);
    squares[squares.size() - 1]->setToNotActive(true);
    unsigned long long mid = (squares.size() - 1) / 2;
    unsigned long long d = static_cast<unsigned long long>((*areaSize - 1) / 2);
    squares[mid - d]->setToNotActive(true);
    squares[mid + d]->setToNotActive(true);
}
