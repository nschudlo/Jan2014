#ifndef STORY_H
#define STORY_H

#include <vector>
#include <string>
#include "controller.h"
#include "worldinterpreter.h"
#include "evaluator.h"
#include "condition.h"
#include "director.h"

class Director;

class Story
{
public:
    Story();

    std::string printOut();
    std::string printDescription();
    std::string printMotivation();
    bool evaluatePre();
    std::string getName();
    void setName(std::string _name);
    std::string getDescription();
    void setDescription(std::string _description);
    std::string getMotivator();
    void setMotivator(std::string _motivator);
    bool motivationBeenPrinted();
    void setMotivationPrinted(bool _been);

    void addMPreCondition(std::string precondition);
    void addPreCondition(std::string precondition);
    void addChanges(std::string change);
    void addTrigger(std::string trigger);

    void setPriority(int _priority);
    int getPriority();

    void divideConditions();

    std::vector<Person*> getAMand();
    std::vector<Person*> getBMand();
    std::vector<Person*> getCMand();

    std::vector<Person*> getAOptional();
    std::vector<Person*> getBOptional();
    std::vector<Person*> getCOptional();

    std::vector<Condition*> getChanges();

    void evaluateMandatory();
    int evaluateOptional();

    void chooseVariablePeople();
    bool reEvaluate();
    void checkStoryGoals();

    bool checkTriggers();

    bool setGoal(Condition* goalCondition);
    bool compareConditions(Condition *condition1, Condition *condition2);

    bool beenUsed();
    void setUsed(bool _used);
    void resetVariables();

private:
    std::string name;
    std::string description;
    std::string motivator;

    std::vector<Condition*> conds, aConds, bConds, cConds, setConds;
    std::vector<Condition*> condsM, aCondsM, bCondsM, cCondsM, setCondsM;
    std::vector<Condition*> changes;
    std::vector<Condition*> triggers;

    bool preEvaluation;

    Controller *controller;
    WorldInterpreter *interpreter;
    Evaluator *evaluator;
    Director *director;

    std::vector<Person*> aMand,bMand,cMand;
    std::vector<Person*> aOpt,bOpt,cOpt;
    int aCount,bCount,cCount,setCount, setCountM;

    int failedOptConditions;

    //Person chosen_A, chosen_B, chosen_C;
    std::string chosenA,chosenB,chosenC;

    bool used;
    int priority;

    bool motivationPrinted;

};

#endif // STORY_H
