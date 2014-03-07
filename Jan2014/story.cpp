#include "story.h"

#include "evaluator.h"

#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;


using namespace std;

Story::Story()
{
    controller = Controller::Instance();
    interpreter = WorldInterpreter::Instance();
    evaluator = Evaluator::Instance();

    name = "InterrogateGangMember";
    description = "No description";

    // preStoryValues.push_back("isMainCharacter nick");

    //Leave them empty?
    //a = controller->getPeopleVector();
    //b = controller->getPeopleVector();
    //c = controller->getPeopleVector();
    preEvaluation=false;

}

string Story::getName(){
    return name;}

void Story::setName(string _name){
    name = _name;}

string Story::getDescription(){
    return description;}

void Story::setDescription(string _description){
    description = _description;}

void Story::addPreCondition(string precondition){
    preStoryValues.push_back(precondition);}

void Story::addChanges(string change){
    changes.push_back(change);}

std::vector<Person*> Story::getAPerson(){
    return a;}

std::vector<Person*> Story::getBPerson(){
    return b;}

std::vector<Person*> Story::getCPerson(){
    return c;}



bool Story::evaluatePre()
{
    if(evaluator->evaluate(preStoryValues,&a,&b,&c)==(int)preStoryValues.size())
    {
        preEvaluation = true;
        if(a.size()>0)
            chosenA = a.at(0)->getName();
        if(b.size()>0)
            chosenB = b.at(0)->getName();
        if(c.size()>0)
            chosenC = c.at(0)->getName();
    }
    else
        preEvaluation = false;

    return preEvaluation;
}

void Story::printOut()
{
    cout<<"Story: "<<name<<endl;

    if(preEvaluation)
    {
        string tempDesc=description;

        replace_all(tempDesc,"[a]",chosenA);
        replace_all(tempDesc,"[b]",chosenB);
        replace_all(tempDesc,"[c]",chosenC);

        cout<<tempDesc<<endl;
    }
    else
    {
        cout<<description;
    }
    cout<<endl;
}


