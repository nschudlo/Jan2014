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
    director = Director::Instance();

    name = "InterrogateGangMember";
    description = "No description";
    failedOptConditions=0;
    used=false;

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

void Story::setUsed(bool _used){
    used = _used;}

bool Story::beenUsed(){
    return used;}

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

vector<Condition*> Story::getChanges(){
    return changes;}

void Story::addPreCondition(string precondition){
    Condition* tempCond = new Condition(precondition);
    conds.push_back(tempCond);
    failedOptConditions++;
}

void Story::addMPreCondition(string precondition)
{
    Condition* tempCond = new Condition(precondition);
    condsM.push_back(tempCond);
}

void Story::addTrigger(string trigger)
{
    Condition* tempCond = new Condition(trigger);
    triggers.push_back(tempCond);
}

void Story::divideConditions()
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
}




void Story::evaluateMandatory()
{
    evaluator->checkMandatory(&aCondsM,&aMand);
    evaluator->checkMandatory(&bCondsM,&bMand);
    evaluator->checkMandatory(&cCondsM,&cMand);

    //Go through each mandatory set condition and evaluate fulfillment
    //If fullfilled add to setCountM
    setCountM=0;
    for(int index=0; index<(int)setCondsM.size();index++)
        if(evaluator->checkConditionSet(setCondsM.at(index)))
            setCountM++;
}

int Story::evaluateOptional()
{
    //evaluator returns number of fulfilled conditions
    aCount = evaluator->checkOptional(&aConds, &aMand, &aOpt);
    bCount = evaluator->checkOptional(&bConds, &bMand, &bOpt);
    cCount = evaluator->checkOptional(&cConds, &cMand, &cOpt);

    //Go through each optional set condition and evaluate fulfillment.
    //If fullfilled add to setCount
    setCount=0;
    for(int index=0; index<(int)setConds.size();index++)
        if(evaluator->checkConditionSet(setConds.at(index)))
            setCount++;

    //Returns the number of conditions that will need goals
    //created in order for every condition to be met
    failedOptConditions = conds.size()-(aCount+bCount+cCount+setCount);
    return failedOptConditions;
}

/*
 *  Divides the conditions into variable groupings and evaluates the mandatory
 *  conditions. The Person objects which fulfill the a, b, and c mandatory
 *  conditions are put into the respective vectors. This function will return
 *  false if any of the required conditions can not be fulfilled. Otherwise return
 *  true, indicating the story fulfills all mandatory conditions.
 */
bool Story::evaluatePre()
{
    //Seperate the conds and condsM into a, b, c, and set vectors
    divideConditions();

    //Clear the vectors of People who fit the
    //mandatory a, b, and c conditions
    aMand.clear();
    bMand.clear();
    cMand.clear();

    //Clear the vectors of People who fit the
    //optional a, b, and c conditions
    aOpt.clear();
    bOpt.clear();
    cOpt.clear();

    //Dont clear these? Because we want to maintain them for the
    //goals currently in the goal queue
    //chosenA.clear();
    //chosenB.clear();
    //chosenC.clear();

    //Evaluate the mandatory conditions
    evaluateMandatory();

    //Check if mandatory requirements are met with current people
    //If this returns true then this story is possible to achieve
    //with goals, if not already possible
    if(aCondsM.size()>0)
        if(aMand.size()==0)
            return false;

    if(bCondsM.size()>0)
        if(bMand.size()==0)
            return false;

    if(cCondsM.size()>0)
        if(cMand.size()==0)
            return false;

    if(setCondsM.size()>0)
        if(setCountM==0)
            return false;

    return true;

}

void Story::chooseVariablePeople()
{
    //Evaluate the optional conditions. Returns the number of
    //conditions the variables do not fulfill
    //failedOptConditions = evaluateOptional();


    //If there are any people in the optional people vectors then
    //they at least passed the mandatory screening. A random is chosen
    //from the list as the representative of that variable. The random
    //process could be improved by selecting based on which conditions
    //failed. Also, need to make sure the a, b, and c people are not the
    //same
    if(((int)aOpt.size())>0)
    {
        chosenA = aOpt.at(rand()%(int)aOpt.size())->getName();
    }else if(((int)aMand.size())>0) //This covers cases where no optional conditions exist
    {
        chosenA = aMand.at(rand()%(int)aMand.size())->getName();
    }


    if((int)bOpt.size()>0)
    {
        chosenB = bOpt.at(rand()%(int)bOpt.size())->getName();
    }else if(((int)bMand.size())>0) //This covers cases where no optional conditions exist
    {
        chosenB = bMand.at(rand()%(int)bMand.size())->getName();
    }


    if((int)cOpt.size()>0)
    {
        chosenC = cOpt.at(rand()%(int)cOpt.size())->getName();
    }else if(((int)cMand.size())>0) //This covers cases where no optional conditions exist
    {
        chosenC = cMand.at(rand()%(int)cMand.size())->getName();
    }


    //Attempt to add the goal to the director goal queue
    //The director is responsible for not double adding the goal

    //This is the reevaluators job-->//Loop through all of a conditions to find any the chosenA doesnt have
    for(int index=0;index<(int)aConds.size();index++)
    {
        //Set Variable person to chosenA for all a conditions
        aConds.at(index)->setVariablePerson(chosenA);
        //if(!aConds.at(index)->hasPerson(chosenA))
        //    director->addStoryGoal(aConds.at(index));
    }

    for(int index=0; index<(int)bConds.size();index++)
    {
        //Set Variable person to chosenB for all b conditions
        bConds.at(index)->setVariablePerson(chosenB);
       // if(!bConds.at(index)->hasPerson(chosenB))
       //     director->addStoryGoal(bConds.at(index));
    }

    for(int index=0; index<(int)cConds.size();index++)
    {
        //Set Variable person to chosenC for all c conditions
        cConds.at(index)->setVariablePerson(chosenC);
       // if(!cConds.at(index)->hasPerson(chosenC))
       //     director->addStoryGoal(cConds.at(index));
    }

    for(int index=0; index<(int)triggers.size();index++)
    {
        if(triggers.at(index)->isA())
            triggers.at(index)->setVariablePerson(chosenA);
        else if(triggers.at(index)->isB())
            triggers.at(index)->setVariablePerson(chosenB);
        else if(triggers.at(index)->isC())
            triggers.at(index)->setVariablePerson(chosenC);
    }

    for(int index=0; index<(int)changes.size();index++)
    {
        if(changes.at(index)->isA())
            changes.at(index)->setVariablePerson(chosenA);
        else if(changes.at(index)->isB())
            changes.at(index)->setVariablePerson(chosenB);
        else if(changes.at(index)->isC())
            changes.at(index)->setVariablePerson(chosenC);
    }

}

void Story::checkStoryGoals()
{
    failedOptConditions=0;
    //Loop through all optional conditions
    for(int index=0; index<(int)conds.size();index++)
    {
        //If the condition comes back unfulfilled, add it to the
        //goals queue
        if(!evaluator->checkConditionSet(conds.at(index)))
        {
            director->addStoryGoal(conds.at(index));
            failedOptConditions++;
        }
    }
}

bool Story::reEvaluate()
{
    //Redivide the conditions
    //divideConditions();

    //Evaluate all the preconditions. Modified failedOptConditions
    //with new count of number of unfulfilled conditions
    //evaluateOptional()
    checkStoryGoals();

    //If this is true, every precondition is met
    preEvaluation = failedOptConditions==0;
    //if(failedOptConditions == 0)//(int)aConds.size()+(int)bConds.size()+(int)cConds.size()+(int)setConds.size())
    //    preEvaluation=true;
    //else
    //    preEvaluation=false;
    return preEvaluation;
}

/*
 *  Checks if any of the triggers is true
 */
bool Story::checkTriggers()
{
    for(int index=0; index<(int)triggers.size();index++)
    {
        if(evaluator->checkConditionSet(triggers.at(index)))
            return true;
    }
    return false;
}

/*
 *  Function takes a goal condition and sets the variable people from
 *  that goal. It then checks if the mand functions would work. If not
 *  the variables are reset and this story cannot be used.
 */
bool Story::setGoal(Condition *goalCondition)
{
    //determine which variable is to be set
    int pos = goalCondition->getVariablePosition();

    //If no variables then return true
    if(pos==0)
        return true;


    //search the changes for the matching one
    for(int index=0;index<(int)changes.size();index++)
    {
        if(compareConditions(goalCondition,changes.at(index)))
        {
            if(changes.at(index)->isA())
            {
                if(pos==1)
                    this->chosenA=goalCondition->getVal1();
                else
                    this->chosenA=goalCondition->getVal2();

            }
            else if(changes.at(index)->isB())
            {
                if(pos==1)
                    this->chosenB=goalCondition->getVal1();
                else
                    this->chosenB=goalCondition->getVal2();
            }
            else if(changes.at(index)->isC())
            {
                if(pos==1)
                    this->chosenC=goalCondition->getVal1();
                else
                    this->chosenC=goalCondition->getVal2();
            }
        }
    }

    //After the chosen variable is selected, check if mandatory
    //conditions can be met with this new variable. If not, reset
    //and resturn false
    if(!evaluatePre())
    {
        chosenA.clear();
        chosenB.clear();
        chosenC.clear();
        return false;
    }
    return true;

}

/*
 *  Compare two conditions for the same goal. Goals are considered the same
 *  if all their values are the same, except for a substitution in the variable
 *  location.
 */
bool Story::compareConditions(Condition *condition1, Condition *condition2)
{
    if(condition1->getType() != condition2->getType())
        return false;
    if(condition1->getEvaluationBool() != condition2->getEvaluationBool())
        return false;

    int variablePosition1 = condition1->getVariablePosition();
    int variablePosition2 = condition2->getVariablePosition();

    if(variablePosition1!=variablePosition2)
        return false;

    //If they both share val1 as their variable position, dont compare val1
    if(variablePosition1==1)
        if(condition1->getVal2()!=condition2->getVal2())
            return false;

    //If they both share val2 as their variable position, dont compare val2
    if(variablePosition1==2)
        if(condition1->getVal1()!=condition2->getVal1())
            return false;

    //If they both don't have a variable, compare both variables
    if(variablePosition1==0)
    {
        if(condition1->getVal1()!=condition2->getVal1())
            return false;
        if(condition1->getVal2()!=condition2->getVal2())
            return false;
    }

    //If they are the same condition, except a possible variable, return true
    return true;
}

string Story::printOut()
{
    ostringstream printOut;

    printOut<<"Story: "<<name<<endl;

    for(int index=0; index<(int)condsM.size();index++)
        printOut<<"    MPreconditions: "<<condsM.at(index)->printOut()<<endl;

    for(int index=0; index<(int)conds.size();index++)
        printOut<<"    Preconditions: "<<conds.at(index)->printOut()<<endl;

    for(int index=0; index<(int)triggers.size();index++)
        printOut<<"    Triggers: "<<triggers.at(index)->printOut()<<endl;

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
        printOut<<"Number of unfulfilled conditions: "<<failedOptConditions<<endl;
        printOut<<description;
    }
    printOut<<endl;
    return printOut.str();
}


