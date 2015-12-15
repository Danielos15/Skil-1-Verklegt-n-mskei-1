#ifndef ADDSCI_H
#define ADDSCI_H

#include <QDialog>

namespace Ui {
class addsci;
}

class addsci : public QDialog
{
    Q_OBJECT

public:
    explicit addsci(QWidget *parent = 0);
    ~addsci();

private:
    Ui::addsci *ui;
};

#endif // ADDSCI_H
