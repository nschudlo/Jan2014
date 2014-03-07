#ifndef STORY_H
#define STORY_H

#include <vector>
#include <string>
#include "controller.h"
#include "worldinterpreter.h"
#include "evaluator.h"

class Story
{
public:
    Story();

    void printOut();
    bool evaluatePre();
    std::string getName();
    void setName(std::string _name);
    std::string getDescription();
    void setDescription(std::string _description);

    void addPreCondition(std::string precondition);
    void addChanges(std::string change);

    std::vector<Person*> getAPerson();
    std::vector<Person*> getBPerson();
    std::vector<Person*> getCPerson();

private:
    std::string name;
    std::string description;
    std::vector<std::string> preStoryValues;
    std::vector<std::string> changes;

    bool preEvaluation;

    Controller *controller;
    WorldInterpreter *interpreter;
    Evaluator *evaluator;

    std::vector<Person*> a,b,c;
    std::string chosenA,chosenB,chosenC;
};

#endif // STORY_H
