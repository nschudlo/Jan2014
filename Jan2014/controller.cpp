#include "controller.h"
#include <iostream>
#include <bulkloader.h>

using namespace std;

enum gender{MALE=0, FEMALE=1};
enum relationship{Parent=0, Child=1, Sibling=2, Married=3, Family=4, SO=5, Strangers=6,
                  Friends=7, Enemies=8, Teacher=9, Student=10, Working=11, Community=12};

// Global static pointer used to ensure a single instance of the class.
Controller* Controller::m_pInstance = NULL;

/** This function is called to create an instance of the class.
    Calling the constructor publicly is not allowed. The constructor
    is private and is only called by this Instance function.
*/
Controller* Controller::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Controller;
    return m_pInstance;
}

/**
 *  Main function of the class.
 * @brief Controller::doThings
 */
void Controller::doThings()
{
    //void updateCursors(vector<cursor*>& cursors)
    BulkLoader bulk = BulkLoader(&worldObjects,&relationships,&people);

    /*
    Person* nick = createPerson("Nick",MALE);
    Person* nikki = createPerson("Nikki",FEMALE);

    //Nick believes this is the type of relationship he has with nikki
    addRelationship(nick, nikki, SO, 2);
    addRelationship(nikki,nick,SO,1);

   // nick->listRelationships();
   // nikki->listRelationships();

    createPerson("Larissa",FEMALE);
    createPerson("John",MALE);

    addRelationship(getPerson("Larissa"),getPerson("John"),Parent,2);
    addRelationship(getPerson("John"),getPerson("Larissa"),Child,0);

    getPerson("Larissa")->listRelationships();
    getPerson("John")->listRelationships();

    /*for(int index=0;index<=12;index++)
    {
        for(int index2=0; index2<=2; index2++)
        {
            nikki->getRelationship("Nick")->setState(index,index2);
            nikki->listRelationships();
        }
    }*/

    //createObject("Apple");
    //createObject("Flowers");

    //getPerson("Nick")->listRelationships();
   // getPerson("Nikki")->listRelationships();
    getPerson("Nick")->printDetails();
    getPerson("Nikki")->printDetails();




}

Person* Controller::createPerson(std::string name, int gender)
{

    people.push_back(new Person(name,gender));
    return people.back();
}

WorldObject *Controller::createObject(std::string name)
{
    worldObjects.push_back(new WorldObject(name));
    return worldObjects.back();
}

Relationship *Controller::addRelationship(Person *one, Person *two, int type, int status)
{
    if(one != 0 && two != 0)
    {
        relationships.push_back(new Relationship(one, two, type, status));
        return relationships.back();
    }
    return 0;
}

Person* Controller::getPerson(std::string name)
{
    for(int index=0; index<(int)people.size(); index++)
    {
        if(people.at(index)->getName()==name)
            return people.at(index);
    }

    return 0;
}
