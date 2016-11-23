#include "crm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    crm w;
    w.show();

    return a.exec();
}
