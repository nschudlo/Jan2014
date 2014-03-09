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
{\
    if(firstVal=="a")\
    {\
        aCount++;\
        for(int index=0;index<(int)a->size();index++)\
            if(interpreter->functionName(a->at(index)->getName(),secondVal)==evalBool)\
            {\
                countA.at(index)++;\
            }\
    }\
    else if(firstVal=="b")\
    {\
        bCount++;\
        for(int index=0;index<(int)b->size();index++)\
            if(interpreter->functionName(b->at(index)->getName(),secondVal)==evalBool)\
            {\
                countB.at(index)++;\
            }\
    }\
    else if(firstVal=="c")\
    {\
        cCount++;\
        for(int index=0;index<(int)c->size();index++)\
            if(interpreter->functionName(c->at(index)->getName(),secondVal)==evalBool)\
            {\
                countC.at(index)++;\
            }\
    }\
    else if(secondVal=="a")\
    {\
        aCount++;\
        for(int index=0;index<(int)a->size();index++)\
            if(interpreter->functionName(firstVal, a->at(index)->getName())==evalBool)\
            {\
                countA.at(index)++;\
            }\
    }\
    else if(secondVal=="b")\
    {\
        bCount++;\
        for(int index=0;index<(int)b->size();index++)\
            if(interpreter->functionName(firstVal, b->at(index)->getName())==evalBool)\
            {\
                countB.at(index)++;\
            }\
    }\
    else if(secondVal=="c")\
    {\
        cCount++;\
        for(int index=0;index<(int)c->size();index++)\
            if(interpreter->functionName(firstVal, c->at(index)->getName())==evalBool)\
            {\
                countC.at(index)++;\
            }\
    }\
    else\
    {\
        if(interpreter->functionName(firstVal,secondVal)==evalBool)\
            return true;\
    }\
    return false;\
}

#define macroSingle(functionName,firstVal)\
{\
    if(firstVal=="a")\
    {\
        aCount++;\
        for(int index=0;index<(int)a->size();index++)\
            if(interpreter->functionName(a->at(index)->getName())==evalBool)\
            {\
                countA.at(index)++;\
            }\
    }\
    else if(firstVal=="b")\
    {\
        bCount++;\
        for(int index=0;index<(int)b->size();index++)\
            if(interpreter->functionName(b->at(index)->getName())==evalBool)\
            {\
                countB.at(index)++;\
            }\
    }\
    else if(firstVal=="c")\
    {\
        cCount++;\
        for(int index=0;index<(int)c->size();index++)\
            if(interpreter->functionName(c->at(index)->getName())==evalBool)\
            {\
                countC.at(index)++;\
            }\
    }\
    else{\
        if(interpreter->functionName(firstVal)==evalBool)\
            return true;\
    }\
    return false;\
}

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

int Evaluator::evaluate(vector<string> _conditions,
                        vector<Person*> *_a,vector<Person*> *_b,
                        vector<Person*> *_c)//, vector<int> validConditions)
{
    conditions = _conditions;
    vector<Person*> temp = controller->getPeopleVector();
    a = _a;
    b = _b;
    c = _c;

    countA.clear();
    countB.clear();
    countC.clear();

    aCount = 0;
    bCount = 0;
    cCount = 0;

    //This variable is used to determine if the a b c vectors had values in them
    //when the function was called. If so, do not modify the vectors
    bool prefilledPeople = false;

    //If a, b, c are passed in with values predetermined dont fill them
    if(a->size()>0 || b->size()>0 || c->size()>0)
    {
        prefilledPeople = true;
        for(int index=0; index<(int)a->size(); index++)
            countA.push_back(0);
        for(int index=0; index<(int)b->size(); index++)
            countB.push_back(0);
        for(int index=0; index<(int)c->size(); index++)
            countC.push_back(0);
    }
    else
    {//If a b c are empty (new) fill them with all people
        for(int index=0; index<(int)temp.size(); index++)
        {
            countA.push_back(0);
            countB.push_back(0);
            countC.push_back(0);
            a->push_back(temp.at(index));
            b->push_back(temp.at(index));
            c->push_back(temp.at(index));
        }
    }

    //Cycle through each condition checking for validity
    int countCorrect =0;
    for(int index=0; index<(int)conditions.size();index++)
    {
        string pre = conditions.at(index);
        //evaluatePre(pre);
        if(evaluatePre(pre))//This will only return true if no a b c variables are used
            countCorrect++;
    }

    //Find the person with the most matching for each variable
    int maxA=0,maxB=0,maxC=0;
    for(int index=0;index<(int)a->size();index++)
        if(countA.at(index)>maxA)
        {
            maxA=countA.at(index);
        }

    for(int index=0;index<(int)b->size();index++)
        if(countB.at(index)>maxB)
        {
            maxB=countB.at(index);
        }

    for(int index=0;index<(int)c->size();index++)
        if(countC.at(index)>maxC)
        {
            maxC=countC.at(index);
        }


    //Once all conditions have been checked, eliminate the necessary people
    for(int index=a->size()-1; index>=0; index--)
        if(aCount!=countA.at(index) || aCount==0) //Meaning this person doesn't satisfy all of a's requirements
            vecRemove(a,index);                     //or there are no a requirements

    for(int index=b->size()-1; index>=0; index--)
        if(bCount!=countB.at(index) || bCount==0)
            vecRemove(b,index);

    for(int index=c->size()-1; index>=0; index--)
        if(cCount!=countC.at(index) || cCount==0)
            vecRemove(c,index);


    //If every condition is met this should = conditions.size()
    int totalCount = countCorrect + maxA + maxB + maxC;
    //Otherwise is should be the number of conditions met

    return totalCount;
}

int Evaluator::evaluateStory(vector<string> _conditions,
                        vector<Person*> *_a,vector<Person*> *_b,
                        vector<Person*> *_c)//, vector<int> validConditions)
{
    conditions = _conditions;
    vector<Person*> temp = controller->getPeopleVector();
    a = _a;
    b = _b;
    c = _c;

    countA.clear();
    countB.clear();
    countC.clear();

    aCount = 0;
    bCount = 0;
    cCount = 0;

    //This variable is used to determine if the a b c vectors had values in them
    //when the function was called. If so, do not modify the vectors
    bool prefilledPeople = false;

    //If a, b, c are passed in with values predetermined dont fill them
    if(a->size()>0 || b->size()>0 || c->size()>0)
    {
        prefilledPeople = true;
        for(int index=0; index<(int)a->size(); index++)
            countA.push_back(0);
        for(int index=0; index<(int)b->size(); index++)
            countB.push_back(0);
        for(int index=0; index<(int)c->size(); index++)
            countC.push_back(0);
    }
    else
    {//If a b c are empty (new) fill them with all people
        for(int index=0; index<(int)temp.size(); index++)
        {
            countA.push_back(0);
            countB.push_back(0);
            countC.push_back(0);
            a->push_back(temp.at(index));
            b->push_back(temp.at(index));
            c->push_back(temp.at(index));
        }
    }

    //Cycle through each condition checking for validity
    int countCorrect =0;
    for(int index=0; index<(int)conditions.size();index++)
    {
        string pre = conditions.at(index);
        //evaluatePre(pre);
        if(evaluatePre(pre))//This will only return true if no a b c variables are used
            countCorrect++;
    }

    Person *maxPerA,*maxPerB,*maxPerC;
    //Find the person with the most matching for each variable
    int maxA=0,maxB=0,maxC=0;
    for(int index=0;index<(int)a->size();index++)
        if(countA.at(index)>maxA)
        {
            maxPerA=a->at(index);
            maxA=countA.at(index);
        }

    for(int index=0;index<(int)b->size();index++)
        if(countB.at(index)>maxB)
        {
            maxPerB=b->at(index);
            maxB=countB.at(index);
        }

    for(int index=0;index<(int)c->size();index++)
        if(countC.at(index)>maxC)
        {
            maxPerC=c->at(index);
            maxC=countC.at(index);
        }


    //Once all conditions have been checked, eliminate the necessary people
    for(int index=a->size()-1; index>=0; index--)
        if(aCount!=countA.at(index) || aCount==0) //Meaning this person doesn't satisfy all of a's requirements
            vecRemove(a,index);                     //or there are no a requirements

    for(int index=b->size()-1; index>=0; index--)
        if(bCount!=countB.at(index) || bCount==0)
            vecRemove(b,index);

    for(int index=c->size()-1; index>=0; index--)
        if(cCount!=countC.at(index) || cCount==0)
            vecRemove(c,index);


    //If every condition is met this should = conditions.size()
    int totalCount = countCorrect + maxA + maxB + maxC;
    //Otherwise is should be the number of conditions met

    return totalCount;
}

bool Evaluator::evaluatePre(string pre)
{

    boost::tokenizer<> tok(pre);
    boost::tokenizer<>::iterator i=tok.begin();

    //Pull out the boolean value
    string evalBoolString = *i++;
    bool evalBool = false;
    if(evalBoolString=="true")
        evalBool = true;
    else if(evalBoolString=="false")
        evalBool = false;
    else
    {
        cout<<"ERROR: condition did not start with true or false!"<<endl;
        return false;
    }


    //Pull out the type of check
    string type = *i++;
    //cout<<pre<<endl;


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

        macroMulti(personHealthGreaterThan,personName,health);
    }
    else if(type =="personHealthLessThan"){
        string personName = *i++;
        string health = *i++;

        macroMulti(personHealthLessThan,personName,health);
    }
    else if(type =="personMoneyGreaterThan"){
        string personName = *i++;
        string money = *i++;

        macroMulti(personMoneyGreaterThan,personName,money);
    }
    else if(type =="personMoneyLessThan"){
        string personName = *i++;
        string money = *i++;

        macroMulti(personMoneyLessThan,personName,money);
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

        macroMulti(policeRepGreaterThan,personName,rep)
    }
    else if(type =="policeRepLessThan"){
        string personName = *i++;
        string rep = *i++;

        macroMulti(policeRepLessThan,personName,rep)
    }
    else if(type =="mobRepGreaterThan"){
        string personName = *i++;
        string rep = *i++;

        macroMulti(mobRepGreaterThan,personName,rep)
    }
    else if(type =="mobRepLessThan"){
        string personName = *i++;
        string rep = *i++;

        macroMulti(mobRepLessThan,personName,rep)
    }
    else if(type =="policeWantedLessThan"){
        string personName = *i++;
        string wanted = *i++;

        macroMulti(policeWantedLessThan,personName,wanted)
    }
    else if(type =="policeWantedGreaterThan"){
        string personName = *i++;
        string wanted = *i++;

        macroMulti(policeWantedGreaterThan,personName,wanted)
    }
    else if(type =="mobWantedGreaterThan"){
        string personName = *i++;
        string wanted = *i++;

        macroMulti(mobWantedGreaterThan,personName,wanted)
    }
    else if(type =="mobWantedLessThan"){
        string personName = *i++;
        string wanted = *i++;

        macroMulti(mobWantedLessThan,personName,wanted)
    }
    else if(type =="isMainCharacter"){
        string personName = *i++;

        macroSingle(isMainCharacter,personName);
    }
    else if(type =="isPolice"){
        string personName = *i++;

        //macroSingle(isPolice,personName);


        if(personName=="a")
        {
            aCount++;
            for(int index=0;index<(int)a->size();index++)
                if(interpreter->isPolice(a->at(index)->getName())==evalBool)
                {
                    countA.at(index)++;
                }
        }
        else if(personName=="b")
        {
            bCount++;
            for(int index=0;index<(int)b->size();index++)
                if(interpreter->isPolice(b->at(index)->getName())==evalBool)
                {
                    countB.at(index)++;
                }
        }
        else if(personName=="c")
        {
            cCount++;
            for(int index=0;index<(int)c->size();index++)
                if(interpreter->isPolice(c->at(index)->getName())==evalBool)
                {
                    countC.at(index)++;
                }
        }
        else{
            if(interpreter->isPolice(personName)==evalBool)
                return true;
        }
        return false;

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
