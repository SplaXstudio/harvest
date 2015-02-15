#ifndef CONSOLE_H
#define CONSOLE_H

#include <QDialog>

namespace Ui {
class console;
}

class console : public QDialog
{
    Q_OBJECT

public:
    explicit console(QWidget *parent = 0);
    ~console();

private:
    Ui::console *ui;
};

#endif // CONSOLE_H
