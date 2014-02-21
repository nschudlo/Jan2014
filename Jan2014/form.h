#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
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

    void updateLists();

    
private slots:
    void on_buttonUpdateLists_released();

    void on_buttonAddItem_released();

    void on_buttonPersonInfo_released();

    void on_personHealthInput_valueChanged(int arg1);

    void on_personMoneyInput_valueChanged(int arg1);

    void on_buttonRemoveItem_released();

    void on_listPeople_itemDoubleClicked();

    void on_personRelTypeInput_valueChanged(int arg1);

    void on_personRelStrengthInput_valueChanged(int arg1);

    void on_listPersonRelationship_currentRowChanged(int currentRow);

    void on_listPersonLocations_itemDoubleClicked(QListWidgetItem *item);

    void on_personMoodInput_valueChanged(int arg1);

private:
    Ui::Form *ui;
    Controller *controller;
    Person * current;

    void updatePeople();
    void updateLocations();
    void updateItems();
    void updateActions();
};

#endif // FORM_H
