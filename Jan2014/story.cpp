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
    Condition* tempCond = new Condition(precondition);
    conds.push_back(tempCond);

    /*
    if(tempCond->isA())
        aConds.push_back(tempCond);
    else if(tempCond->isB())
        bConds.push_back(tempCond);
    else if(tempCond->isC())
        cConds.push_back(tempCond);
    else
        setConds.push_back(tempCond);
        */
}

void Story::addMPreCondition(string precondition)
{
    Condition* tempCond = new Condition(precondition);
    condsM.push_back(tempCond);

    /* if(tempCond->isA())
        aCondsM.push_back(tempCond);
    if(tempCond->isB())
        bCondsM.push_back(tempCond);
    if(tempCond->isC())
        cCondsM.push_back(tempCond);
    else
        setCondsM.pushBack(tempCond);
        */
}

void Story::divideConditions(int typeFlag)
{
    //Clear all current lists and re-divide the conditions. This is done in the case
    //that any condition has been changed from a variable condition to a set condition
    //Ex-if paul was chosen to represent a and missing conditions of paul being a were
    //sent to the goal queue, that condition would no longer be in the aConds list but
    //rather the setConds list for evaluation.

    aCondsM.clear();
    bCondsM.clear();
    cCondsM.clear();
    setCondsM.clear();
    aConds.clear();
    bConds.clear();
    cConds.clear();
    setConds.clear();

    // if(typeFlag==0)//Mandatory
    // {
    for(int index=0; index<(int)condsM.size();index++)
    {
        if(condsM.at(index)->isA())
            aCondsM.push_back(condsM.at(index));
        else if(condsM.at(index)->isB())
            bCondsM.push_back(condsM.at(index));
        else if(condsM.at(index)->isC())
            cCondsM.push_back(condsM.at(index));
        else
            setCondsM.push_back(condsM.at(index));
    }
    // }
    // else//Optional
    // {
    for(int index=0; index<(int)conds.size();index++)
    {
        if(conds.at(index)->isA())
            aConds.push_back(conds.at(index));
        else if(conds.at(index)->isB())
            bConds.push_back(conds.at(index));
        else if(conds.at(index)->isC())
            cConds.push_back(conds.at(index));
        else
            setConds.push_back(conds.at(index));
    }
    //  }
}

void Story::addChanges(string change){
    changes.push_back(new Condition(change));}

std::vector<Person*> Story::getAMand(){
    return aMand;}

std::vector<Person*> Story::getBMand(){
    return bMand;}

std::vector<Person*> Story::getCMand(){
    return cMand;}

std::vector<Person*> Story::getAOptional(){
    return aOpt;}

std::vector<Person*> Story::getBOptional(){
    return bOpt;}

std::vector<Person*> Story::getCOptional(){
    return cOpt;}

void Story::evaluateMandatory()
{
    evaluator->checkMandatory(&aCondsM,&aMand);
    evaluator->checkMandatory(&bCondsM,&bMand);
    evaluator->checkMandatory(&cCondsM,&cMand);

    //Need to evaluate the setCondsM;
}

int Story::evaluateOptional()
{
    int count=0;
    count += evaluator->checkOptional(&aConds, &aMand, &aOpt);
    count += evaluator->checkOptional(&bConds, &bMand, &bOpt);
    count += evaluator->checkOptional(&cConds, &cMand, &cOpt);

    //Need to evaluate the setConds
    for(int index=0; index<(int)setConds.size();index++)
        if(evaluator->checkConditionSet(setConds.at(index)))
            count++;

    return count;
}

bool Story::evaluatePre()
{
    divideConditions(1);

    aMand.clear();
    bMand.clear();
    cMand.clear();

    aOpt.clear();
    bOpt.clear();
    cOpt.clear();

    //Dont clear these? Because we want to maintain them for the
    //goals currently in the goal queue
    //chosenA.clear();
    //chosenB.clear();
    //chosenC.clear();


    evaluateMandatory();
    int trueOptConditions = evaluateOptional();




    if(((int)aOpt.size())>0)
    {
        chosenA = aOpt.at(rand()%(int)aOpt.size())->getName();
    }
    if((int)bOpt.size()>0)
    {
        chosenB = bOpt.at(rand()%(int)aOpt.size())->getName();
    }
    if((int)cOpt.size()>0)
    {
        chosenC = cOpt.at(rand()%(int)aOpt.size())->getName();
    }

    //If this is true, every precondition is met
    if(trueOptConditions == (int)aConds.size()+(int)bConds.size()+(int)cConds.size()+(int)setConds.size())
    {
        preEvaluation=true;
        //returning true tells the director everything is good
        return true;
    }
    else
    {
        preEvaluation=false;

        //Attempt to add the goal to the director goal queue
        //The director is responsible for not double adding the goal

        //Loop through all of a conditions to find any the chosenA doesnt have
        for(int index=0;index<(int)aConds.size();index++)
        {
            //Set Variable person to chosenA for all a conditions
            aConds.at(index)->setVariablePerson(chosenA);
            if(!aConds.at(index)->hasPerson(chosenA))
                //Add to director
                true;
        }

        for(int index=0; index<(int)bConds.size();index++)
        {
            //Set Variable person to chosenB for all b conditions
            bConds.at(index)->setVariablePerson(chosenB);
            if(!bConds.at(index)->hasPerson(chosenB))
                //Add to director
                true;
        }

        for(int index=0; index<(int)cConds.size();index++)
        {
            //Set Variable person to chosenC for all c conditions
            cConds.at(index)->setVariablePerson(chosenC);
            if(!cConds.at(index)->hasPerson(chosenC))
                //Add to director
                true;
        }

    }
    return false;
}

string Story::printOut()
{
    ostringstream printOut;

    printOut<<"Story: "<<name<<endl;

    for(int index=0; index<(int)condsM.size();index++)
        printOut<<"    MPreconditions: "<<condsM.at(index)->printOut()<<endl;

    for(int index=0; index<(int)conds.size();index++)
        printOut<<"    Preconditions: "<<conds.at(index)->printOut()<<endl;

    printOut<<endl;

    for(int index=0; index<(int)changes.size();index++)
        printOut<<"    Change: "<<changes.at(index)->printOut()<<endl;

    printOut<<endl;

    for(int index=0; index<(int)aMand.size();index++)
        printOut<<"a mandatory has: "<<aMand.at(index)->getName()<<endl;

    for(int index=0; index<(int)bMand.size();index++)
        printOut<<"b mandatory has: "<<bMand.at(index)->getName()<<endl;

    for(int index=0; index<(int)cMand.size();index++)
        printOut<<"c mandatory has: "<<cMand.at(index)->getName()<<endl;

    for(int index=0; index<(int)aOpt.size();index++)
        printOut<<"a optional has: "<<aOpt.at(index)->getName()<<endl;

    for(int index=0; index<(int)bOpt.size();index++)
        printOut<<"b optional has: "<<bOpt.at(index)->getName()<<endl;

    for(int index=0; index<(int)cOpt.size();index++)
        printOut<<"c optional has: "<<cOpt.at(index)->getName()<<endl;

    printOut<<endl;

    if(preEvaluation)
    {
        string tempDesc=description;

        if(((int)aOpt.size())>0)
        {
            printOut<<"Chosen a is: ";
            //chosenA = aOpt.at(rand()%(int)aOpt.size())->getName();
            printOut<<chosenA<<endl;
        }
        if((int)bOpt.size()>0)
        {
            printOut<<"Chosen b is: ";
            //chosenB = bOpt.at(rand()%(int)aOpt.size())->getName();
            printOut<<chosenB<<endl;
        }
        if((int)cOpt.size()>0)
        {
            printOut<<"Chosen c is: ";
            //chosenC = cOpt.at(rand()%(int)aOpt.size())->getName();
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


