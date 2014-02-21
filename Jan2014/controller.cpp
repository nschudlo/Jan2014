#include "controller.h"
#include <iostream>
#include "bulkloader.h"
#include "locationloader.h"

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
void Controller::startLoad()
{

    BulkLoader(&worldObjects,&relationships,&people,&actions, "BulkLoad.txt");
    LocationLoader(&locations, "locations.txt");

    getPerson("Nick")->printDetails();
    getPerson("Nikki")->printDetails();

   //nick->getItemsHeld().at(0)->listActions();
}


std::vector<Person*> Controller::getPeopleVector(){
    return people;}
std::vector<WorldObject*> Controller::getItemVector(){
    return worldObjects;}
std::vector<Action*> Controller::getActionVector(){
    return actions;}
std::vector<Location*> Controller::getLocationVector(){
    return locations;}

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

WorldObject* Controller::getItem(std::string name)
{
    for(int index=0; index<(int)worldObjects.size(); index++)
    {
        if(worldObjects.at(index)->getName()==name)
            return worldObjects.at(index);
    }

    return 0;
}

Action *Controller::createAction(std::string name)
{
    actions.push_back(new Action(name));
    return actions.back();
}

Location* Controller::getLocation(string name)
{
    for(int index=0; index<(int)locations.size();index++)
    {
        if(locations.at(index)->getName()==name)
            return locations.at(index);
    }
    return 0;
}
