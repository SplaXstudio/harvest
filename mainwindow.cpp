#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "console.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConsole_triggered()
{
    console *window;
    window = new console;
    window->show();
}
