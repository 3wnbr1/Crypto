#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"

#include <QtWidgets/QSpinBox>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    cypher = new Cesar;
    cypher->ui(*ui->layout_options);
    this->statusBar()->showMessage("Cesar cypher selected");
}

MainWindow::~MainWindow() {
    delete cypher;
    delete ui;
}

void MainWindow::on_pushButton_encode_clicked() {
    cypher->encode(*ui);
}

void MainWindow::on_pushButton_decode_clicked() {
    cypher->decode(*ui);
}

void MainWindow::on_pushButton_inv_clicked() {
    QString text1 = ui->plainTextEdit_input->toPlainText();
    ui->plainTextEdit_input->document()->setPlainText(ui->plainTextEdit_output->toPlainText());
    ui->plainTextEdit_output->document()->setPlainText(text1);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow) {

}
