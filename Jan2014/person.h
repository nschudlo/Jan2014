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


    void setPoliceRep(int rep);
    void setMobRep(int rep);
    void setPoliceWanted(int wanted);
    void setMobWanted(int wanted);

    int getPoliceRep();
    int getMobRep();
    int getPoliceWanted();
    int getMobWanted();

    void setStoryRank(int rank);
    int getStoryRank();

    void recheckStoryRank();

    void setStoryRole(int role);
    int getStoryRole();

    bool isMainChar();
    void setIsMainChar(bool val);

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


    //These values have to do with cops and robbers
    bool mainChar;
    int policeRep;
    int mobRep;
    int policeWanted;
    int mobWanted;

    //The various levels you can be
    //3=Police, 2=Vigilante, 1=Mobster, 0=Citizen
    int storyRank;

    //For other characters. StoryRank is citizen for these types
    //1=Shopper, 2=Shop Owner, 3=Bartender, 4=Police, 5=Mobster
    //6=Banker, 7=Gang Member, 8=DockWorker
    int storyRole;



};

#endif // PERSON_H
