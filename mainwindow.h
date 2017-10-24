#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crypto.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setup_cryptoList();
    ~MainWindow();

public slots:
    void on_pushButton_encode_clicked();
    void on_pushButton_decode_clicked();
    void on_pushButton_inv_clicked();
    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;
    Crypto *cypher;
    QList<QString> cryptoList;
};

#endif // MAINWINDOW_H
