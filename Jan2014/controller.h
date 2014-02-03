#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "person.h"
#include "relationship.h"
#include "worldobject.h"
#include "action.h"

class Controller
{
public:
    static Controller* Instance();

    void doThings();

private:
    Controller(){};// Private so that it can  not be called
    Controller(Controller const&){};             // copy constructor is private
    Controller& operator=(Controller const&){};  // assignment operator is private
    static Controller* m_pInstance;

    Person *createPerson(std::string name, int gender);
    WorldObject* createObject(std::string name);
    Relationship* addRelationship(Person *one, Person *two, int type, int status);

    Person *getPerson(std::string name);

    std::vector<WorldObject*> worldObjects;
    std::vector<Relationship*> relationships;
    std::vector<Person*> people;
    std::vector<Action*> actions;

};

#endif // CONTROLLER_H
