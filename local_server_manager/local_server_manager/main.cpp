#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
  QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));

  QApplication a(argc, argv);
  MainWindow w;
  w.hide();

  return a.exec();
}
