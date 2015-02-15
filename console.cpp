#include "console.h"
#include "ui_console.h"

console::console(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::console)
{
    ui->setupUi(this);
}

console::~console()
{
    delete ui;
}
