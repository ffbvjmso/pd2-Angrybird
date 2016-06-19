#include "lose.h"
#include "ui_lose.h"

Lose::Lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lose)
{
    ui->setupUi(this);
}

Lose::~Lose()
{
    delete ui;
}
