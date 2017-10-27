#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[]) {
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);

	QTranslator translator;
	translator.load("cryptor_fr");
	app.installTranslator(&translator);

	MainWindow window;
	window.show();
	return app.exec();
}
