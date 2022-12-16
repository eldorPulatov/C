#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers())); // Соединение нажатие на кнопки с методом
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plusminus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_proc, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_times, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(sqrt()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_times->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_lable;

    if(ui->label_show->text().contains(".") && button->text() == "0"){
        new_lable = ui->label_show->text() + button->text();
    }
    else{
        all_numbers = (ui->label_show->text() + button->text()).toDouble();
        new_lable = QString::number(all_numbers, 'g', 15);
    }
    ui->label_show->setText(new_lable);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->label_show->text().contains('.'))
        ui->label_show->setText(ui->label_show->text() + ".");
}

void MainWindow::operations(){
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_lable;

    if(button->text() == "+/-"){
        all_numbers = (ui->label_show->text()).toDouble();
        if(all_numbers < 0)
            all_numbers *= -1;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label_show->setText(new_lable);
    }
    else if(button->text() == "%"){
        all_numbers = (ui->label_show->text()).toDouble();
        all_numbers *= 0.01;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label_show->setText(new_lable);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender(); //проверка на какую кнопку было нажато

    num_first = ui->label_show->text().toDouble();

    ui->label_show->setText("");

    button->setChecked(true);
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_times->setChecked(false);

    ui->label_show->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double label_number, num_second;

    QString new_lable;

    num_second = ui->label_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        label_number = num_first + num_second;
        new_lable = QString::number(label_number, 'g', 15);

        ui->label_show->setText(new_lable);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){
        label_number = num_first - num_second;
        new_lable = QString::number(label_number, 'g', 15);

        ui->label_show->setText(new_lable);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_del->isChecked()){
        if(num_second == 0){
            ui->label_show->setText("0");
        }
        else {
            label_number = num_first / num_second;
            new_lable = QString::number(label_number, 'g', 15);

            ui->label_show->setText(new_lable);
        }
        ui->pushButton_del->setChecked(false);
    }
    else if(ui->pushButton_times->isChecked()){
        label_number = num_first * num_second;
        new_lable = QString::number(label_number, 'g', 15);

        ui->label_show->setText(new_lable);
        ui->pushButton_times->setChecked(false);
    }
}

void MainWindow::sqrt(){
    double x = ui->label_show->text().toDouble();
    QString new_label;
    double s = 1;
    while(s*s < x)
        s++;
    new_label = QString::number(s, 'g', 15);
    ui->label_show->setText(new_label);
}
