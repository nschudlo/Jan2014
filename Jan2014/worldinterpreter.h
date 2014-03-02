#ifndef WORLDINTERPRETER_H
#define WORLDINTERPRETER_H

#include <string>
#include <vector>
#include "controller.h"

class WorldInterpreter
{
public:
    WorldInterpreter();

    bool personIsAt(std::string person, std::string location);

private:
    std::vector<Location*> locations;
    std::vector<WorldObject*> worldObjects;
    std::vector<Relationship*> relationships;
    std::vector<Person*> people;
    std::vector<Action*> actions;

    Controller *controller;
};

#endif // WORLDINTERPRETER_H
