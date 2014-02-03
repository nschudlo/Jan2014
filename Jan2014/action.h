#ifndef ACTION_H
#define ACTION_H

#include <string>

class Action
{
public:
    Action(std::string _name);

    std::string getName();

private:
    std::string name;
};

#endif // ACTION_H
