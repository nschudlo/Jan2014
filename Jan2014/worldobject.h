#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H
#include<string>
#include<vector>
#include<action.h>

class WorldObject
{
public:
    WorldObject(std::string name);

    std::string getName();

    void addActionDo(Action *act);
    void addActionGet(Action *act);
    void listActions();

    std::vector<Action*> getActionsDo();
    std::vector<Action*> getActionsGet();

    bool canActionDo(std::string name);
    bool canActionGet(std::string name);

    void setMaxItemsPossible(int max);
    int getMaxItemsPossible();

private:
    std::string name;
    std::vector<Action*> actionsDo;
    std::vector<Action*> actionsGet;

    int maxItemsPossible;

};

#endif // WORLDOBJECT_H
