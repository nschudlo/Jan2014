#include "worldinterpreter.h"
#include "controller.h"
#include <cstdlib>

using namespace std;

enum relationship{Parent=0, Child=1, Sibling=2, Married=3, Family=4, SO=5, Strangers=6,
                  Friends=7, Enemies=8, Teacher=9, Student=10, Working=11, Community=12};

WorldInterpreter* WorldInterpreter::m_pInstance = NULL;

WorldInterpreter* WorldInterpreter::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new WorldInterpreter;
    return m_pInstance;
}

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

bool WorldInterpreter::personHealthGreaterThan(string person, string healthValue)
{
    int hv = atoi(healthValue.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getHealth() > hv;
}

bool WorldInterpreter::personHealthLessThan(string person, string healthValue)
{
    int hv = atoi(healthValue.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getHealth() < hv;
}

bool WorldInterpreter::personMoneyGreaterThan(string person, string moneyValue)
{
    int hv = atoi(moneyValue.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMoney() > hv;
}

bool WorldInterpreter::personMoneyLessThan(string person, string moneyValue)
{
    int hv = atoi(moneyValue.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMoney() < hv;
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


bool WorldInterpreter::policeRepGreaterThan(std::string person, string rep)
{
    int r = atoi(rep.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getPoliceRep()>r;
}

bool WorldInterpreter::policeRepLessThan(std::string person, string rep)
{
    int r = atoi(rep.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getPoliceRep()<r;
}

bool WorldInterpreter::mobRepGreaterThan(std::string person, string rep)
{
    int r = atoi(rep.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getMobRep()>r;
}

bool WorldInterpreter::mobRepLessThan(std::string person, string rep)
{
    int r = atoi(rep.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobRep()<r;
}

bool WorldInterpreter::policeWantedLessThan(std::string person, string wanted)
{
    int w = atoi(wanted.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getPoliceWanted()<w;
}

bool WorldInterpreter::policeWantedGreaterThan(std::string person, string wanted)
{
    int w = atoi(wanted.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getPoliceWanted()>w;
}

bool WorldInterpreter::mobWantedGreaterThan(std::string person, string wanted)
{
    int w = atoi(wanted.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobWanted()>w;
}

bool WorldInterpreter::mobWantedLessThan(std::string person, string wanted)
{
    int w = atoi(wanted.c_str());
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;
    return per->getMobWanted()<w;
}

enum storyRoles{Shopper=1, ShopOwner=2, Bartender=3, Police=4, Mobster=5,
                Banker=6, GangMember=7, DockWorker=8};

bool WorldInterpreter::isMainCharacter(string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->isMainChar();
}

bool WorldInterpreter::isPolice(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return per->getStoryRank()==3;

    return per->getStoryRole()==Police;
}

bool WorldInterpreter::isVigilante(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    return per->getStoryRank()==2;

}

bool WorldInterpreter::isMobster(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return per->getStoryRank()==1;

    return per->getStoryRole()==Mobster;

}

bool WorldInterpreter::isGangMember(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;

    return per->getStoryRole()==GangMember;
}

bool WorldInterpreter::isShopper(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;
    return per->getStoryRole()==Shopper;
}

bool WorldInterpreter::isShopOwner(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;
    return per->getStoryRole()==ShopOwner;
}

bool WorldInterpreter::isBartender(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;
    return per->getStoryRole()==Bartender;
}

bool WorldInterpreter::isBanker(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;
    return per->getStoryRole()==Banker;
}

bool WorldInterpreter::isDockWorker(std::string person)
{
    Person* per = controller->getPerson(person);
    if(per==0)
        return false;

    if(per->isMainChar())
        return false;
    return per->getStoryRole()==DockWorker;
}

bool WorldInterpreter::isEmpty(string location)
{
    Location * loc = controller->getLocation(location);
    if(loc==0)
        return false;

    return loc->getCurrentPeople().size()==0;
}
