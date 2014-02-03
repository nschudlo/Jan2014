#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H
#include<string>

class WorldObject
{
public:
    WorldObject(std::string name);

    std::string getName();

private:
    std::string name;

};

#endif // WORLDOBJECT_H
