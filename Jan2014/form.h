#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include "controller.h"
#include "worldinterpreter.h"


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

    void on_buttonItemInfo_released();

    void on_buttonItemAddDo_released();

    void on_buttonItemRemoveDo_released();

    void on_listWorldObjects_itemDoubleClicked();

    void on_buttonItemAddGet_released();

    void on_buttonItemRemoveGet_released();

    void on_buttonLocationInfo_released();

    void on_listLocations_itemDoubleClicked();

    void on_listLocationsGoTo_itemDoubleClicked(QListWidgetItem *item);

    void on_listLocationsComeFrom_itemDoubleClicked(QListWidgetItem *item);

    void on_listLocationsPeople_itemDoubleClicked(QListWidgetItem *item);

    void on_buttonAddRelationship_released();

    void on_buttonRemoveRelationship_released();

    void on_buttonTest_released();

    void on_policeRep_valueChanged(int arg1);

    void on_mobRep_valueChanged(int arg1);

    void on_policeWanted_valueChanged(int arg1);

    void on_mobWanted_valueChanged(int arg1);

    void on_storyRank_valueChanged(int arg1);

    void on_citizenCheckBox_toggled(bool checked);

private:
    Ui::Form *ui;
    Controller *controller;
    Person * current;
    WorldObject * currentItem;
    Location * currentLocation;
    WorldInterpreter interpreter;

    void updatePeople();
    void updateLocations();
    void updateItems();
    void updateActions();

    void refreshLocationTab();
    void refreshPersonTab();
};

#endif // FORM_H
