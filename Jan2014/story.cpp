#include "story.h"

#include "evaluator.h"

#include <iostream>
#include <sstream> //for the printout stream
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

void Story::addMPreCondition(string precondition){
    preStoryValuesM.push_back(precondition);}

void Story::addChanges(string change){
    changes.push_back(change);}

std::vector<Person*> Story::getAPerson(){
    return a;}

std::vector<Person*> Story::getBPerson(){
    return b;}

std::vector<Person*> Story::getCPerson(){
    return c;}


#define macroInterpreterTwo(functionName, valOne,valTwo)\
    interpreter->functionName(valOne,valTwo)
#define macroInterpreterOne(functionName, valOne)\
    interpreter->functionName(valOne)

bool Story::evaluatePre()
{
    a.clear();
    b.clear();
    c.clear();

    //This returns people with all mandatory values true. If no one fits this, we have
    //to create a new person...
    if(evaluator->evaluateStory(preStoryValuesM,&a,&b,&c)==(int)preStoryValuesM.size())
    {
        int numCorr = evaluator->evaluateStory(preStoryValues,&a,&b,&c);
        if(numCorr == (int)preStoryValues.size())
        {
            preEvaluation = true;
        }
        else
        {
            preEvaluation = false;
        }

        return preEvaluation;
    }
    else
    {
        //Make a new person who fits the description
    }
}

string Story::printOut()
{
    ostringstream printOut;

    printOut<<"Story: "<<name<<endl;

    for(int index=0; index<(int)preStoryValuesM.size();index++)
        printOut<<"    MPreconditions: "<<preStoryValuesM.at(index)<<endl;

    for(int index=0; index<(int)preStoryValues.size();index++)
        printOut<<"    Preconditions: "<<preStoryValues.at(index)<<endl;

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

    printOut<<endl;

    if(preEvaluation)
    {
        string tempDesc=description;

        if((int)a.size()>0)
        {
            printOut<<"Choosing a: ";
            chosenA = a.at(rand()%(int)a.size())->getName();
            printOut<<chosenA<<endl;
        }
        if((int)b.size()>0)
        {
            printOut<<"Choosing b: ";
            chosenB = b.at(rand()%(int)b.size())->getName();
            printOut<<chosenB<<endl;
        }
        if((int)c.size()>0)
        {
            printOut<<"Choosing c: ";
            chosenC = c.at(rand()%(int)c.size())->getName();
            printOut<<chosenC<<endl;
        }


        replace_all(tempDesc,"[a]",chosenA);
        replace_all(tempDesc,"[b]",chosenB);
        replace_all(tempDesc,"[c]",chosenC);

        printOut<<tempDesc<<endl;
    }
    else
    {
        printOut<<description;
    }
    printOut<<endl;
    return printOut.str();
}


