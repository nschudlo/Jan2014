#ifndef WORLDINTERPRETER_H
#define WORLDINTERPRETER_H

#include <string>
#include <vector>
#include "controller.h"

class WorldInterpreter
{
public:
    static WorldInterpreter* Instance();

    bool personIsAt(std::string person, std::string location);
    bool personIsAtSameLocationAs(std::string person1, std::string person2);
    bool personIsHolding(std::string person, std::string object);
    bool personCanDoAction(std::string person, std::string action);//untested
    bool personCanGetAction(std::string person,std::string action);//untested
    bool personHealthGreaterThan(std::string person, int healthValue);
    bool personHealthLessThan(std::string person, int healthValue);
    bool personMoneyGreaterThan(std::string person, int moneyValue);
    bool personMoneyLessThan(std::string person, int moneyValue);
    bool personIsMale(std::string person);
    bool personIsFemale(std::string person);

    bool itemCanDoAction(std::string item, std::string action);
    bool itemCanGetAction(std::string item, std::string action);

    bool relationshipPositive(std::string person1, std::string person2);
    bool relationshipNegative(std::string person1, std::string person2);
    bool relationshipAverage(std::string person1, std::string person2);
    bool relationshipParent(std::string person1, std::string person2);
    bool relationshipChild(std::string person1, std::string person2);
    bool relationshipSibling(std::string person1, std::string person2);
    bool relationshipMarried(std::string person1, std::string person2);
    bool relationshipFamily(std::string person1, std::string person2);
    bool relationshipSO(std::string person1, std::string person2);
    bool relationshipStrangers(std::string person1, std::string person2);
    bool relationshipFriends(std::string person1, std::string person2);
    bool relationshipEnemies(std::string person1, std::string person2);
    bool relationshipTeacher(std::string person1, std::string person2);
    bool relationshipStudent(std::string person1, std::string person2);
    bool relationshipWorking(std::string person1, std::string person2);
    bool relationshipCommunity(std::string person1, std::string person2);

    bool policeRepGreaterThan(std::string person, int rep);
    bool policeRepLessThan(std::string person, int rep);
    bool mobRepGreaterThan(std::string person, int rep);
    bool mobRepLessThan(std::string person, int rep);
    bool policeWantedLessThan(std::string person, int wanted);
    bool policeWantedGreaterThan(std::string person, int wanted);
    bool mobWantedGreaterThan(std::string person, int wanted);
    bool mobWantedLessThan(std::string person, int wanted);

    bool isPolice(std::string person);
    bool isVigilante(std::string person);
    bool isMobster(std::string person);

    bool isGangMember(std::string person);
    bool isShopper(std::string person);
    bool isShopOwner(std::string person);
    bool isBartender(std::string person);
    bool isBanker(std::string person);
    bool isDockWorker(std::string person);


private:
    WorldInterpreter();
   // WorldInterpreter(WorldInterpreter const&){};             // copy constructor is private
    //WorldInterpreter& operator=(WorldInterpreter const&){};  // assignment operator is private
    static WorldInterpreter* m_pInstance;

    std::vector<Location*> locations;
    std::vector<WorldObject*> worldObjects;
    std::vector<Relationship*> relationships;
    std::vector<Person*> people;
    std::vector<Action*> actions;

    Controller *controller;
};

#endif // WORLDINTERPRETER_H
