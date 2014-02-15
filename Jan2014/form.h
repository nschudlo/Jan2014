#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>
#include "controller.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    
private:
    Ui::Form *ui;
    Controller *controller;
};

#endif // FORM_H
