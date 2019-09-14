#ifndef POINTS_H
#define POINTS_H

#include <map>
#include <memory>

#include <QDebug>

class Points
{
public:
    Points(int &_areaSize, const int &_pointsStep);
    bool isPointsForLines();
    std::shared_ptr<std::multimap<int, int> > getCalculatedPoints();
private:
    void calculatePointsCoords(bool isReversePass = false);
    void calculateXsForY(int yPointCount, int yCoord);

    std::unique_ptr<int> pixelArea;
    std::unique_ptr<int> areaSize;
    std::unique_ptr<int> pointsStep;
    std::shared_ptr<std::multimap<int, int> > points;
};

#endif // POINTS_H
