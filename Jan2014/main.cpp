#include <iostream>
#include <vector>
#include <QApplication>
#include "form.h"

#include <worldobject.h>
#include <person.h>
#include <relationship.h>
#include <controller.h>




using namespace std;

int main(int argc, char *argv[])
{
    Controller::Instance()->doThings();

    QApplication a(argc, argv);
    Form w;
    w.show();

return a.exec();
}
