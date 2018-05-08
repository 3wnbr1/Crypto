#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[]) {
  #ifndef Q_OS_LINUX
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  #endif
	QApplication app(argc, argv);

	QTranslator translator;
	QString locale = QLocale::system().name().section('_', 0, 0);
	translator.load(":/cryptor_" + locale);
	app.installTranslator(&translator);

	MainWindow window;
	window.show();
	return app.exec();
}
