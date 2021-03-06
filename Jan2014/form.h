#ifndef FORM_H
#define FORM_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QListWidget>
#include "controller.h"
#include "worldinterpreter.h"
#include "director.h"
#include "evaluator.h"


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
    void on_storyRole_valueChanged(int arg1);
    void on_loadGoals_released();
    void on_loadStories_released();

    void on_listGoals_itemDoubleClicked(QListWidgetItem *item);

    void on_refreshStories_released();

    void on_refreshGoals_released();

    void on_listStories_itemDoubleClicked(QListWidgetItem *item);

    void on_updateCurrentGoalsButton_released();

    void on_updateCurrentStoriesButton_released();

    void on_runDirectorLoop_released();

    void on_currentTriggerStoriesList_itemDoubleClicked(QListWidgetItem *item);

    void on_currentStoriesList_itemDoubleClicked(QListWidgetItem *item);

    void on_completeStory_released();

    void on_currentActiveStory_itemDoubleClicked(QListWidgetItem *item);

    void on_personMoneyInput_editingFinished();

    void on_personHealthInput_editingFinished();

    void on_personMoodInput_editingFinished();

    void on_personRelTypeInput_editingFinished();

    void on_personRelStrengthInput_editingFinished();

    void on_storyRole_editingFinished();

    void on_citizenCheckBox_released();

private:
    Ui::Form *ui;
    Controller *controller;
    Person * current;
    WorldObject * currentItem;
    Location * currentLocation;
    WorldInterpreter *interpreter;
    Director *director;
    Evaluator *evaluator;

    void updatePeople();
    void updateLocations();
    void updateItems();
    void updateActions();

    void refreshLocationTab();
    void refreshPersonTab();

    void addOutputText(std::string textToAdd, int colour);
};

#endif // FORM_H
