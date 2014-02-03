#ifndef BULKLOADER_H
#define BULKLOADER_H
#include <person.h>
#include <relationship.h>
#include <worldobject.h>
#include <action.h>

class BulkLoader
{
public:
    BulkLoader(std::vector<WorldObject*> *_worldObjects,
               std::vector<Relationship*> *_relationships,
               std::vector<Person*> *_people,
               std::vector<Action *> *_actions);

    Person* createPerson(std::string name, int gender);
    WorldObject* createObject(std::string name);
    Action* createAction(std::string name);
    Relationship *addRelationship(Person *one, Person *two, int type, int status);

    void loadfile(std::string filename);
    void testString(std::string line, int cycle, std::string &currentPerson);
    Person* getPerson(std::string name);
    WorldObject* getItem(std::string name);
    Action* getAction(std::string name);

private:
    //std::string types[] = {"Item", "Person", "Relationship"};
    //const char* const types[] = {"Item", "Person", "Relationship"};

    std::vector<WorldObject*> *worldObjects;
    std::vector<Relationship*> *relationships;
    std::vector<Person*> *people;
    std::vector<Action*> *actions;

};

#endif // BULKLOADER_H
