#include "micromouse.h"
#include "ui_micromouse.h"

Micromouse::Micromouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Micromouse)
{
    ui->setupUi(this);
}

Micromouse::~Micromouse()
{
    delete ui;
}

