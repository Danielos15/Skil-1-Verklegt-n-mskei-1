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
    bool isSure() const;
    void setLabel(QString newLabel);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::areyousure *ui;
    bool sure;
};

#endif // AREYOUSURE_H
