#include "director.h"
#include <iostream>
#include <fstream>

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

using namespace std;

Director* Director::m_pInstance = NULL;

Director* Director::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Director;
    return m_pInstance;
}


void Director::loadGoals(string filename)
{
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

    //Count the number of parameters
    //int numParams = std::distance(tok.begin(),tok.end())-1;

    //This changes all uppercase in any names to lower
    //to_lower(info[0]);

    if(type=="Goal")
    {
        currentGoal = new StoryGoal();
    }
    else if(type=="Name")
    {
        currentGoal->setName(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="Person")
    {
        currentGoal->addPerson(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="ValueEnd")
    {
        currentGoal->addChanges(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="EndGoal")
    {
        currentGoal->completeGoal();
        storyGoals.push_back(currentGoal);
        storyGoals.back()->printOut();
    }
    else
    {
        cout<<"ERROR: type +"<<type<<"+ not found"<<endl;
    }
}

void Director::loadStories(string filename)
{
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

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep("<> ");
    tokenizer tok(line, sep);
    tokenizer::iterator tokenIterator = tok.begin();


    //tokenize the line
    //boost::tokenizer<> tok(line);
    //boost::tokenizer<>::iterator tokenIterator=tok.begin();

    //Pull out the <type> from the line
    string type = *tokenIterator++;

    //Assign the remaining tokens to the info string vector
    vector<string> info;
    info.assign(tokenIterator, tok.end());

    //Count the number of parameters
    //int numParams = std::distance(tok.begin(),tok.end())-1;

    //This changes all uppercase in any names to lower
    //to_lower(info[0]);

    if(type=="Story")
    {
        currentStory = new Story();
    }
    else if(type=="Name")
    {
        currentStory->setName(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="Description")
    {
        currentStory->setDescription(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="Precondition")
    {
        currentStory->addPreCondition(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="ValueEnd")
    {
        currentStory->addChanges(vectorToString(info,0,(int)info.size()));
    }
    else if(type=="EndGoal")
    {
        currentStory->evaluatePre();
        stories.push_back(currentStory);
        stories.back()->printOut();
    }
    else
    {
        cout<<"ERROR: type +"<<type<<"+ not found"<<endl;
    }
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
