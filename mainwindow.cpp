#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view = new GraphicsView;
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
