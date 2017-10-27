#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"

#include <QApplication>
#include <QtWidgets/QSpinBox>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	setup_cryptoList();
	cypher = new Crypto(*ui);
	cypher->ui(*ui->layout_options);
	this->statusBar()->showMessage(tr("Welcome to AGSE Crypto"));
}

void MainWindow::setup_cryptoList() {
	cryptoList << tr("César") << tr("Grid") << tr("Morse") << tr("Numeric");
	ui->listWidget->addItems(cryptoList);
}

MainWindow::~MainWindow() {
	delete cypher;
	delete ui;
}

void MainWindow::on_pushButton_encode_clicked() {
	cypher->encode();
}

void MainWindow::on_pushButton_decode_clicked() {
	cypher->decode();
}

void MainWindow::on_pushButton_inv_clicked() {
	QString text1 = ui->plainTextEdit_input->toPlainText();
	ui->plainTextEdit_input->document()->setPlainText(ui->plainTextEdit_output->toPlainText());
	ui->plainTextEdit_output->document()->setPlainText(text1);
}

void MainWindow::on_listWidget_currentTextChanged(const QString &currentText) {
	delete cypher;
	if (currentText == tr("César")) {
		cypher = new Cesar(*ui);
	} else if (currentText == tr("Grid")) {
		cypher = new Grid(*ui);
	} else if (currentText == tr("Numeric")) {
		cypher = new Numeric(*ui);
	} else {
		cypher = new Crypto(*ui);
	}
	cypher->ui(*ui->layout_options);
	this->statusBar()->showMessage(currentText + tr(" selected"));
}
