#include "worldobject.h"
#include <iostream>
#include <string>

using namespace std;

WorldObject::WorldObject(std::string name)
{
    this->name = name;
    cout<< "Created an object: " << this->name << endl;
}

std::string WorldObject::getName()
{
   return this->name;
}
