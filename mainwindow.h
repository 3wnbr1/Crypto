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

public slots:
    void on_pushButton_encode_clicked();
    void on_pushButton_decode_clicked();
    void on_pushButton_inv_clicked();

private slots:
    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
