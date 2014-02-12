#include "location.h"
#include <iostream>


Location::Location(std::string _location)
{
    //country = _country;
    //city = _city;
    location = _location;
}

std::string Location::getLocation(){
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
    return canGoTo(loc->getLocation());}

bool Location::canGoTo(std::string loc){
    for(unsigned int f=0; f < goToLocations.size(); f++)
    {
       try{
            if(goToLocations.at(f)->getLocation()==loc)
                return true;
        }catch(std::exception e){std::cout<<" none";}
    }
    return false;
}

bool Location::canComeFrom(Location *loc){
    return canComeFrom(loc->getLocation());}

bool Location::canComeFrom(std::string loc){
    for(unsigned int f=0; f < comeFromLocations.size(); f++)
    {
       try{
            if(comeFromLocations.at(f)->getLocation()==loc)
                return true;
        }catch(std::exception e){std::cout<<" none";}
    }
    return false;
}
