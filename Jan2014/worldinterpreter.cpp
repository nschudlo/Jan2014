#include "worldinterpreter.h"
#include "controller.h"

WorldInterpreter::WorldInterpreter()
{
    controller = Controller::Instance();

    //These may not be necessary
    locations = controller->getLocationVector();
    worldObjects = controller->getItemVector();
    people = controller->getPeopleVector();
    actions = controller->getActionVector();
}

bool WorldInterpreter::personIsAt(std::string person, std::string location)
{
    int comp = controller->getPerson(person)->getCurrLocation()->getName().compare(location);
    return true;
}
