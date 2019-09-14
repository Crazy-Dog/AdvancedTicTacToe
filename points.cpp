#include "points.h"

Points::Points(int &_areaSize, const int &_pointsStep)
{
    points.reset(new std::multimap<int, int>);

    if(_areaSize%2 == 0) _areaSize--;

    pixelArea.reset(new int{_areaSize * _pointsStep});
    areaSize.reset(new int{_areaSize});
    pointsStep.reset(new int{_pointsStep});

    calculatePointsCoords();
}

std::shared_ptr<std::multimap<int, int> > Points::getCalculatedPoints()
{
    return points;
}

void Points::calculatePointsCoords(bool isReversePass)
{
    if(isReversePass)
    {
        for(int yPointCount = (*areaSize - 1) / 2; yPointCount >= 0; yPointCount--)
        {
            int yCoord = *pixelArea - (yPointCount * (*pointsStep));
            calculateXsForY(yPointCount, yCoord);
        }
        return;
    }
    for(int yPointCount = 0; yPointCount <= (*areaSize - 1) / 2; yPointCount++)
    {
        int yCoord = yPointCount * (*pointsStep);
        calculateXsForY(yPointCount, yCoord);
    }
    calculatePointsCoords(true);
}

void Points::calculateXsForY(int yPointCount, int yCoord)
{
    int mid1 = (*pixelArea)/2 - (*pointsStep)/2;
    int mid2 = (*pixelArea)/2 + (*pointsStep)/2;
    for(int xPointCount = 0; xPointCount < (yPointCount * 2 + 2) / 2; xPointCount++)
    {
        int xCoord1 = mid1 - xPointCount * (*pointsStep);
        int xCoord2 = mid2 + xPointCount * (*pointsStep);
        points->insert(std::pair<int, int>(xCoord1, yCoord));
        points->insert(std::pair<int, int>(xCoord2, yCoord));
    }
}
