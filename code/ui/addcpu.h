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

    bool shouldSave() const;
    std::string getName() const;
    int getType() const;
    int getYearBuilt() const;
    bool getWasBuilt() const;
    std::string getInfo() const;

private slots:

    void on_button_ok_clicked();
    void on_button_cancel_clicked();

private:
    Ui::addcpu *ui;

    std::string name;
    int type;
    int yearBuilt;
    bool wasBuilt;
    std::string info;

    bool save = false;
};

#endif // ADDCPU_H
