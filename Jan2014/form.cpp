#include "form.h"
#include "ui_form.h"
#include "controller.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    controller = Controller::Instance();
    controller->doThings();
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}
