#include "crypto.h"
#include <stdio.h>
#include <cmath>
#include "mainwindow.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QMessageBox>



Crypto::Crypto(Ui::MainWindow &ui) : QObject() {
	mainwindowUi = &ui;
	option_label = new QLabel;
}

void Crypto::ui(QHBoxLayout &layout) {
	while (layout.count() != 0) { layout.removeItem(layout.takeAt(0));}
	option_label->setText(tr("No Options avalaible"));
	layout.addWidget(option_label);
	layout.update();
}

void Crypto::encode() {
	mainwindowUi->plainTextEdit_output->document()->setPlainText(tr("Cannot encode"));
}

void Crypto::decode() {
	mainwindowUi->plainTextEdit_output->document()->setPlainText(tr("Cannot decode"));
}

Crypto::~Crypto() {
	delete option_label;
}


//////////////////////////
///    CESAR CYPHER    ///
//////////////////////////


Cesar::Cesar(Ui::MainWindow &ui) : Crypto(ui) {
	mainwindowUi = &ui;
	description = new QLabel;
	cesar_spin = new QSpinBox;
	predefined_combobox = new QComboBox;
}

void Cesar::ui(QHBoxLayout &layout) {
	while (layout.count() != 0) { layout.removeItem(layout.takeAt(0));}
	description->setText(tr("Cesar padding"));
	layout.addWidget(description);
	layout.addWidget(cesar_spin);
	layout.addWidget(predefined_combobox);
	layout.update();
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

void Cesar::encode() {
	int key = cesar_spin->value();
	string in = mainwindowUi->plainTextEdit_input->toPlainText().toStdString();
	string out = cypher(in, key);
	mainwindowUi->plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Cesar::decode() {
	int key = (26 - cesar_spin->value()) % 26;
	string in = mainwindowUi->plainTextEdit_input->toPlainText().toStdString();
	string out = cypher(in, key);
	mainwindowUi->plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Cesar::combobox_set() {
	predefined_combobox->addItems({tr("custom"),"Avocat", "Bande dessinée", "Déesse", "Elle aime", "Escalier", "Hachette", "Hélène", "Hervé", "Hier", "Idée", "Oeuf pourri", "Pays", "QG", "TV", "WC"});
}

void Cesar::currentTextHasChanged(QString value) {
	if (value == tr("custom")) {
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
		} else if (value == "Déesse") {
			cesar_spin->setValue(11);
		} else if (value == "Elle aime") {
			cesar_spin->setValue(25);
		} else if (value == "Escalier") {
			cesar_spin->setValue(8);
		} else if (value == "Hachette") {
			cesar_spin->setValue(14);
		} else if (value == "Hélène") {
			cesar_spin->setValue(24);
		} else if (value == "Hervé") {
			cesar_spin->setValue(22);
		} else if (value == "Hier") {
			cesar_spin->setValue(17);
		} else if (value == "Idéee") {
			cesar_spin->setValue(21);
		} else {
			QMessageBox::critical(mainwindowUi->centralWidget, "This is a bug", "This is a bug\nPlease report bug with cesar selector for value = " + value);
		}
	}
}

Cesar::~Cesar() {
	delete cesar_spin;
	delete predefined_combobox;
	delete description;
}


//////////////////////////
///  CHIFFERS CYPHER  ////
//////////////////////////


Numeric::Numeric(Ui::MainWindow &ui) : Crypto(ui) {
	mainwindowUi = &ui;
	description = new QLabel;
	cesar_spin = new QSpinBox;
	predefined_combobox = new QComboBox;
}

void Numeric::ui(QHBoxLayout &layout) {
	while (layout.count() != 0) { layout.removeItem(layout.takeAt(0));}
	description->setText(tr("Numeric padding"));
	layout.addWidget(description);
	layout.addWidget(cesar_spin);
	layout.addWidget(predefined_combobox);
	layout.update();
	combobox_set();
	QObject::connect(predefined_combobox, SIGNAL(currentTextChanged(QString)), this, SLOT(currentTextHasChanged(QString)));
}

string Numeric::cypher(string text, int key) {
	int n = text.size();
	string output;
	for (int i = 0; i <= n; i++) {
		if (isalpha(text[i])) {
			output += to_string(((int(tolower(text[i])) - 96) % 27 + key) % 27) + " ";
		} else {
			output += text[i];
		}
	}
	return output;
}

void Numeric::encode() {
	int key = cesar_spin->value();
	string in = mainwindowUi->plainTextEdit_input->toPlainText().toStdString();
	string out = cypher(in, key);
	mainwindowUi->plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Numeric::decode() {
	int key = (26 - cesar_spin->value()) % 26;
	string in = mainwindowUi->plainTextEdit_input->toPlainText().toStdString();
	string out = cypher(in, key);
	mainwindowUi->plainTextEdit_output->document()->setPlainText(QString::fromStdString(out));
}

void Numeric::combobox_set() {
	predefined_combobox->addItems({tr("custom"),"Avocat"});
}

void Numeric::currentTextHasChanged(QString value) {
	if (value == tr("custom")) {
		cesar_spin->setEnabled(true);
	} else {
		cesar_spin->setEnabled(false);
		if (value == "Avocat") {
			cesar_spin->setValue(16);
		} else {
			QMessageBox::critical(mainwindowUi->centralWidget, "This is a bug", "This is a bug\nPlease report bug with numeric selector for value = " + value);
		}
	}
}

Numeric::~Numeric() {
	delete cesar_spin;
	delete predefined_combobox;
	delete description;
}


///////////////////////////
/// CUSTOM MORSE CYPHER ///
///////////////////////////


Morse::Morse(Ui::MainWindow &ui) : Crypto(ui) {

}

void Morse::ui(QHBoxLayout &layout) {
	while (layout.count() != 0) { layout.removeItem(layout.takeAt(0));}
	layout.update();
}

string Morse::cypher(string text) {
	return text;
}

void Morse::encode() {

}

void Morse::decode() {

}

Morse::~Morse() {

}




//////////////////////////
/// CUSTOM GRID CYPHER ///
//////////////////////////


Grid::Grid(Ui::MainWindow &ui) : Crypto(ui) {
	mainwindowUi = &ui;
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
