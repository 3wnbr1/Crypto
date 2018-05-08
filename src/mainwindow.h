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
    void setup_connections();
    ~MainWindow();

public slots:
    void on_pushButton_encode_clicked();
    void on_pushButton_decode_clicked();
    void on_pushButton_inv_clicked();
    void on_listWidget_currentTextChanged(const QString &currentText);
    void on_actionAboutQt(bool toogled);
    void on_actionAbout(bool toogled);


private:
    Ui::MainWindow *ui;
    Crypto *cypher;
    QList<QString> cryptoList;
};

#endif // MAINWINDOW_H
