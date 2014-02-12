#ifndef LOCATIONLOADER_H
#define LOCATIONLOADER_H

#include "location.h"

class LocationLoader
{
public:
    LocationLoader(std::vector<Location*> *_locations, std::string filename);

    void loadfile(std::string filename);
    void testString(std::string line, std::string &currentLocation);

    Location* getLocation(std::string name);
    Location* createLocation(std::string name);

private:
    std::string vectorToString(std::vector<std::string> vec, int start, int end);

    std::vector<Location*> *locations;
};

#endif // LOCATIONLOADER_H
