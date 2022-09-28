#include "mainwindow.h"

#include <unistd.h>
#include <iostream>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //quit.resize(300, 300);
    //quit.show();
    return a.exec();
}
