#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonValidate_clicked()
{
    if (ui->checkBoxRule1->isChecked())
    {
        QRegExp rx("^\\S{5,}$");

        if (rx.indexIn(ui->lineEditPassword->text()) == -1)
        {
            QMessageBox::warning(0,"Password invalid: ", "It must consist of a minimum of five characters and no spaces are allowed.");
        } else
        {
            QMessageBox::information(0,"Password valid. ", "No action needed");
        }

    } else if (ui->checkBoxRule2->isChecked())
    {
        QRegExp rx("^..[a-fA-F0-9].{2,2}$");

        if (rx.indexIn(ui->lineEditPassword->text()) == -1)
        {
            QMessageBox::warning(0,"Password invalid: ", "It must consist of 5 characters, where the third character can be either a digit or an alphabetic character (a-f or A-F).");
        } else
        {
            QMessageBox::information(0,"Password valid. ", "No action needed");
        }

    } else if (ui->checkBoxRule3->isChecked())
    {
        QRegExp rx("^[1-9][0-9]{3,5}$");

        if (rx.indexIn(ui->lineEditPassword->text()) == -1)
        {
            QMessageBox::warning(0,"Password invalid: ", "It must consist of a minimum of four and a maximum of six digits and the starting digit cannot be 0.");
        } else
        {
            QMessageBox::information(0,"Password valid. ", "No action needed");
        }
    }

}
