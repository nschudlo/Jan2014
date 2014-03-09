#include "storygoal.h"
#include <iostream>
#include <sstream>
#include <boost/tokenizer.hpp>

#define AUTHORGOAL 1
#define STORYGOAL 0

using namespace std;

StoryGoal::StoryGoal()
{
    name = "No Name Goal";
    typeOfGoal = STORYGOAL;
    numOfAttempts = 0;
    maxAttempts = 3;

    evaluator = Evaluator::Instance();
}

StoryGoal::StoryGoal(string _name, string _change)
{
    name = _name;
    changes.push_back(_change);
    evaluator = Evaluator::Instance();
}

vector<string> StoryGoal::getChanges(){
    return changes;}

string StoryGoal::getName(){
    return name;}

void StoryGoal::setName(string _name){
    name = _name;}

int StoryGoal::getType(){
    return typeOfGoal;}

void StoryGoal::setType(int _type){
    typeOfGoal=_type;}

bool StoryGoal::isAuthorGoal(){
    return typeOfGoal==AUTHORGOAL;}

bool StoryGoal::isStoryGoal(){
    return typeOfGoal==STORYGOAL;}

void StoryGoal::addChanges(string _change){
    changes.push_back(_change);}

int StoryGoal::getNumOfAttempts(){
    return numOfAttempts;}

void StoryGoal::setNumOfAttempts(int _num){
    numOfAttempts=_num;}

void StoryGoal::addAttempt(){
    numOfAttempts++;}

void StoryGoal::setMaxAttempts(int _max){
    maxAttempts=_max;}

int StoryGoal::getMaxAttempts(){
    return maxAttempts;}

string StoryGoal::printOut()
{
    ostringstream printOut;

    printOut<<"Goal: "<<name<<endl;
    for(int index=0; index<(int)personConditions.size();index++)
        printOut<<"    Person: "<<personConditions.at(index)<<endl;

    printOut<<endl;

    for(int index=0; index<(int)changes.size();index++)
        printOut<<"    Change: "<<changes.at(index)<<endl;

    printOut<<endl;

    for(int index=0; index<(int)a.size();index++)
        printOut<<"a has: "<<a.at(index)->getName()<<endl;

    for(int index=0; index<(int)b.size();index++)
        printOut<<"b has: "<<b.at(index)->getName()<<endl;

    for(int index=0; index<(int)c.size();index++)
        printOut<<"c has: "<<c.at(index)->getName()<<endl;

    return printOut.str();
}

void StoryGoal::addPerson(std::string person){
    personConditions.push_back(person);}

bool StoryGoal::evaluateChanges()
{
    //Haven't actually checked if any of this makes any sense...
    bool evaluation = false;
    int numTrue = evaluator->evaluate(changes,&a,&b,&c);
    if(numTrue==(int)changes.size())
    {
        cout<<"*****************"<<endl;
        cout<<"All goal conditions met for this goal:"<<name<<endl;


        cout<<"*****************"<<endl;

        //do something with a,b,c
        //as in select who will be the chosen ones
        evaluation=true;
    }

    evaluatePersonConditions();//To reset the people
    return evaluation;
}

void StoryGoal::evaluatePersonConditions()
{
    vector<Person*> _a,_b,_c;

    //Evaluate all a,b,c conditions at once
    evaluator->evaluate(personConditions,&_a,&_b,&_c);

    a=_a;
    b=_b;
    c=_c;
}

void StoryGoal::completeGoal()
{
    evaluatePersonConditions();
}


