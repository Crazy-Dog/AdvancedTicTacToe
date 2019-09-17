#include "game.h"

Game *Game::game = nullptr;
std::vector<QColor> Game::playersColors = {Qt::green, Qt::blue, Qt::white, Qt::yellow, Qt::red, Qt::magenta};

Game::Game()
{

}

Game *Game::getInstance()
{
    if(game == nullptr)
    {
        game = new Game;
    }
    return game;
}

void Game::startNewGame(int _areaSize,  unsigned long long _playersCount)
{

    areaSize = (_areaSize % 2 == 0) ? ++_areaSize : _areaSize;
    areaSize += 2;
    playersCount = _playersCount;
}

int Game::getAreaSize()
{
    return areaSize;
}

QColor Game::getPlayerColor() const
{
    return playersColors[player];
}

void Game::nextPlayerTurn()
{
    player = (player == playersCount - 1) ? 0 : player + 1;
}
