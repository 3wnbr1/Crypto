#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
#include "ui_mainwindow.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>

using namespace std;
class Crypto : public QObject {
public:
    Crypto(Ui::MainWindow &ui);
    virtual void ui(QHBoxLayout &layout);
    virtual void encode();
    virtual void decode();
    virtual ~Crypto();
private:
    QLabel *option_label;
    Ui::MainWindow *mainwindowUi;
};


class Cesar : public Crypto {
Q_OBJECT
public:
    Cesar(Ui::MainWindow &ui);
    virtual void ui(QHBoxLayout &layout);
    virtual void encode();
    virtual void decode();
    virtual ~Cesar();
public slots:
    void currentTextHasChanged(QString value);
protected:
    QLabel *description;
    QSpinBox *cesar_spin;
    QComboBox *predefined_combobox;
    Ui::MainWindow *mainwindowUi;
    string cypher(string text, int key);
    void combobox_set();
};


class Numeric : public Crypto {
Q_OBJECT
public:
    Numeric(Ui::MainWindow &ui);
    virtual void ui(QHBoxLayout &layout);
    virtual void encode();
    virtual void decode();
    virtual ~Numeric();
public slots:
    void currentTextHasChanged(QString value);
protected:
    QLabel *description;
    QSpinBox *cesar_spin;
    QComboBox *predefined_combobox;
    Ui::MainWindow *mainwindowUi;
    string cypher(string text, int key);
    void combobox_set();
};


class Morse : public Crypto {
public:
    Morse(Ui::MainWindow &ui);
    virtual void ui(QHBoxLayout &layout);
    string cypher(string text);
    virtual void encode();
    virtual void decode();
    virtual ~Morse();
private:
    QLabel *option_label;
    Ui::MainWindow *mainwindowUi;
};


class Grid : public Crypto {
public:
    Grid(Ui::MainWindow &ui);
    void size(int l);
protected:
    Ui::MainWindow *mainwindowUi;
    int n = 0;
    int m = 0;
	int index = -1;
};

#endif // CRYPTO_H
