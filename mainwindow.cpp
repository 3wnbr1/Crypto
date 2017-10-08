#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"


Grid cypher;


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

void MainWindow::on_pushButton_encode_clicked()
{
    string coded = cypher.encode("HELLO");
    qInfo("ENCODE");
}

void MainWindow::on_pushButton_decode_clicked()
{

}
