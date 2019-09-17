#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Game::getInstance()->startNewGame(3, 2);
    view = new GraphicsView(Game::getInstance());
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
