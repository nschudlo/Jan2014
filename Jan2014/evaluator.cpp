#include "evaluator.h"
#include "worldinterpreter.h"
#include "controller.h"

#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

using namespace std;

#define vecRemove(vec,index) vec->erase(vec->begin()+index)


#define macroMulti(functionName,firstVal,secondVal)\
{if(firstVal=="a")\
{   for(int index=0;index<(int)a->size();index++)\
    if(!interpreter->functionName(a->at(index)->getName(),secondVal))\
    vecRemove(a,index--);\
    if(a->size()==0)\
    return false;}\
    else if(firstVal=="b"){\
    for(int index=0;index<(int)b->size();index++)\
    if(!interpreter->functionName(b->at(index)->getName(),secondVal))\
    vecRemove(b,index--);\
    if(b->size()==0)\
    return false;}\
    else if(firstVal=="c"){\
    for(int index=0;index<(int)c->size();index++)\
    if(!interpreter->functionName(c->at(index)->getName(),secondVal))\
    vecRemove(c,index--);\
    if(c->size()==0)\
    return false;}\
    else{\
    if(!interpreter->functionName(firstVal,secondVal))\
    return false;}}

#define macroSingle(functionName,firstVal)\
{if(firstVal=="a")\
{   for(int index=0;index<(int)a->size();index++)\
    if(!interpreter->functionName(a->at(index)->getName()))\
    vecRemove(a,index--);\
    if(a->size()==0)\
    return false;}\
    else if(firstVal=="b"){\
    for(int index=0;index<(int)b->size();index++)\
    if(!interpreter->functionName(b->at(index)->getName()))\
    vecRemove(b,index--);\
    if(b->size()==0)\
    return false;}\
    else if(firstVal=="c"){\
    for(int index=0;index<(int)c->size();index++)\
    if(!interpreter->functionName(c->at(index)->getName()))\
    vecRemove(c,index--);\
    if(c->size()==0)\
    return false;}\
    else{\
    if(!interpreter->functionName(firstVal))\
    return false;}}
Evaluator* Evaluator::m_pInstance = NULL;

Evaluator* Evaluator::Instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new Evaluator;
    return m_pInstance;
}

Evaluator::Evaluator(){
    controller=Controller::Instance();
    interpreter=WorldInterpreter::Instance();
}

/*
 *  This function takes the conditions and person vectors. It creates copies of the
 *  entire people vectors. Each parameter is checked, modifying the people vectors
 *  as necessary. The number of true parameters is returned, and the people vectors
 *  are modified.
 *
 */
int Evaluator::evaluate(vector<string> _conditions, vector<Person*> *_a)
{
    conditions = _conditions;
    vector<Person*> temp = controller->getPeopleVector();
    a = _a;

    for(int index=0; index<(int)temp.size(); index++)
    {
        a->push_back(temp.at(index));
    }
    return cycleConditions();

}

int Evaluator::evaluate(vector<string> _conditions, vector<Person*> *_a,vector<Person*> *_b)
{
    conditions = _conditions;
    vector<Person*> temp = controller->getPeopleVector();
    a = _a;
    b = _b;

    for(int index=0; index<(int)temp.size(); index++)
    {
        a->push_back(temp.at(index));
        b->push_back(temp.at(index));
    }
    return cycleConditions();
}

int Evaluator::evaluate(vector<string> _conditions, vector<Person*> *_a,vector<Person*> *_b,vector<Person*> *_c)
{
    conditions = _conditions;
    vector<Person*> temp = controller->getPeopleVector();
    a = _a;
    b = _b;
    c = _c;

    for(int index=0; index<(int)temp.size(); index++)
    {
        a->push_back(temp.at(index));
        b->push_back(temp.at(index));
        c->push_back(temp.at(index));
    }
    return cycleConditions();
}

int Evaluator::cycleConditions()
{
    int countTrue =0;
    for(int index=0; index<(int)conditions.size();index++)
    {
        string pre = conditions.at(index);
        if(evaluatePre(pre))
            countTrue++;
    }
    return countTrue;
}

bool Evaluator::evaluatePre(string pre)
{

    boost::tokenizer<> tok(pre);
    boost::tokenizer<>::iterator i=tok.begin();

    //Pull out the type of check
    string type = *i++;
    cout<<pre<<endl;


    if(type =="personIsAt"){
        string personName = *i++;
        string location;
        while(i!=tok.end())
        {
            location.append(*i++);
            location.append(" ");
        }
        trim(location);

        macroMulti(personIsAt,personName,location)

    }
    else if(type =="personIsAtSameLocationAs"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(personIsAtSameLocationAs,personName,p2);

    }
    else if(type =="personIsHolding"){
        string personName = *i++;
        string object = *i++;

        macroMulti(personIsHolding,personName,object)
    }
    else if(type =="personCanDoAction"){
        string personName = *i++;
        string action = *i++;

        macroMulti(personCanDoAction,personName,action)
    }
    else if(type =="personCanGetAction"){
        string personName = *i++;
        string action = *i++;

        macroMulti(personCanGetAction,personName,action)
    }
    else if(type =="personHealthGreaterThan"){
        string personName = *i++;
        string health = *i++;
        int h = atoi(health.c_str());

        macroMulti(personHealthGreaterThan,personName,h);
    }
    else if(type =="personHealthLessThan"){
        string personName = *i++;
        string health = *i++;
        int h = atoi(health.c_str());

        macroMulti(personHealthLessThan,personName,h);
    }
    else if(type =="personMoneyGreaterThan"){
        string personName = *i++;
        string money = *i++;
        int h = atoi(money.c_str());

        macroMulti(personMoneyGreaterThan,personName,h);
    }
    else if(type =="personMoneyLessThan"){
        string personName = *i++;
        string money = *i++;
        int h = atoi(money.c_str());

        macroMulti(personMoneyLessThan,personName,h);
    }
    else if(type =="personIsMale"){
        string personName = *i++;

        macroSingle(personIsMale,personName);
    }
    else if(type =="personIsFemale"){
        string personName = *i++;

        macroSingle(personIsFemale,personName);
    }

    else if(type =="itemCanDoAction"){
        string item = *i++;
        string action = *i++;

        macroMulti(itemCanDoAction,item,action);
    }
    else if(type =="itemCanGetAction"){
        string item = *i++;
        string action = *i++;

        macroMulti(itemCanGetAction,item,action);
    }

    else if(type =="relationshipPositive"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipPositive,personName,p2);
    }
    else if(type =="relationshipNegative"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipNegative,personName,p2);
    }
    else if(type =="relationshipAverage"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipAverage,personName,p2);
    }
    else if(type =="relationshipParent"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipParent,personName,p2);
    }
    else if(type =="relationshipChild"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipChild,personName,p2);
    }
    else if(type =="relationshipSibling"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipSibling,personName,p2);
    }
    else if(type =="relationshipMarried"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipMarried,personName,p2);
    }
    else if(type =="relationshipFamily"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipFamily,personName,p2);
    }
    else if(type =="relationshipSO"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipSO,personName,p2);
    }
    else if(type =="relationshipStrangers"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipStrangers,personName,p2);
    }
    else if(type =="relationshipFriends"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipFriends,personName,p2);
    }
    else if(type =="relationshipEnemies"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipEnemies,personName,p2);
    }
    else if(type =="relationshipTeacher"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipTeacher,personName,p2);
    }
    else if(type =="relationshipStudent"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipStudent,personName,p2);
    }
    else if(type =="relationshipWorking"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipWorking,personName,p2);
    }
    else if(type =="relationshipCommunity"){
        string personName = *i++;
        string p2 = *i++;
        macroMulti(relationshipCommunity,personName,p2);
    }

    else if(type =="policeRepGreaterThan"){
        string personName = *i++;
        string rep = *i++;
        int r= atoi(rep.c_str());

        macroMulti(policeRepGreaterThan,personName,r)
    }
    else if(type =="policeRepLessThan"){
        string personName = *i++;
        string rep = *i++;
        int r= atoi(rep.c_str());

        macroMulti(policeRepLessThan,personName,r)
    }
    else if(type =="mobRepGreaterThan"){
        string personName = *i++;
        string rep = *i++;
        int r= atoi(rep.c_str());

        macroMulti(mobRepGreaterThan,personName,r)
    }
    else if(type =="mobRepLessThan"){
        string personName = *i++;
        string rep = *i++;
        int r= atoi(rep.c_str());

        macroMulti(mobRepLessThan,personName,r)
    }
    else if(type =="policeWantedLessThan"){
        string personName = *i++;
        string wanted = *i++;
        int w= atoi(wanted.c_str());

        macroMulti(policeWantedLessThan,personName,w)
    }
    else if(type =="policeWantedGreaterThan"){
        string personName = *i++;
        string wanted = *i++;
        int w= atoi(wanted.c_str());

        macroMulti(policeWantedGreaterThan,personName,w)
    }
    else if(type =="mobWantedGreaterThan"){
        string personName = *i++;
        string wanted = *i++;
        int w= atoi(wanted.c_str());

        macroMulti(mobWantedGreaterThan,personName,w)
    }
    else if(type =="mobWantedLessThan"){
        string personName = *i++;
        string wanted = *i++;
        int w= atoi(wanted.c_str());

        macroMulti(mobWantedLessThan,personName,w)
    }
    else if(type =="isMainCharacter"){
        string personName = *i++;

        macroSingle(isMainCharacter,personName);
    }
    else if(type =="isPolice"){
        string personName = *i++;

        macroSingle(isPolice,personName);
    }
    else if(type =="isVigilante"){
        string personName = *i++;

        macroSingle(isVigilante,personName);
    }
    else if(type =="isMobster"){
        string personName = *i++;

        macroSingle(isMobster,personName);
    }

    else if(type =="isGangMember"){
        string personName = *i++;

        macroSingle(isGangMember,personName);
    }
    else if(type =="isShopper"){
        string personName = *i++;

        macroSingle(isShopper,personName);
    }
    else if(type =="isShopOwner"){
        string personName = *i++;

        macroSingle(isShopOwner,personName);
    }
    else if(type =="isBartender"){
        string personName = *i++;

        macroSingle(isBartender,personName);
    }
    else if(type =="isBanker"){
        string personName = *i++;

        macroSingle(isBanker,personName);
    }
    else if(type =="isDockWorker"){
        string personName = *i++;

        macroSingle(isDockWorker,personName);
    }
    else
    {
        cout<<"ERROR: Function +"<<type<<"+ not found!"<<endl;
        return false;
    }
    // }
    //preEvaluation=true;
    return true;
}
