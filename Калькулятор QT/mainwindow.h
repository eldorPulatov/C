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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void math_operations();
    void sqrt();
    void on_pushButton_AC_clicked();
    void on_pushButton_equal_clicked();

private:
    Ui::MainWindow *ui;    
};

#endif // MAINWINDOW_H
