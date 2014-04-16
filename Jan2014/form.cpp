#include "form.h"
#include "ui_form.h"
#include "controller.h"
#include "worldinterpreter.h"
#include "story.h"
#include "evaluator.h"

#include <vector>
#include <iostream>
#include <time.h>
#include <boost/lexical_cast.hpp>

#include "person.h"

using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    controller = Controller::Instance();
    controller->startLoad();
    ui->setupUi(this);
    ui->infoTabWidget->setCurrentIndex(0);

    interpreter = WorldInterpreter::Instance();
    director = Director::Instance();
    evaluator = Evaluator::Instance();

    current = new Person();
    currentLocation = new Location();
    //updateLists();

    srand(time(NULL));
}

Form::~Form()
{
    delete ui;
}

void Form::on_buttonTest_released()
{
    //This is a test button
    int random = rand()%4;
    addOutputText("Test Output", random);
}


void Form::updateLists()
{
    updatePeople();
    updateItems();
    updateLocations();
    updateActions();
}

void Form::updatePeople()
{
    vector<Person*> people = controller->getPeopleVector();
    ui->listPeople->clear();
    for(int x=0; x<(int)people.size(); x++)
    {
        QString q = people.at(x)->getName().c_str();
        ui->listPeople->addItem(q);
    }

    if(ui->listPeople->count()==0)
        ui->listPeople->setCurrentRow(-1);
    else
        ui->listPeople->setCurrentRow(0);
}

void Form::updateActions()
{
    vector<Action*> actions = controller->getActionVector();
    ui->listActions->clear();
    for(int x=0; x<(int)actions.size(); x++)
    {
        QString q = actions.at(x)->getName().c_str();
        ui->listActions->addItem(q);
    }
    if(ui->listActions->count()==0)
        ui->listActions->setCurrentRow(-1);
    else
        ui->listActions->setCurrentRow(0);
}

void Form::updateLocations()
{
    vector<Location*> locations = controller->getLocationVector();
    ui->listLocations->clear();
    for(int x=0; x<(int)locations.size(); x++)
    {
        QString q = locations.at(x)->getName().c_str();
        ui->listLocations->addItem(q);
    }
    if(ui->listLocations->count()==0)
        ui->listLocations->setCurrentRow(-1);
    else
        ui->listLocations->setCurrentRow(0);
}

void Form::updateItems()
{
    vector<WorldObject*> items = controller->getItemVector();
    ui->listWorldObjects->clear();
    for(int x=0; x<(int)items.size(); x++)
    {
        QString q = items.at(x)->getName().c_str();
        ui->listWorldObjects->addItem(q);
    }
    if(ui->listWorldObjects->count()==0)
        ui->listWorldObjects->setCurrentRow(-1);
    else
        ui->listWorldObjects->setCurrentRow(0);
}

void Form::on_buttonUpdateLists_released()
{
    updateLists();
}

void Form::on_buttonAddItem_released()
{
    if(!ui->listWorldObjects->count()==0)
    {
        QString newItem = ui->listWorldObjects->currentItem()->text();
        WorldObject* object = controller->getItem(newItem.toStdString());

        if(object!=0)
        {
            int itemCount = 0;
            int heldCount = ui->listPersonItems->count();
            for(int index=0; index<heldCount;index++)
            {
                if(ui->listPersonItems->item(index)->text().compare(newItem)==0)
                    itemCount++;
            }

            if(itemCount<object->getMaxItemsPossible())
            {
                current->holdItem(object);
                on_buttonPersonInfo_released();
            }
            string output = current->getName() + " now has the " + newItem.toStdString() + ".";
            addOutputText(output,0);
        }
    }
}

void Form::on_buttonRemoveItem_released()
{
    if(!ui->listPersonItems->count()==0)
    {
        QString removeItem = ui->listPersonItems->currentItem()->text();
        current->dropItem(removeItem.toStdString());
        on_buttonPersonInfo_released();

        string output = current->getName() + " no longer has the " + removeItem.toStdString() + ".";
        addOutputText(output,0);
    }
}

void Form::on_buttonPersonInfo_released()
{
    if(ui->listPeople->currentRow()>=0)
    {
        ui->infoTabWidget->setCurrentIndex(0);

        current = controller->getPerson(ui->listPeople->currentItem()->text().toStdString());
        refreshPersonTab();
    }
}

void Form::refreshPersonTab()
{
    ui->labelCurrentPerson->setText(QString (current->getName().c_str()));

    //Add Items to current Items List
    vector<WorldObject*> currItems = current->getItemsHeld();
    ui->listPersonItems->clear();
    for(int index=0;index<(int)currItems.size();index++)
    {
        QString item=currItems.at(index)->getName().c_str();
        ui->listPersonItems->addItem(item);
    }
    ui->listPersonItems->setCurrentRow(0);

    //Set Money
    int currMoney = current->getMoney();
    ui->personMoneyInput->setValue(currMoney);

    //Set Health
    int currHealth = current->getHealth();
    ui->personHealthInput->setValue(currHealth);

    //Set Mood
    int currMood = current->getMood();
    ui->personMoodInput->setValue(currMood);

    //Set Relationships
    vector<Relationship*> rels = current->getRelationships();
    ui->listPersonRelationship->clear();
    for(int index=0; index<(int)rels.size();index++)
    {
        QString rel =rels.at(index)->getTwo().c_str();
        ui->listPersonRelationship->addItem(rel);
    }
    ui->listPersonRelationship->setCurrentRow(0);

    //Set Location
    ui->listPersonLocations->clear();
    Location* currLocation = current->getCurrLocation();
    QString currLoc = "";
    vector<Location*> gotoLocations;

    if(currLocation != 0)
    {
        currLoc = currLocation->getName().c_str();
        gotoLocations = currLocation->getGoTo();
    }
    else
    {
        currLoc = "No Current Location";
        gotoLocations = controller->getLocationVector();
    }

    ui->personCurrentLocation->setText(currLoc);
    for(int index=0; index<(int)gotoLocations.size();index++)
        ui->listPersonLocations->addItem(gotoLocations.at(index)->getName().c_str());

    //Set Reps and Wanted
    ui->policeRep->setValue(current->getPoliceRep());
    ui->mobRep->setValue(current->getMobRep());
    ui->policeWanted->setValue(current->getPoliceWanted());
    ui->mobWanted->setValue(current->getMobWanted());

    //Set storyrank
    if(current->isMainChar())
    {
        ui->citizenCheckBox->setChecked(false);
        ui->storyRank->setEnabled(true);
        ui->storyRole->setEnabled(false);
        current->recheckStoryRank();
        ui->storyRank->setValue(current->getStoryRank());
        ui->storyRole->setValue(0);
    }
    else
    {
        ui->citizenCheckBox->setChecked(true);
        ui->storyRank->setEnabled(false);
        ui->storyRole->setEnabled(true);
        ui->storyRank->setValue(0);
        ui->storyRole->setValue(current->getStoryRole());
    }


}

void Form::on_listPeople_itemDoubleClicked(){
    on_buttonPersonInfo_released();}


void Form::on_personHealthInput_valueChanged(int arg1)
{
    current->setHealth(arg1);
}

void Form::on_personHealthInput_editingFinished()
{
    string output = current->getName() + "'s health is now " + boost::lexical_cast<string>(current->getHealth()) + ".";
    addOutputText(output,0);
}

void Form::on_personMoneyInput_valueChanged(int arg1)
{
    current->setMoney(arg1);
}

void Form::on_personMoneyInput_editingFinished()
{
    string output = current->getName() + " now has " + boost::lexical_cast<string>(current->getMoney()) + " dollars.";
    addOutputText(output,0);
}

void Form::on_personMoodInput_valueChanged(int arg1)
{
    current->setMood(arg1);
}

void Form::on_personMoodInput_editingFinished()
{
    string output = current->getName() + " now has a mood of " + boost::lexical_cast<string>(current->getMood()) + ".";
    addOutputText(output,0);
}


void Form::on_personRelTypeInput_valueChanged(int arg1)
{

    //Update the Label
    QString relType = "";
    switch(arg1)
    {
    case 0: relType = "Parent";break;
    case 1: relType = "Child";break;
    case 2: relType = "Sibling";break;
    case 3: relType = "Married";break;
    case 4: relType = "Family";break;
    case 5: relType = "SO";break;
    case 6: relType = "Strangers";break;
    case 7: relType = "Friends";break;
    case 8: relType = "Enemies";break;
    case 9: relType = "Teacher";break;
    case 10: relType = "Student";break;
    case 11: relType = "Working";break;
    case 12: relType = "Community";break;
    }
    ui->personRelType->setText(relType);

    //Change the Person value
    QString currRel = ui->listPersonRelationship->currentItem()->text();
    Relationship* rel = current->getRelationship(currRel.toStdString());

    rel->setState(arg1, rel->getStrength());
    ui->personRelPrintout->setText(rel->relationshipToString().c_str());


}

void Form::on_personRelTypeInput_editingFinished()
{
    QString currRel = ui->listPersonRelationship->currentItem()->text();
    Relationship* rel = current->getRelationship(currRel.toStdString());
    string output = rel->relationshipToString();
    addOutputText(output,0);
}

void Form::on_personRelStrengthInput_editingFinished()
{
    on_personRelTypeInput_editingFinished();
}

void Form::on_personRelStrengthInput_valueChanged(int arg1)
{
    QString relType = "";
    switch(arg1)
    {
    case 0: relType = "Bad";break;
    case 1: relType = "Average";break;
    case 2: relType = "Good";break;
    }

    ui->personRelStrength->setText(relType);

    //Change the Person value
    QString currRel = ui->listPersonRelationship->currentItem()->text();
    Relationship* rel = current->getRelationship(currRel.toStdString());

    rel->setState(rel->getState(), arg1);
    ui->personRelPrintout->setText(rel->relationshipToString().c_str());
}

void Form::on_listPersonRelationship_currentRowChanged(int currentRow)
{
    if(currentRow >= 0)
    {
        //Get the current and Relationship
        QString currRel = ui->listPersonRelationship->currentItem()->text();
        Relationship* rel = current->getRelationship(currRel.toStdString());

        //Set the label values
        ui->personRelTypeInput->setValue(rel->getState());
        ui->personRelStrengthInput->setValue(rel->getStrength());

        ui->personRelPrintout->setText(rel->relationshipToString().c_str());

    }
}

void Form::on_buttonAddRelationship_released()
{
    if(ui->listPeople->currentRow() >= 0)
    {
        string name2 = ui->listPeople->currentItem()->text().toStdString();
        if(current->getName()!=name2)
        {
            Person* person2 = controller->getPerson(name2);
            if(person2 != 0)
            {
                controller->addRelationship(current,person2,6,1);
            }
        }
    }
    refreshPersonTab();

    string person2 = ui->listPeople->currentItem()->text().toStdString();
    Relationship* rel = current->getRelationship(person2);
    string output = rel->relationshipToString();
    addOutputText(output,0);
}

void Form::on_buttonRemoveRelationship_released()
{
    if(ui->listPersonRelationship->currentRow() >=0)
    {
        string person2 = ui->listPersonRelationship->currentItem()->text().toStdString();

        current->removeRelationship(person2);
        refreshPersonTab();
    }
}

void Form::on_listPersonLocations_itemDoubleClicked(QListWidgetItem *item)
{
    Location* newLoc = controller->getLocation(item->text().toStdString());

    if(newLoc!=0)
    {
        current->setCurrLocation(newLoc);
        //on_buttonPersonInfo_released();
        refreshPersonTab();
    }
    refreshLocationTab();

    string output= current->getName() + " is now at the location " + newLoc->getName()+".";
    addOutputText(output,0);
}

void Form::on_listWorldObjects_itemDoubleClicked()
{
    on_buttonItemInfo_released();
}

void Form::on_buttonItemInfo_released()
{
    if(ui->listWorldObjects->currentRow()>=0)
    {
        ui->infoTabWidget->setCurrentIndex(1);
        currentItem = controller->getItem(ui->listWorldObjects->currentItem()->text().toStdString());

        //Set Current Item label
        ui->labelCurrentItem->setText(currentItem->getName().c_str());

        //Add to action do
        vector<Action*> actionsDo = currentItem->getActionsDo();
        ui->listItemActionDo->clear();
        for(int index=0; index<(int)actionsDo.size();index++)
        {
            ui->listItemActionDo->addItem(actionsDo.at(index)->getName().c_str());
        }

        //Add to action get
        vector<Action*> actionsGet = currentItem->getActionsGet();
        ui->listItemActionGet->clear();
        for(int index=0; index<(int)actionsGet.size();index++)
        {
            ui->listItemActionGet->addItem(actionsGet.at(index)->getName().c_str());
        }
    }
}

void Form::on_buttonItemAddDo_released()
{
    if(!ui->listActions->count()==0)
    {
        QString newItem = ui->listActions->currentItem()->text();
        Action* action = controller->getAction(newItem.toStdString());

        if(action!=0)
        {
            int actionCount = ui->listItemActionDo->count();
            for(int index=0; index<actionCount;index++)
            {
                if(ui->listItemActionDo->item(index)->text().compare(newItem)==0)
                    return;
            }

            currentItem->addActionDo(action);
            on_buttonItemInfo_released();

        }
    }
}

void Form::on_buttonItemRemoveDo_released()
{
    if(ui->listItemActionDo->currentRow()>=0)
    {
        QString removeItem = ui->listItemActionDo->currentItem()->text();
        currentItem->removeActionDo(removeItem.toStdString());
        on_buttonItemInfo_released();
    }
}



void Form::on_buttonItemAddGet_released()
{
    if(!ui->listActions->count()==0)
    {
        QString newItem = ui->listActions->currentItem()->text();
        Action* action = controller->getAction(newItem.toStdString());

        if(action!=0)
        {
            int actionCount = ui->listItemActionGet->count();
            for(int index=0; index<actionCount;index++)
            {
                if(ui->listItemActionGet->item(index)->text().compare(newItem)==0)
                    return;
            }

            currentItem->addActionGet(action);
            on_buttonItemInfo_released();

        }
    }
}

void Form::on_buttonItemRemoveGet_released()
{
    if(ui->listItemActionGet->currentRow()>=0)
    {
        QString removeItem = ui->listItemActionGet->currentItem()->text();
        currentItem->removeActionGet(removeItem.toStdString());
        on_buttonItemInfo_released();
    }
}

void Form::on_buttonLocationInfo_released()
{
    if(ui->listLocations->currentRow()>=0)
    {
        ui->infoTabWidget->setCurrentIndex(2);
        currentLocation = controller->getLocation(ui->listLocations->currentItem()->text().toStdString());

        refreshLocationTab();

    }
}

void Form::refreshLocationTab()
{
    //Set Current Item label
    ui->labelLocationCurrent->setText(currentLocation->getName().c_str());

    //Add to locations to
    vector<Location*> locationsTo = currentLocation->getGoTo();
    ui->listLocationsGoTo->clear();
    for(int index=0; index<(int)locationsTo.size();index++)
    {
        ui->listLocationsGoTo->addItem(locationsTo.at(index)->getName().c_str());
    }

    //Add to locations from
    vector<Location*> locationsFrom = currentLocation->getComeFrom();
    ui->listLocationsComeFrom->clear();
    for(int index=0; index<(int)locationsFrom.size();index++)
    {
        ui->listLocationsComeFrom->addItem(locationsFrom.at(index)->getName().c_str());
    }

    //Add People Currently there
    vector<Person*> currentPeople = currentLocation->getCurrentPeople();
    ui->listLocationsPeople->clear();
    for(int index=0; index<(int)currentPeople.size();index++)
    {
        ui->listLocationsPeople->addItem(currentPeople.at(index)->getName().c_str());
    }
}

void Form::on_listLocations_itemDoubleClicked()
{
    on_buttonLocationInfo_released();
}

void Form::on_listLocationsGoTo_itemDoubleClicked(QListWidgetItem *item)
{
    currentLocation = controller->getLocation(item->text().toStdString());
    refreshLocationTab();
}

void Form::on_listLocationsComeFrom_itemDoubleClicked(QListWidgetItem *item)
{
    currentLocation = controller->getLocation(item->text().toStdString());
    refreshLocationTab();
}

void Form::on_listLocationsPeople_itemDoubleClicked(QListWidgetItem *item)
{
    current = controller->getPerson(item->text().toStdString());
    refreshPersonTab();
    ui->infoTabWidget->setCurrentIndex(0);
}


void Form::on_policeRep_valueChanged(int arg1){
    current->setPoliceRep(arg1);
    refreshPersonTab();}

void Form::on_mobRep_valueChanged(int arg1){
    current->setMobRep(arg1);
    refreshPersonTab();}

void Form::on_policeWanted_valueChanged(int arg1){
    current->setPoliceWanted(arg1);
    refreshPersonTab();}

void Form::on_mobWanted_valueChanged(int arg1){
    current->setMobWanted(arg1);
    refreshPersonTab();}


void Form::on_storyRank_valueChanged(int arg1)
{
    current->setStoryRank(arg1);
    QString rank = "";
    switch(current->getStoryRank())
    {
    case 0: rank="No Rank";break;
    case 1: rank="Mobster";break;
    case 2: rank="Vigilante";break;
    case 3: rank="Police";break;
    }

    ui->rankLabel->setText(rank);
}

void Form::on_citizenCheckBox_toggled(bool checked)
{

    if(checked)//Not main char
    {
        current->setIsMainChar(false);
    }
    else//Main char
    {
        current->setIsMainChar(true);
    }

    refreshPersonTab();
}

void Form::on_citizenCheckBox_released()
{
    string output = current->getName() + " is ";
    if(!current->isMainChar())
        output = output + " not ";
    output = output + " the main character.";
    addOutputText(output,0);
}

void Form::on_storyRole_valueChanged(int arg1)
{
    QString role = "";

    if(arg1==0)
    {
        if(current->isMainChar())
            ui->roleLabel->setText("No Role");
        else
        {
            //current->setStoryRole(1);
            ui->storyRole->setValue(1);
        }
    }
    else
    {
        current->setStoryRole(arg1);
        switch(current->getStoryRole())
        {
        case 0: role="error";break; //should never get here
        case 1: role="Shopper";break;
        case 2: role="Shop Owner";break;
        case 3: role="Bartender";break;
        case 4: role="Police";break;
        case 5: role="Mobster";break;
        case 6: role="Banker";break;
        case 7: role="Gang Member";break;
        case 8: role="Dock Worker";break;
        }
        ui->roleLabel->setText(role);
    }
}

void Form::on_storyRole_editingFinished()
{
    QString role = ui->roleLabel->text();
    string output = current->getName() + " is a " + role.toStdString();
    addOutputText(output,0);
}

void Form::on_loadGoals_released()
{
    //director->loadGoals("./Stories/Goals.txt");
    //on_refreshGoals_released();
}

void Form::on_refreshGoals_released()
{
    /* ui->listGoals->clear();
    vector<StoryGoal*> goals = director->getGoals();
    for(int x=0; x<(int)goals.size(); x++)
    {
        QString q = goals.at(x)->getName().c_str();

        ui->listGoals->addItem(q);

        if(goals.at(x)->isAuthorGoal())
            ui->listGoals->itemAt(x,0)->setTextColor(Qt::red);
    }

    ui->listGoals->setCurrentRow(-1);
    ui->numAttempts->setText(QString("0"));
    ui->maxAttempts->setText(QString("0"));

    ui->goalTextBrowser->clear();
*/
}

void Form::on_loadStories_released()
{
    director->loadStories("./Stories/Stories.txt");
    on_refreshStories_released();
}

void Form::on_refreshStories_released()
{
    ui->listStories->clear();
    vector<Story*> stories = director->getStories();
    for(int x=0; x<(int)stories.size(); x++)
    {
        QString q = stories.at(x)->getName().c_str();
        ui->listStories->addItem(q);
    }

    ui->stortTextBrowser->clear();
}

void Form::on_listGoals_itemDoubleClicked(QListWidgetItem *item)
{
    //StoryGoal* curr = director->getGoal(item->text().toStdString());

    //ui->numAttempts->setText(QString::number(curr->getNumOfAttempts()));
    //ui->maxAttempts->setText(QString::number(curr->getMaxAttempts()));

    //ui->goalTextBrowser->setText(QString(curr->printOut().c_str()));
}



void Form::on_listStories_itemDoubleClicked(QListWidgetItem *item)
{
    Story* curr = director->getStory(item->text().toStdString());

    string output = "Story Fragment '" + curr->getName() + "' added as a goal story.";
    addOutputText(output, 1);

    if(curr->evaluatePre())
    {
        curr->evaluateOptional();
        curr->chooseVariablePeople();
        curr->reEvaluate();
        director->addToStoryQueue(curr);
    }
    ui->stortTextBrowser->setText(QString(curr->printOut().c_str()));
    on_runDirectorLoop_released();
}

void Form::on_updateCurrentGoalsButton_released()
{
    vector<Condition*> currGoals = director->getGoalQueue();

    ui->currentGoalsList->clear();

    for(int index=0; index<(int)currGoals.size();index++)
    {
        string curr = currGoals.at(index)->printOut();
        ui->currentGoalsList->addItem(QString(curr.c_str()));
    }

}

void Form::on_updateCurrentStoriesButton_released()
{
    ui->currentStoryInfo->clear();

    vector<Story*> currStories = director->getStoryQueue();
    ui->currentStoriesList->clear();
    for(int index=0; index<(int)currStories.size();index++)
    {
        string curr = currStories.at(index)->getName();
        ui->currentStoriesList->addItem(QString(curr.c_str()));
    }

    vector<Story*> currTrigStories = director->getTriggerStories();
    ui->currentTriggerStoriesList->clear();
    for(int index=0; index<(int)currTrigStories.size();index++)
    {
        string curr = currTrigStories.at(index)->getName();
        ui->currentTriggerStoriesList->addItem(QString(curr.c_str()));
    }
}

void Form::on_runDirectorLoop_released()
{
    director->runStoryLoop();
    on_updateCurrentStoriesButton_released();
    on_updateCurrentGoalsButton_released();

    ui->currentActiveStory->clear();

    //Get the active story from the director
    Story* currActiveStory = director->getCurrentActiveStory();
    if(currActiveStory != NULL)
    {
        ui->currentActiveStory->addItem(QString(currActiveStory->getName().c_str()));
        string output= "Currently playing the story '" + currActiveStory->getName() + "'.";
        addOutputText(output,1);
        output = currActiveStory->printDescription();
        addOutputText(output,2);
    }
}

void Form::on_currentTriggerStoriesList_itemDoubleClicked(QListWidgetItem *item)
{
    ui->currentStoriesList->setCurrentRow(-1);
    ui->currentActiveStory->setCurrentRow(-1);

    ui->currentStoryInfo->clear();
    Story* currStory = director->getStory(item->text().toStdString());

    ui->currentStoryInfo->addItem(QString(currStory->printOut().c_str()));
}

void Form::on_currentStoriesList_itemDoubleClicked(QListWidgetItem *item)
{
    ui->currentTriggerStoriesList->setCurrentRow(-1);
    ui->currentActiveStory->setCurrentRow(-1);

    ui->currentStoryInfo->clear();
    Story* currStory = director->getStory(item->text().toStdString());

    ui->currentStoryInfo->addItem(QString(currStory->printOut().c_str()));
}

void Form::on_currentActiveStory_itemDoubleClicked(QListWidgetItem *item)
{
    ui->currentTriggerStoriesList->setCurrentRow(-1);
    ui->currentStoriesList->setCurrentRow(-1);

    ui->currentStoryInfo->clear();
    Story* currStory = director->getStory(item->text().toStdString());

    ui->currentStoryInfo->addItem(QString(currStory->printOut().c_str()));
}

void Form::on_completeStory_released()
{
    Story* currActiveStory = director->getCurrentActiveStory();
    if(currActiveStory!=NULL)
    {
        string output= "Completing the story '" + currActiveStory->getName() + "'.";
        addOutputText(output,1);

        director->completeActiveStory();
        on_runDirectorLoop_released();
    }


}

void Form::addOutputText(string textToAdd, int colour)
{

    QListWidgetItem* pItem =new QListWidgetItem(textToAdd.c_str());

    switch (colour)
    {
    case 0://Black
        pItem->setForeground(Qt::black);
        break;
    case 1://Blue
        pItem->setForeground(Qt::darkBlue);
        break;
    case 2://Green
        pItem->setForeground(Qt::darkGreen);
        break;
    case 3://Red
        pItem->setForeground(Qt::red);
        break;
    }

    ui->outputText->addItem(pItem);
    ui->outputText->scrollToBottom();
}




