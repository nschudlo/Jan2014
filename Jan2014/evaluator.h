#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include <string>
#include "worldinterpreter.h"
#include "controller.h"
#include "person.h"
#include "condition.h"

class Evaluator
{
public:
    static Evaluator* Instance();

    int evaluate(std::vector<std::string> _conditions,
                 std::vector<Person*> *_a,
                 std::vector<Person*> *_b,
                 std::vector<Person*> *_c);

    int evaluateStory(std::vector<std::string> _conditions,
                      std::vector<Person*> *_a,
                      std::vector<Person*> *_b,
                      std::vector<Person*> *_c);

    void checkMandatory(std::vector<Condition *> *_conditions,
                        std::vector<Person *> *_currPeople);

    int checkOptional(std::vector<Condition *> *_conditions,
                       std::vector<Person*> *_currPeople,
                       std::vector<Person *> *resultPeople);

    void checkCondition(Condition* condition);

    bool checkConditionSet(Condition* condition);

private:

    Evaluator();
    static Evaluator* m_pInstance;
    bool evaluatePre(std::string pre);

    WorldInterpreter *interpreter;
    Controller * controller;

    std::vector<std::string> conditions;

    std::vector<Condition*> *conditionList;
    std::vector<Person*> *peopleList;

    std::vector<Person*> *a,*b,*c;

    std::vector<int> countA,countB,countC;//,countTemp;
    int aCount,bCount,cCount;


};

#endif // EVALUATOR_H
