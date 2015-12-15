#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
