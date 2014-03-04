#include "worldinterpreter.h"
#include "controller.h"

using namespace std;

enum relationship{Parent=0, Child=1, Sibling=2, Married=3, Family=4, SO=5, Strangers=6,
                  Friends=7, Enemies=8, Teacher=9, Student=10, Working=11, Community=12};

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
    Person* per =controller->getPerson(person);
    if(per==0)
        return false;
    Location* loc = per->getCurrLocation();
    if(loc ==0)
        return false;

    return !loc->getName().compare(location);
}

bool WorldInterpreter::personIsAtSameLocationAs(std::string person1, std::string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Location* loc1 = per1->getCurrLocation();
    Location* loc2 = per2->getCurrLocation();
    if(loc1 == 0 || loc2 == 0)
        return false;

    return !loc1->getName().compare(loc2->getName());
}

bool WorldInterpreter::personIsHolding(string person, string object)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->isHolding(object);
}

bool WorldInterpreter::personCanDoAction(string person, string action)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return 0;
    return per->canActionDo(action);
}

bool WorldInterpreter::personCanGetAction(string person, string action)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return 0;
    return per->canActionGet(action);
}

bool WorldInterpreter::personHealthGreaterThan(string person, int healthValue)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getHealth() > healthValue;
}

bool WorldInterpreter::personHealthLessThan(string person, int healthValue)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getHealth() < healthValue;
}

bool WorldInterpreter::personIsMale(string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return 0;
    return !per->getGender();
}

bool WorldInterpreter::personIsFemale(string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return 0;
    return per->getGender();
}

bool WorldInterpreter::itemCanDoAction(string item, string action)
{
    WorldObject* object = controller->getItem(item);
    if(object==0)
        return false;
    return object->canActionDo(action);
}

bool WorldInterpreter::itemCanGetAction(string item, string action)
{
    WorldObject* object = controller->getItem(item);
    if(object==0)
        return false;
    return object->canActionGet(action);
}

bool WorldInterpreter::relationshipPositive(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getStrength()==2;
}

bool WorldInterpreter::relationshipNegative(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getStrength()==0;
}

bool WorldInterpreter::relationshipAverage(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getStrength()==1;
}

bool WorldInterpreter::relationshipParent(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Parent;
}

bool WorldInterpreter::relationshipChild(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Child;
}

bool WorldInterpreter::relationshipSibling(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Sibling;
}

bool WorldInterpreter::relationshipMarried(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Married;
}

bool WorldInterpreter::relationshipFamily(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Family;
}

bool WorldInterpreter::relationshipSO(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==SO;
}

bool WorldInterpreter::relationshipStrangers(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Strangers;
}

bool WorldInterpreter::relationshipFriends(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Friends;
}

bool WorldInterpreter::relationshipEnemies(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Enemies;
}

bool WorldInterpreter::relationshipTeacher(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Teacher;
}

bool WorldInterpreter::relationshipStudent(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Student;
}

bool WorldInterpreter::relationshipWorking(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Working;
}

bool WorldInterpreter::relationshipCommunity(string person1, string person2)
{
    Person* per1 = controller->getPerson(person1);
    Person* per2 = controller->getPerson(person2);
    if(per1==0 || per2==0)
        return false;

    Relationship* rel = per1->getRelationship(per2->getName());
    if(rel==0)
        return false;

    return rel->getState()==Community;
}


bool WorldInterpreter::policeRepGreaterThan(std::string person, int rep)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getPoliceRep()>rep;
}

bool WorldInterpreter::policeRepLessThan(std::string person, int rep)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getPoliceRep()<rep;
}

bool WorldInterpreter::mobRepGreaterThan(std::string person, int rep)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getMobRep()>rep;
}

bool WorldInterpreter::mobRepLessThan(std::string person, int rep)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobRep()<rep;
}

bool WorldInterpreter::policeWantedLessThan(std::string person, int wanted)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getPoliceWanted()<wanted;
}

bool WorldInterpreter::policeWantedGreaterThan(std::string person, int wanted)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getPoliceWanted()>wanted;
}

bool WorldInterpreter::mobWantedGreaterThan(std::string person, int wanted)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobWanted()>wanted;
}

bool WorldInterpreter::mobWantedLessThan(std::string person, int wanted)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobWanted()<wanted;
}

bool WorldInterpreter::isPolice(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getStoryRank()==2;
}

bool WorldInterpreter::isVigilante(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getStoryRank()==1;

}

bool WorldInterpreter::isMobster(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getStoryRank()==0;

}

bool WorldInterpreter::isGang(std::string person)
{

}
