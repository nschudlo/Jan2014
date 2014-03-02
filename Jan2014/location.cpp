#include "location.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

Location::Location(){}

Location::Location(std::string _location)
{
    //country = _country;
    //city = _city;
    trim(_location);
    location = _location;
}

std::string Location::getName(){
    return location;}

void Location::addGoTo(Location * loc){
    goToLocations.push_back(loc);}

void Location::addComeFrom(Location *loc){
    comeFromLocations.push_back(loc);}

std::vector<Location*> Location::getGoTo(){
    return goToLocations;}

std::vector<Location*> Location::getComeFrom(){
    return comeFromLocations;}

bool Location::canGoTo(Location *loc){
    return canGoTo(loc->getName());}

bool Location::canGoTo(std::string loc){
    for(unsigned int f=0; f < goToLocations.size(); f++)
    {
       try{
            if(goToLocations.at(f)->getName()==loc)
                return true;
        }catch(std::exception e){std::cout<<" none";}
    }
    return false;
}

bool Location::canComeFrom(Location *loc){
    return canComeFrom(loc->getName());}

bool Location::canComeFrom(std::string loc){
    for(unsigned int f=0; f < comeFromLocations.size(); f++)
    {
       try{
            if(comeFromLocations.at(f)->getName()==loc)
                return true;
        }catch(std::exception e){std::cout<<" none";}
    }
    return false;
}

void Location::addPerson(Person *person)
{
    peopleAtLocation.push_back(person);
}

int Location::removePerson(Person *person)
{
    for(int index=0; index<(int)peopleAtLocation.size();index++)
    {
        if(peopleAtLocation.at(index)->getName()==person->getName())
        {
            peopleAtLocation.erase(peopleAtLocation.begin()+index);
            return 1;
        }
    }
    return 0;
}

std::vector<Person*> Location::getCurrentPeople(){
    return peopleAtLocation;}

