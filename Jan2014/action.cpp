#include "action.h"
#include <string>


using namespace std;

Action::Action(string _name)
{
    name = _name;
}

string Action::getName()
{
    return name;
}
