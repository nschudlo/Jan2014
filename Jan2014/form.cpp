#include "form.h"
#include "ui_form.h"
#include "controller.h"
#include <vector>
#include <iostream>

#include "person.h"

using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    controller = Controller::Instance();
    controller->startLoad();
    ui->setupUi(this);

    current = new Person();
    //updateLists();
}

Form::~Form()
{
    delete ui;
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
    }
}

void Form::on_buttonPersonInfo_released()
{
    if(ui->listPeople->currentRow()>=0)
    {
        current = controller->getPerson(ui->listPeople->currentItem()->text().toStdString());

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


    }
}
void Form::on_listPeople_itemDoubleClicked(){
    on_buttonPersonInfo_released();}


void Form::on_personHealthInput_valueChanged(int arg1)
{
    current->setHealth(arg1);
}

void Form::on_personMoneyInput_valueChanged(int arg1)
{
    current->setMoney(arg1);
}


void Form::on_personMoodInput_valueChanged(int arg1)
{
    current->setMood(arg1);
}

enum relationship{Parent=0, Child=1, Sibling=2, Married=3, Family=4, SO=5, Strangers=6,
                  Friends=7, Enemies=8, Teacher=9, Student=10, Working=11, Community=12};

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

void Form::on_listPersonLocations_itemDoubleClicked(QListWidgetItem *item)
{
    Location* newLoc = controller->getLocation(item->text().toStdString());

    if(newLoc!=0)
    {
        current->setCurrLocation(newLoc);
        on_buttonPersonInfo_released();
    }

}
