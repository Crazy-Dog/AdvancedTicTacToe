#include "game.h"

Game *Game::game = nullptr;

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

QColor Game::getPlayerColor() const
{
    return Qt::gray;
}
