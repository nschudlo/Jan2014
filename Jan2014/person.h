#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <worldobject.h>
#include <relationship.h>

class Relationship;

class Person
{
public:
    Person(std::string name, int gender);

    std::string getName();
    void setMood(int mood);
    int getMood();

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

    void addRelationship(Relationship *rel);
    void listRelationships();
    Relationship* getRelationship(std::string name);

private:
    std::string name;
    int gender; //0=male 1=female
    int mood; //0=sad 10=happy

    std::vector<WorldObject*> itemsHeld;
    std::vector<Relationship*> relationships;
};

#endif // PERSON_H
