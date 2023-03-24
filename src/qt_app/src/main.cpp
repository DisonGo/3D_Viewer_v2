#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     const QString style_file_path = "home/mortalan/Documents/3D_Viewer-develop_mortalan/src/qt_app/style/style.qss";
    MainWindow w;
    StyleLoader *style_loader = new StyleLoader(&w, style_file_path);
    style_loader->attach();
    w.show();
    return a.exec();
}
