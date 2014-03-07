#include "storygoal.h"
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace std;

StoryGoal::StoryGoal()
{
    name = "No Name Goal";
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

void StoryGoal::addChanges(string _change){
    changes.push_back(_change);}

void StoryGoal::printOut()
{
    cout<<"Goal: "<<name<<endl;
    for(int index=0; index<(int)changes.size();index++)
        cout<<"\tChange: "<<changes.at(index)<<endl;
}

void StoryGoal::addPerson(std::string person)
{
    personConditions.push_back(person);
}

void StoryGoal::completeGoal()
{
    vector<Person*> _a,_b,_c;

    //Evaluate all a,b,c conditions at once
    evaluator->evaluate(personConditions,&_a,&_b,&_c);

    a=_a;
    b=_b;
    c=_c;

    for(int index=0; index<(int)a.size();index++)
        cout<<"a has: "<<a.at(index)->getName()<<endl;

    for(int index=0; index<(int)b.size();index++)
        cout<<"b has: "<<b.at(index)->getName()<<endl;

    for(int index=0; index<(int)c.size();index++)
        cout<<"c has: "<<c.at(index)->getName()<<endl;
}


