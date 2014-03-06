#ifndef STORY_H
#define STORY_H

#include <vector>
#include <string>
#include "controller.h"
#include "worldinterpreter.h"

class Story
{
public:
    Story();

    bool evaluatePre();
    std::string getName();

    std::vector<Person*> getAPerson();
    std::vector<Person*> getBPerson();
    std::vector<Person*> getCPerson();

private:
    std::string name;
    std::vector<std::string> preStoryValues;
    std::vector<std::string> goalChanges;

    bool preEvaluation;

    Controller *controller;
    WorldInterpreter *interpreter;

    std::vector<Person*> a,b,c;
};

#endif // STORY_H
