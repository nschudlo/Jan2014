#ifndef STORY_H
#define STORY_H

#include <vector>
#include <string>
#include "controller.h"
#include "worldinterpreter.h"
#include "evaluator.h"
#include "condition.h"

class Story
{
public:
    Story();

    std::string printOut();
    bool evaluatePre();
    std::string getName();
    void setName(std::string _name);
    std::string getDescription();
    void setDescription(std::string _description);

    void addMPreCondition(std::string precondition);
    void addPreCondition(std::string precondition);
    void addChanges(std::string change);

    void divideConditions(int typeFlag);

    std::vector<Person*> getAMand();
    std::vector<Person*> getBMand();
    std::vector<Person*> getCMand();

    std::vector<Person*> getAOptional();
    std::vector<Person*> getBOptional();
    std::vector<Person*> getCOptional();

    void evaluateMandatory();
    int evaluateOptional();

private:
    std::string name;
    std::string description;
    std::vector<Condition*> conds, aConds, bConds, cConds, setConds;
    std::vector<Condition*> condsM, aCondsM, bCondsM, cCondsM, setCondsM;
    std::vector<Condition*> changes;

    bool preEvaluation;

    Controller *controller;
    WorldInterpreter *interpreter;
    Evaluator *evaluator;

    std::vector<Person*> aMand,bMand,cMand;
    std::vector<Person*> aOpt,bOpt,cOpt;
    //Person chosen_A, chosen_B, chosen_C;
    std::string chosenA,chosenB,chosenC;
};

#endif // STORY_H
