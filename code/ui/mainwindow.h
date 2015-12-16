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


    void on_actionAdd_Scientist_triggered();
    void on_actionAdd_Computer_triggered();
    void actionAdd_Relation_triggered();
    void on_actionExit_triggered();

    void on_input_sci_search_textChanged(const QString &arg1);
    void on_input_cpu_search_textChanged(const QString &arg1);

    void on_table_sci_view_clicked(const QModelIndex &index);

    void on_table_cpu_view_clicked(const QModelIndex &index);

    void on_button_sci_remove_clicked();

    void on_button_cpu_remove_clicked();

    void on_list_rel_sci_clicked(const QModelIndex &index);

    void on_list_rel_cpu_clicked(const QModelIndex &index);

    void on_input_sci_rel_search_textChanged(const QString &arg1);

    void on_input_rel_cpu_search_textChanged(const QString &arg1);

    void on_actionEdit_Scientist_triggered();

    void on_actionEdit_Computer_triggered();

    void on_button_rel_add_clicked();

    void on_list_rel_common_clicked();

    void on_button_rel_remove_clicked();

private:
    Ui::MainWindow *ui;

    void displayComputers(std::vector<Computer> computers);
    void displayScientists(std::vector<Scientist> scientists);

    void displayRelationComputers(std::vector<Computer> computers);
    void displayRelationScientists(std::vector<Scientist> scientists);

    void displayCommonComputers(std::vector<Computer> computers);
    void displayCommonScientists(std::vector<Scientist> scientists);

    ComputerService cpu_service;
    ScientistService sci_service;
    LinkRepository link_service;

    std::vector<Computer> computers;
    std::vector<Scientist> scientists;

    std::vector<Computer> relComputers;
    std::vector<Scientist> relScientists;

    std::vector<Computer> commonComputers;
    std::vector<Scientist> commonScientists;
};

#endif // MAINWINDOW_H
