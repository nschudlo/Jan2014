#include "director.h"
#include "condition.h"

#include <iostream>
#include <fstream>

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

#define AUTHORGOAL 1
#define STORYGOAL 0

#define IdealStoryCount 2

#define vecRemove(vec,index) vec.erase(vec.begin()+index)
#define vecRemove2(vec,index) vec->erase(vec->begin()+index)

using namespace std;

Director* Director::m_pInstance = NULL;

Director* Director::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Director();
    return m_pInstance;
}

Director::Director()
{
    evaluator = Evaluator::Instance();
    currentStory = NULL;
    activeStory = NULL;
}

void Director::runStoryLoop()
{

    changeMade=true;


    while(changeMade)
    {
        changeMade=false;
        //Set current story to null to start fresh. This value will be set
        //if any stories have their triggers active.

        //activeStory = NULL; <--THIS NEEDS TO HAPPEN SOMEWHERE
        triggerStories.clear();
        //for all stories in the story queue check if their triggers are active
        for(int sIndex=0; sIndex<(int)storyQueue.size();sIndex++)
        {
            Story* currStory = storyQueue.at(sIndex);
            if(currStory->reEvaluate())//checks optional story conditions and adds goals
            {
                triggerStories.push_back(currStory);//adds any stories with all conditions fulfilled
                if(currStory->checkTriggers())
                {
                    //Only run one story at a time
                    if(activeStory==NULL)
                    {
                        activeStory = currStory;
                        //Removed this line because when stories became the current story they were
                        //no longer seen as persuing the goal and therefore another story was selected
                        //to persue the goal. Not sure if removing will break something...
                        //vecRemove(storyQueue,sIndex--);
                    }
                }
            }
        }

        //Cycle the goals, first checking if they are fulfilled, and if not
        //looking to see if they have any stories in the queue which are
        //attempting to fulfill them
        vector<Condition*> unmetGoals;
        for(int gIndex=0; gIndex<(int)goalQueue.size();gIndex++)
        {
            Condition* currGoal = goalQueue.at(gIndex);
            bool matched = false;

            if(!evaluator->checkConditionSet(currGoal))
            {
                //Check the story queue for a story with this goal as the result
                for(int sIndex=0; sIndex<(int)storyQueue.size();sIndex++)
                {
                    Story* currStory = storyQueue.at(sIndex);
                    vector<Condition*> currChanges = currStory->getChanges();
                    for(int cIndex=0; cIndex<(int)currChanges.size();cIndex++)
                    {
                        if(compareConditionsSet(currGoal,currChanges.at(cIndex)))
                            matched=true;
                    }

                    if(matched)
                        break;
                }

                //If goal has no story trying to reach it, add it to the list
                if(!matched)
                    unmetGoals.push_back(currGoal);
            }
            else
                vecRemove(goalQueue,gIndex--);
        }

        //For each unmet goal find a story to reach it. The reason this wasn't
        //done as soon as a goal was deemed unmatched is because there is a
        //possibilty now to compare the stories being matched to the goals
        //and choosing one that fulfills multiple goals. Not what is going on, but still...
        for(int ugIndex=0; ugIndex<(int)unmetGoals.size();ugIndex++)
        {
            possibleStories.clear();
            //Adds matches to the possibleStories vector
            findStory(unmetGoals.at(ugIndex));

            bool test=true;
            if(possibleStories.size()>0)
            {

                int highestP = 0;
                std::vector<Story*> newList;
                //Slim the selection down to those with highest priority
                for(int pIndex=0; pIndex<(int)possibleStories.size();pIndex++)
                {
                    int currPriority = possibleStories.at(pIndex)->getPriority();
                    if( currPriority == highestP)
                    {
                        //add it to the new list
                        newList.push_back(possibleStories.at(pIndex));
                    }
                    else if(currPriority > highestP)
                    {
                        //clear new list and add this one
                        newList.clear();
                        newList.push_back(possibleStories.at(pIndex));
                        highestP = currPriority;
                    }
                }
                possibleStories = newList;

                while(test)
                {
                    //This is where we pick the story from the possible list
                    int randStory = rand() % possibleStories.size();
                    Story* goalMatch = possibleStories.at(randStory);
                    if(!goalMatch->setGoal(unmetGoals.at(ugIndex)))
                        vecRemove(unmetGoals,randStory);
                    else
                    {
                        goalMatch->evaluateOptional();
                        goalMatch->chooseVariablePeople();
                        if(goalMatch->reEvaluate())
                            triggerStories.push_back(goalMatch);
                        addToStoryQueue(goalMatch);
                        test=false;
                    }
                }
            }
            else
            {
                //Gotta make magic happen. There are no stories to reach this goal
                cout<<"ERROR: No story achieves the goal +"<<unmetGoals.at(ugIndex)->printOut()<<"+"<<endl;
            }
        }

    }

}

void Director::addStoryGoal(Condition *condition)
{
    for(int index=0; index<(int)goalQueue.size();index++)
    {
        //If this goal already exists, exit out
        if(condition->printOut()==goalQueue.at(index)->printOut())
            return;
    }
    //If this goal does not already exist, add it the goal list
    goalQueue.push_back(condition);
    changeMade=true;

}

void Director::addToStoryQueue(Story* story)
{
    storyQueue.push_back(story);
    story->setUsed(true);
    changeMade=true;
}

void Director::completeActiveStory()
{
    if(activeStory != NULL)
    {
        //Clear the story from the trigger list
        for(int index=0; index<(int)triggerStories.size();index++)
        {
            if(triggerStories.at(index)->getName() == activeStory->getName())
                vecRemove(triggerStories,index);


        }
        //Clear the story from the active list
        for(int index=0; index<(int)storyQueue.size();index++)
        {
            if(storyQueue.at(index)->getName() == activeStory->getName())
                vecRemove(storyQueue,index);
        }
        activeStory=NULL;
    }
}


/*
 *  Find a story which has an end value of the given condition
 */
void Director::findStory(Condition *condition)
{
    //cycle through every story - could be improved with categories
    for(int storyIndex=0; storyIndex<(int)stories.size(); storyIndex++)
    {
        Story* curr = stories.at(storyIndex);
        if(!curr->beenUsed())
        {
            vector<Condition*> currChanges = curr->getChanges();

            //Cycle through every change of the current story
            for(int changesIndex=0; changesIndex<(int)currChanges.size();changesIndex++)
            {
                Condition* currChange = currChanges.at(changesIndex);

                //Check if the current change is the same as the goal condition
                if(compareConditions(condition, currChange))
                    possibleStories.push_back(curr);
            }
        }
    }

    //Now we have a list of stories with change conditions the same as the given


}

/*
 *  Compare two conditions for the same goal. Goals are considered the same
 *  if all their values are the same, except for a substitution in the variable
 *  location.
 */
bool Director::compareConditions(Condition *condition1, Condition *condition2)
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

bool Director::compareConditionsSet(Condition *condition1, Condition *condition2)
{if(condition1->getType() != condition2->getType())
        return false;
    if(condition1->getEvaluationBool() != condition2->getEvaluationBool())
        return false;

    int variablePosition1 = condition1->getVariablePosition();
    int variablePosition2 = condition2->getVariablePosition();

    if(variablePosition1!=variablePosition2)
        return false;

    if(condition1->getVal2()!=condition2->getVal2())
        return false;

    if(condition1->getVal1()!=condition2->getVal1())
        return false;

    //If they are the same condition, except a possible variable, return true
    return true;

}
/*
void Director::loadGoals(string filename)
{
    cout<<"*****************"<<endl;
    cout<<"Clearing all current goals..."<<endl;

    storyGoals.clear();

    string line;
    ifstream file(filename.c_str());

    //Open the file
    if(file.is_open())
    {
        while(getline(file, line))
        {
            evaluateGoalLine(line);
        }
        file.clear();
        file.seekg(0,ios::beg);

        file.close();
    }
    else cout<<"Unable to open file "<<filename<<endl;

}

void Director::evaluateGoalLine(string line)
{

    //Skip comment lines and blank lines
    if(line[0] == '#' || line.empty())
        return;

    //tokenize the line
    boost::tokenizer<> tok(line);
    boost::tokenizer<>::iterator tokenIterator=tok.begin();

    //Pull out the <type> from the line
    string type = *tokenIterator++;

    //Assign the remaining tokens to the info string vector
    vector<string> info;
    info.assign(tokenIterator, tok.end());

    if(type=="Goal")
    {
        currentGoal = new StoryGoal();
        currentGoal->setType(AUTHORGOAL);
    }
    else if(type=="Name")
        currentGoal->setName(vectorToString(info,0,(int)info.size()));
    else if(type=="Person")
        currentGoal->addPerson(vectorToString(info,0,(int)info.size()));
    else if(type=="ValueEnd")
        currentGoal->addChanges(vectorToString(info,0,(int)info.size()));
    else if(type=="EndGoal")
    {
        currentGoal->completeGoal();
        storyGoals.push_back(currentGoal);
        cout<<"*****************"<<endl;
        cout<<"Added Goal:"<<endl;
        cout<<storyGoals.back()->printOut()<<endl;
        cout<<"*****************"<<endl;

    }
    else
    {
        cout<<"ERROR: type +"<<type<<"+ not found"<<endl;
    }

}
*/
void Director::loadStories(string filename)
{
    cout<<"*****************"<<endl;
    cout<<"Clearing all current stories..."<<endl;

    stories.clear();

    string line;
    ifstream file(filename.c_str());

    //Open the file
    if(file.is_open())
    {
        while(getline(file, line))
        {
            evaluateStoryLine(line);
        }
        file.clear();
        file.seekg(0,ios::beg);

        file.close();
    }
    else cout<<"Unable to open file "<<filename<<endl;
}

void Director::evaluateStoryLine(string line)
{
    //Skip comment lines and blank lines
    if(line[0] == '#' || line.empty())
        return;

    //Tokenize the line but only using the  < > and space as tokens
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep("<> ");
    tokenizer tok(line, sep);
    tokenizer::iterator tokenIterator = tok.begin();

    //Pull out the <type> from the line
    string type = *tokenIterator++;

    //Assign the remaining tokens to the info string vector
    vector<string> info;
    info.assign(tokenIterator, tok.end());

    if(type=="Story")
        currentStory = new Story();
    else if(type=="Name")
        currentStory->setName(vectorToString(info,0,(int)info.size()));
    else if(type=="Description")
        currentStory->setDescription(vectorToString(info,0,(int)info.size()));
    else if(type=="MPrecondition")
    {
        currentStory->addMPreCondition(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="Precondition")
    {
        currentStory->addPreCondition(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="Trigger")
    {
        currentStory->addTrigger(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="ValueEnd")
    {
        currentStory->addChanges(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="EndStory")
    {
        stories.push_back(currentStory);

        cout<<"*****************"<<endl;
        cout<<"Added Story:"<<endl;
        cout<<stories.back()->printOut();
        cout<<"*****************"<<endl;
    }
    else if(type=="Priority")
    {
        currentStory->setPriority(atoi(info.at(0).c_str()));
    }
    else
    {
        cout<<"ERROR: type +"<<type<<"+ not found"<<endl;
    }
}
std::vector<Condition *> Director::getGoalQueue(){
    return goalQueue;}

vector<Story*> Director::getStories(){
    return stories;}

vector<Story*> Director::getStoryQueue(){
    return storyQueue;}

vector<Story*> Director::getTriggerStories(){
    return triggerStories;}

Story* Director::getCurrentActiveStory(){
    return activeStory;}
/*
StoryGoal* Director::getGoal(std::string name)
{
    for(int index=0;index<(int)storyGoals.size();index++)
    {
        if(storyGoals.at(index)->getName()==name)
            return storyGoals.at(index);
    }
    return 0;

}
*/
Story* Director::getStory(std::string name)
{
    for(int index=0;index<(int)stories.size();index++)
    {
        if(stories.at(index)->getName()==name)
            return stories.at(index);
    }
    return 0;
}


string Director::vectorToString(vector<string> vec, int start, int end)
{
    if(end>(int)vec.size())
        end=vec.size();

    string output="";
    for(int index=start; index<(int)end; index++)
    {
        output = output+vec.at(index)+" ";
    }
    trim(output);
    //to_lower(output);
    return output;
}
