#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include "person.h"

class Person;

class Location
{
public:
    Location();
    Location(std::string _location);

    void addGoTo(Location* loc);
    void addComeFrom(Location* loc);

    std::string getName();

    std::vector<Location*> getGoTo();
    std::vector<Location*> getComeFrom();

    bool canGoTo(Location* loc);
    bool canGoTo(std::string loc);
    bool canComeFrom(Location* loc);
    bool canComeFrom(std::string loc);

    void addPerson(Person* person);
    int removePerson(Person *person);
    std::vector<Person*> getCurrentPeople();

private:
    std::string country;
    std::string city;
    std::string location;

    std::vector<Location*> goToLocations;
    std::vector<Location*> comeFromLocations;

    std::vector<Person*> peopleAtLocation;
};

#endif // LOCATION_H
