#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

class Location
{
public:
    Location(std::string _location);

    void addGoTo(Location* loc);
    void addComeFrom(Location* loc);

    std::string getLocation();

    std::vector<Location*> getGoTo();
    std::vector<Location*> getComeFrom();

    bool canGoTo(Location* loc);
    bool canGoTo(std::string loc);
    bool canComeFrom(Location* loc);
    bool canComeFrom(std::string loc);

private:
    std::string country;
    std::string city;
    std::string location;

    std::vector<Location*> goToLocations;
    std::vector<Location*> comeFromLocations;
};

#endif // LOCATION_H
