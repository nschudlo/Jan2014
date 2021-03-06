#include "person.h"
#include "worldobject.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;
using namespace std;


Person::Person(){}

Person::Person(string name, int gender)
{
    trim(name);
    to_lower(name);
    this->name = name;
    this->mood = 5;
    this->gender = gender;
    this->health = 100;
    this->money = 200;
    this->currentLocation=0;

    this->policeRep=0;
    this->mobRep=0;
    this->policeWanted=0;
    this->mobWanted=0;

    this->storyRank=0;
    this->storyRole=1;
    this->mainChar=false;

    cout<<"Created a person named: "<<this->name<<endl;
}


void Person::listRelationships()
{
    for(unsigned int index=0; index<this->relationships.size(); index++)
    {
        try{
            relationships.at(index)->printRelationship();
        }catch(exception e){cout<<"No more relationships \n";}
    }
}

void Person::listActions()
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


bool Person::canActionDo(std::string name)
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

bool Person::canActionGet(std::string name)
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



Relationship* Person::getRelationship(string name)
{
    for (unsigned int index=0; index<relationships.size();index++)
    {
        try{
            if(/*relationships.at(index)->getOne()==name || */relationships.at(index)->getTwo()==name)
                return relationships.at(index);
        }catch(exception e){cout<<"No more items \n";}
    }

    return 0;
}

void Person::removeRelationship(string name)
{
    for(int index=0; index<(int)relationships.size();index++)
    {
        if(relationships.at(index)->getTwo()==name)
        {
            relationships.erase(relationships.begin()+index);
            cout<<"Removed Relationship: "<<this->name<<", "<<name<<endl;
            return;
        }
    }
    return;
}


int Person::isHolding(string objectName)
{
    int holding=0;

    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(itemsHeld.at(index)->getName()==objectName)
                holding++;
        }catch(exception e){cout<<"No more items \n";}
    }
    return holding;
}

void Person::dropAll(string object)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(itemsHeld.at(index)->getName()==object)
            {
                itemsHeld.erase(itemsHeld.begin()+index);
                holding++;
                index--;
            }
        }catch(exception e){cout<<"No more items \n";}
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::dropItem(string object)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(this->itemsHeld.at(index)->getName()==object)
            {
                itemsHeld.erase(itemsHeld.begin()+index);
                holding++;
                break;
            }
        }catch(exception e){cout<<"No more items \n";}
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::dropItem(string object, int count)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        if(holding < count)
        {
            try{
                if(this->itemsHeld.at(index)->getName()==object)
                {

                    itemsHeld.erase(itemsHeld.begin()+index);
                    holding++;

                }
            }catch(exception e){cout<<"No more items \n";}
        }
        else
            break;
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::printAllItems()
{
    cout<<"Items Held:";

    for(unsigned int f=0; f < itemsHeld.size(); f++)
    {
        try{ cout<<" "<<itemsHeld.at(f)->getName();}
        catch(exception e){cout<<" none";}
    }
    cout<<endl;
}

void Person::printDetails()
{
    cout<<"-----------------------"<<endl;
    cout<<"Detailed Info For: "<<this->name<<endl;
    cout<<"\tGender: "<<gender<<endl;
    cout<<"\t";
    printAllItems();
    cout<<"\t";
    listActions();
    cout<<"\n\t";
    listRelationships();
    cout<<endl;
    cout<<"-----------------------"<<endl;


}

void Person::setCurrLocation(Location *loc)
{
    Person * temp = this;
    if(currentLocation != 0)
        currentLocation->removePerson(temp);
    currentLocation=loc;
    currentLocation->addPerson(temp);
}


void Person::setName(std::string newName){
    this->name = newName;}

string Person::getName(){
    return this->name;}

int Person::getGender(){
    return this->gender;}

int Person::getMoney(){
    return money;}

void Person::setMoney(int _mon){
    money = _mon;}

int Person::getHealth(){
    return health;}

void Person::setHealth(int _health){
    health = _health;}

int Person::getMood(){
    return mood;}

void Person::setMood(int _mood){
    mood = _mood;}

void Person::addRelationship(Relationship *rel){
    relationships.push_back(rel);}

void Person::addActionDo(Action *act){
    actionsDo.push_back(act);}

void Person::addActionGet(Action *act){
    actionsGet.push_back(act);}

vector<WorldObject*> Person::getItemsHeld(){
    return this->itemsHeld;}

void Person::holdItem(WorldObject *object){
    this->itemsHeld.push_back(object);}

vector<Action*> Person::getActionsDo(){
    return actionsDo;}

vector<Action*> Person::getActionsGet(){
    return actionsGet;}

Location* Person::getCurrLocation(){
    return currentLocation;}

std::vector<Relationship*> Person::getRelationships(){
    return relationships;}


//Cops and Robbers Story Functions
void Person::setPoliceRep(int rep){
    policeRep=rep;
    recheckStoryRank();}

void Person::setMobRep(int rep){
    mobRep=rep;
    recheckStoryRank();}

void Person::setPoliceWanted(int wanted){
    policeWanted=wanted;
    recheckStoryRank();}

void Person::setMobWanted(int wanted){
    mobWanted=wanted;
    recheckStoryRank();}

int Person::getPoliceRep(){
    return policeRep;}

int Person::getMobRep(){
    return mobRep;}

int Person::getPoliceWanted(){
    return policeWanted;}

int Person::getMobWanted(){
    return mobWanted;}

void Person::setStoryRank(int rank){
    storyRank=rank;
    recheckStoryRank();}

int Person::getStoryRank(){
    return storyRank;}

void Person::setStoryRole(int role){
    storyRole=role;}

int Person::getStoryRole(){
    return storyRole;}

bool Person::isMainChar(){
    return mainChar;}

void Person::setIsMainChar(bool val){
    mainChar=val;}

enum ranking{Police=3,Vigilante=2,Mobster=1,Citizen=0};

void Person::recheckStoryRank()
{
    //if(storyRank != Citizen)
    if(mainChar)
    {
        if(policeRep > 5)
        {
            if(policeWanted < 5)
                storyRank = Police;
            else
                storyRank = Vigilante;
        }
        else //PoliceRep < 5
        {
            if(mobRep>5)
            {
                if(mobWanted<5)
                    storyRank=Mobster;
                else
                    storyRank=Vigilante;
            }
            else
            {
                storyRank=Vigilante;
            }
        }
    }
}
