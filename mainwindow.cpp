#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"


Cesar cypher;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->statusBar()->showMessage("Cesar cypher selected");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_encode_clicked() {
    int key = ui->spinBox->value();
    string text = cypher.encode(ui->plainTextEdit_2->toPlainText().toStdString(), key);
    QString coded = QString::fromStdString(text);
    ui->plainTextEdit->document()->setPlainText(coded);
}

void MainWindow::on_pushButton_decode_clicked() {
    int key = ui->spinBox->value();
    string text = cypher.decode(ui->plainTextEdit_2->toPlainText().toStdString(), key);
    QString coded = QString::fromStdString(text);
    ui->plainTextEdit->document()->setPlainText(coded);
}

void MainWindow::on_pushButton_inv_clicked() {
    QString text1 = ui->plainTextEdit_2->toPlainText();
    ui->plainTextEdit_2->document()->setPlainText(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit->document()->setPlainText(text1);
}

void MainWindow::on_listWidget_currentTextChanged(const QString &currentText) {

}
