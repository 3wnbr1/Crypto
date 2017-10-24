#include "crypto.h"
#include <stdio.h>
#include <cmath>
#include "mainwindow.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>



Crypto::Crypto() : QObject() {
    option_label = new QLabel;
}

void Crypto::ui(QHBoxLayout &layout) {
    option_label->setText("No Options avalaible");
    layout.addWidget(option_label);
}

void Crypto::encode(Ui::MainWindow &ui) {
    ui.plainTextEdit_output->document()->setPlainText("Cannot encode");
}

void Crypto::decode(Ui::MainWindow &ui) {
    ui.plainTextEdit_output->document()->setPlainText("Cannot decode");
}

Crypto::~Crypto() {
    delete option_label;
}


//////////////////////////
///    CESAR CYPHER    ///
//////////////////////////


Cesar::Cesar() : Crypto() {
    description = new QLabel;
    cesar_spin = new QSpinBox;
    predefined_combobox = new QComboBox;
}

void Cesar::ui(QHBoxLayout &layout) {
    description->setText("Cesar padding ");
    layout.addWidget(description);
    layout.addWidget(cesar_spin);
    layout.addWidget(predefined_combobox);
    combobox_set();
    QObject::connect(predefined_combobox, SIGNAL(currentTextChanged(QString)), this, SLOT(currentTextHasChanged(QString)));
}

string Cesar::cypher(string text, int key) {
	int n = text.size();
	bool upper;
	for (int i = 0; i <= n; i++) {
		if (isalpha(text[i])) {
			if (isupper(text[i])) {
				upper = true;
			} else {
				upper = false;
			}
			text[i] = tolower(text[i]);
            if ((text[i] + key > 122)||(text[i] + key < 97)) {
				text[i] = (text[i] - 97) % 26;
				if (upper) {
                    text[i] = toupper((text[i] + key) % 26 + 97);
				} else {
                    text[i] = (text[i] + key) % 26 + 97;
				}
			} else {
				if (upper) {
                    text[i] = toupper(text[i] + key);
				} else {
                    text[i] += key;
				}
			}
		}
	}
	return text;
}

void Cesar::encode(Ui::MainWindow &ui) {
    int key = cesar_spin->value();
    string in = ui.plainTextEdit_input->toPlainText().toStdString();
    string out = Cesar::cypher(in, key);
    ui.plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Cesar::decode(Ui::MainWindow &ui) {
    int key = (26 - cesar_spin->value()) % 26;
    string in = ui.plainTextEdit_input->toPlainText().toStdString();
    string out = Cesar::cypher(in, key);
    ui.plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Cesar::combobox_set() {
    predefined_combobox->addItems({"custom","Avocat", "Bande dessinée", "Oeuf pourri", "Pays", "QG", "TV", "WC"});
}

void Cesar::currentTextHasChanged(QString nil) {
    QString value = predefined_combobox->currentText();
    if (value == "custom") {
        cesar_spin->setEnabled(true);
    } else {
        cesar_spin->setEnabled(false);
        if (value == "Avocat") {
            cesar_spin->setValue(16);
        } else if (value == "QG") {
            cesar_spin->setValue(10);
        } else if (value == "Pays") {
            cesar_spin->setValue(7);
        } else if (value == "WC") {
            cesar_spin->setValue(20);
        } else if ((value == "TV") || (value == "Bande dessinée")) {
            cesar_spin->setValue(24);
        } else if (value == "Oeuf pourri") {
            cesar_spin->setValue(22);
        }
    }
}

Cesar::~Cesar() {
    delete cesar_spin;
    delete predefined_combobox;
    delete description;
}


//////////////////////////
/// CUSTOM GRID CYPHER ///
//////////////////////////


Grid::Grid() {
	n = 0;
    m = 0;
	index = -1;
}

void Grid::size(int l) {
    n = sqrt(l);
    m = n;
	if (n*m < l) {
		m += 1;
	}
	while ((n*m - l) >= 0.2*l) {
		m += 1;
		while ((n-1)*m > l) {
            n -= 1;
		}
	}
}
