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
    Crypto();
    virtual void ui(QHBoxLayout &layout);
    virtual void encode(Ui::MainWindow &ui);
    virtual void decode(Ui::MainWindow &ui);
    virtual ~Crypto();
private:
    QLabel *option_label;
};


class Cesar : public Crypto {
Q_OBJECT
public:
    Cesar();
    virtual void ui(QHBoxLayout &layout);
    virtual void encode(Ui::MainWindow &ui);
    virtual void decode(Ui::MainWindow &ui);
    virtual ~Cesar();
public slots:
    void currentTextHasChanged(QString value);
private:
    QLabel *description;
    QSpinBox *cesar_spin;
    QComboBox *predefined_combobox;
    string cypher(string text, int key);
    void combobox_set();
};



class Grid : public Crypto {
public:
	Grid();
    void size(int l);
private:
    int n = 0;
    int m = 0;
	int index = -1;
};

#endif // CRYPTO_H
