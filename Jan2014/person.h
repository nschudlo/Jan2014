#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <worldobject.h>
#include <relationship.h>
#include <action.h>
#include "location.h"

class Relationship;
class Location;

class Person
{
public:
    Person();
    Person(std::string name, int gender);

    std::string getName();


    std::vector<WorldObject *> getItemsHeld();
    void holdItem(WorldObject *object);
    void dropAll(std::string object);               //drop all items with name
    void dropItem(std::string object);              //drop one item with name4
    void dropItem(std::string object,int count);    //drop count items of object
    int isHolding(std::string objectName);
    void printAllItems();
    void setName(std::string newName);
    int getGender();
    void printDetails();


    void listActions();
    void addActionDo(Action *act);
    void addActionGet(Action *act);
    std::vector<Action*> getActionsDo();
    std::vector<Action*> getActionsGet();
    bool canActionDo(std::string name);
    bool canActionGet(std::string name);



    int getMoney();
    void setMoney(int _mon);
    int getMood();
    void setMood(int _mood);
    int getHealth();
    void setHealth(int _health);

    Location* getCurrLocation();
    void setCurrLocation(Location* loc);


    void addRelationship(Relationship *rel);
    void removeRelationship(std::string name);
    void listRelationships();
    Relationship* getRelationship(std::string name);
    std::vector<Relationship*> getRelationships();

private:
    std::string name;
    int gender; //0=male 1=female
    int mood; //0=sad 10=happy
    int money; //Common value in games
    int health; //0-100?

    Location* currentLocation;

    std::vector<WorldObject*> itemsHeld;
    std::vector<Relationship*> relationships;
    std::vector<Action*> actionsDo;
    std::vector<Action*> actionsGet;
};

#endif // PERSON_H
