#ifndef LOSE_H
#define LOSE_H

#include <QDialog>

namespace Ui {
class Lose;
}

class Lose : public QDialog
{
    Q_OBJECT

public:
    explicit Lose(QWidget *parent = 0);
    ~Lose();

private:
    Ui::Lose *ui;
};

#endif // LOSE_H
