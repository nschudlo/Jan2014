#ifndef STORYGOAL_H
#define STORYGOAL_H

#include <vector>
#include <string>
#include "person.h"
#include "evaluator.h"

class StoryGoal
{
public:
    StoryGoal();
    StoryGoal(std::string _name, std::string _change);

    void printOut();

    std::string getName();
    void setName(std::string _name);

    int getType();
    void setType(int _type);
    bool isAuthorGoal();
    bool isStoryGoal();

    std::vector<std::string> getChanges();
    void addChanges(std::string _change);
    void addPerson(std::string person);
    void completeGoal();

    bool evaluateChanges();
    void evaluatePersonConditions();

private:
    std::string name;
    std::string goal;
    Evaluator *evaluator;
    int typeOfGoal;

    std::vector<std::string> changes;

    std::vector<Person*> a,b,c;

    std::vector<std::string> personConditions;


};

#endif // STORYGOAL_H
