#ifndef GAME_H
#define GAME_H

#include <QColor>

// Only one game at the same time

class Game
{
    Game();
public:
    Game(const Game &) = delete;
    Game& operator=(const Game ) = delete;
    static Game *getInstance();

    void startNewGame(int areaSize, int playersCount);
    int getAreaSize();
    QColor getPlayerColor() const;
private:
    static Game *game;

    int areaSize{0};
};

#endif // GAME_H
