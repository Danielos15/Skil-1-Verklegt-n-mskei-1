#ifndef ADDCPU_H
#define ADDCPU_H

#include <QDialog>

namespace Ui {
class addcpu;
}

class addcpu : public QDialog
{
    Q_OBJECT

public:
    explicit addcpu(QWidget *parent = 0);
    ~addcpu();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addcpu *ui;
};

#endif // ADDCPU_H
