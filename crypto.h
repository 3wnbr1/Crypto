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

class Crypto {
public:
    Crypto();
    void ui(QHBoxLayout &layout);
    void encode(Ui::MainWindow &ui);
    void decode(Ui::MainWindow &ui);
private:
    QLabel *option_label;
};


class Cesar : public Crypto {
public:
    Cesar();
    void ui(QHBoxLayout &layout);
    string cypher(string text, int key);
    void encode(Ui::MainWindow &ui);
    void decode(Ui::MainWindow &ui);
private:
    QLabel *description;
    QSpinBox *cesar_spin;
    QComboBox *predefined_combobox;
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
