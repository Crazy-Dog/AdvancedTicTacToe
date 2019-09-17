#ifndef GAME_H
#define GAME_H

#include <QColor>
#include <vector>

/**
 * @brief The Game class
 * Only one game at the same time
 * Singleton pattern
 */

class Game
{
    Game();
public:
    Game& operator=(const Game ) = delete;
    static Game *getInstance();

    void startNewGame(int _areaSize, unsigned long long _playersCount);
    int getAreaSize();
    QColor getPlayerColor() const;
    void nextPlayerTurn();
private:
    static Game *game;
    static std::vector<QColor> playersColors;

    int areaSize{3};
    unsigned long long playersCount{2};
    unsigned long long player{0};
};

#endif // GAME_H
