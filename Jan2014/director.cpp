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

using namespace std;

Director* Director::m_pInstance = NULL;

Director* Director::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Director;
    return m_pInstance;
}

void Director::runStoryLoop()
{
    /*
    for(all current goals (X))
    {
        if((X) is author goal)
        {
            if((X) is true)
                trigger authorial event
            else
                if(no other goals before authorial)
                {
                    find all stories with result = authorial goal
                    pick one (Y)
                    for(all of (Y)'s pre that are false (YPRE))
                    {
                        create goals to make (YPRE) true
                    }
                }
        }
        else if((X) is not author goal) //making it a story goal
        {
            if((X)'s pre are all true)
                trigger story event
            else
            {
                for(all of (X)'s pre that are false (XPRE))
                {
                    if((XPRE) has goal already)
                        add 1 to it
                    else
                        add (XPRE) to the goals
                }

            }
        }
    }
    */
    //for(all current goals (X))
    for(int goalsIndex=0; goalsIndex<(int)storyGoals.size();goalsIndex++)
    {
        StoryGoal* X = storyGoals.at(goalsIndex);

        if(X->isAuthorGoal())
        {

        }
        else //Not author goal
        {

        }

    }


}


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
    else
    {
        cout<<"ERROR: type +"<<type<<"+ not found"<<endl;
    }
}
vector<StoryGoal*> Director::getGoals(){
    return storyGoals;}

vector<Story*> Director::getStories(){
    return stories;}

StoryGoal* Director::getGoal(std::string name)
{
    for(int index=0;index<(int)storyGoals.size();index++)
    {
        if(storyGoals.at(index)->getName()==name)
            return storyGoals.at(index);
    }
    return 0;
}

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
