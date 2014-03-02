#include "action.h"
#include <string>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;


using namespace std;

Action::Action(string _name)
{
    trim(_name);
    to_lower(name);
    name = _name;
}

string Action::getName()
{
    return name;
}
