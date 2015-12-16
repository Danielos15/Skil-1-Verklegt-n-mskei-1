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

    bool shouldSave() const;
    std::string getName() const;
    int getGender() const;
    int getBirth() const;
    int getDeath() const;
    std::string getInfo() const;

    void setName(std::string newName);
    void setGender(int newGender);
    void setYearBorn(int newYear);
    void setYearDeath(int newYear);
    void setInfo(std::string newInfo);

private slots:

    void on_button_ok_clicked();
    void on_button_cancel_clicked();

private:
    Ui::addsci *ui;

    std::string name;
    int gender;
    int yearBorn;
    int yearDeath;
    std::string info;

    bool save = false;
};

#endif // ADDSCI_H
