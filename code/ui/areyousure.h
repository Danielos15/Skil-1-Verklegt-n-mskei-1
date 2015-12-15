#ifndef AREYOUSURE_H
#define AREYOUSURE_H

#include <QDialog>

namespace Ui {
class areyousure;
}

class areyousure : public QDialog
{
    Q_OBJECT

public:
    explicit areyousure(QWidget *parent = 0);
    ~areyousure();

private:
    Ui::areyousure *ui;
};

#endif // AREYOUSURE_H
