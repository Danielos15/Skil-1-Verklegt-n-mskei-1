#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "models/computer.h"
#include "models/scientist.h"
#include "services/computerservice.h"
#include "services/scientistservice.h"
#include "services/linkservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_sci_add_clicked();
    void on_button_cpu_add_clicked();
    void on_button_sci_edit_clicked();
    void on_button_cpu_edit_clicked();

    void on_input_sci_search_textChanged();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    void displayComputers(std::vector<Computer> computers);
    void displayScientists(std::vector<Scientist> scientists);

    ComputerService cpu_service;
    ScientistService sci_service;

    std::vector<Computer> computers;
    std::vector<Scientist> scientists;
};

#endif // MAINWINDOW_H
