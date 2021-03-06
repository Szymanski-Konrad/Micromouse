#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Micromouse; }
QT_END_NAMESPACE

class Micromouse : public QMainWindow
{
    Q_OBJECT

public:
    Micromouse(QWidget *parent = nullptr);
    ~Micromouse();

private:
    Ui::Micromouse *ui;
};
#endif // MICROMOUSE_H
