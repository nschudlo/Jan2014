#include "worldobject.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

using namespace std;

WorldObject::WorldObject(std::string name)
{
    trim(name);
    to_lower(name);
    this->name = name;
    this->maxItemsPossible = 1;
    cout<< "Created an object: " << this->name << endl;
}

std::string WorldObject::getName(){
   return this->name;}

void WorldObject::addActionDo(Action *act){
    actionsDo.push_back(act);}

void WorldObject::addActionGet(Action *act){
    actionsGet.push_back(act);}

void WorldObject::setMaxItemsPossible(int max){
    maxItemsPossible = max;}

int WorldObject::getMaxItemsPossible(){
    return maxItemsPossible;}

void WorldObject::listActions()
{
    cout<<"Actions Possible To Do:";

    for(unsigned int f=0; f < actionsDo.size(); f++)
    {
       try{ cout<<" "<<actionsDo.at(f)->getName();}
        catch(exception e){cout<<" none";}
    }
    cout<<endl;

    cout<<"Actions Possible To Receive:";

    for(unsigned int f=0; f < actionsGet.size(); f++)
    {
       try{ cout<<" "<<actionsGet.at(f)->getName();}
        catch(exception e){cout<<" none";}
    }
    cout<<endl;
}

vector<Action*> WorldObject::getActionsDo()
{
    return actionsDo;
}

vector<Action*> WorldObject::getActionsGet()
{
    return actionsGet;
}

bool WorldObject::canActionDo(std::string name)
{
    for(unsigned int f=0; f < actionsDo.size(); f++)
    {
       try{
            if(actionsDo.at(f)->getName()==name)
                return true;
        }
        catch(exception e){cout<<" none";}
    }
    return false;
}

bool WorldObject::canActionGet(std::string name)
{
    for(unsigned int f=0; f < actionsGet.size(); f++)
    {
       try{
            if(actionsGet.at(f)->getName()==name)
                return true;
        }
        catch(exception e){cout<<" none";}
    }
    return false;
}

void WorldObject::removeActionDo(std::string act)
{
    for(int index=0; index<(int)actionsDo.size();index++)
    {
        if(actionsDo.at(index)->getName().compare(act)==0)
        {
            actionsDo.erase(actionsDo.begin()+index);
        }
    }
}

void WorldObject::removeActionGet(std::string act)
{
    for(int index=0; index<(int)actionsGet.size();index++)
    {
        if(actionsGet.at(index)->getName().compare(act)==0)
        {
            actionsGet.erase(actionsGet.begin()+index);
        }
    }
}


