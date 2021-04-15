#include <QApplication>

#include "mainwindow.h"


int main(int argc, char** argv)
{
    QApplication* app = new QApplication(argc, argv);

    MainWindow window{nullptr};
    window.show();
    return app->exec();
}

