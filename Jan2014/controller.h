#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "location.h"
#include "person.h"
#include "relationship.h"
#include "worldobject.h"
#include "action.h"


class Controller
{
public:
    static Controller* Instance();

    void startLoad();

    std::vector<Person*> getPeopleVector();
    std::vector<Location*> getLocationVector();
    std::vector<WorldObject*> getItemVector();
    std::vector<Action*> getActionVector();

    Person *getPerson(std::string name);
    WorldObject* getItem(std::string name);
    Location* getLocation(std::string name);
    Action* getAction(std::string name);

    Person *createPerson(std::string name, int gender);
    WorldObject* createObject(std::string name);
    Relationship* addRelationship(Person *one, Person *two, int type, int status);
    Action* createAction(std::string name);

private:
    Controller(){};// Private so that it can  not be called
    Controller(Controller const&){};             // copy constructor is private
    Controller& operator=(Controller const&){};  // assignment operator is private
    static Controller* m_pInstance;

    std::vector<Location*> locations;
    std::vector<WorldObject*> worldObjects;
    std::vector<Relationship*> relationships;
    std::vector<Person*> people;
    std::vector<Action*> actions;

};

#endif // CONTROLLER_H
