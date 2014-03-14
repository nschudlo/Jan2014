#ifndef CONDITION_H
#define CONDITION_H

#include <string>
#include <vector>
#include "worldinterpreter.h"
#include "controller.h"


class Condition
{
public:
    Condition(std::string conditionLine);

    std::string printOut();

    bool isA();
    bool isB();
    bool isC();

    int getVariablePosition();

    std::string getType();
    std::string getVal1();
    std::string getVal2();
    bool getEvaluationBool();

    void addPerson(std::string name);
    bool hasPerson(std::string name);

    void setVariablePerson(std::string name);

    void resetCondition();

private:
    std::string type;
    std::string val1;
    std::string originalVal1;//Incase revert is needed
    std::string val2;
    std::string originalVal2;//Incase revert is needed
    bool evalBool;

    std::vector<std::string> people;
    //std::vector<Person*> person;

    WorldInterpreter* interpreter;
    Controller* controller;

};

#endif // CONDITION_H
