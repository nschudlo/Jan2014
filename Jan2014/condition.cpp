#include "condition.h"

#include <iostream>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

using namespace std;
Condition::Condition(string conditionLine)
{
    boost::tokenizer<> tok(conditionLine);
    boost::tokenizer<>::iterator i=tok.begin();

    //Pull out the boolean value
    string evalBoolString = *i++;
    evalBool = false;
    if(evalBoolString=="true")
        evalBool = true;
    else if(evalBoolString=="false")
        evalBool = false;
    else
        cout<<"ERROR: condition did not start with true or false!"<<endl;


    //Pull out the type of check
    type = *i++;

    val1 = *i++;
    originalVal1 = val1;

    if(i != tok.end())
        val2 = *i;
    originalVal2 = val2;

    interpreter = WorldInterpreter::Instance();
    controller = Controller::Instance();

}

void Condition::addPerson(string name){
    people.push_back(name);}

bool Condition::hasPerson(string name){
    for(int index=0; index<(int)people.size();index++)
        if(people.at(index)==name)
            return true;
    return false;
}

void Condition::setVariablePerson(string name){
    if(originalVal1=="a"||originalVal1=="b"||originalVal1=="c")
        val1 = name;
    else if(originalVal2=="a"||originalVal2=="b"||originalVal2=="c")
        val2 = name;
    else
        cout<<"ERROR: "<<printOut()<<" does not have a variable person"<<endl;
}

void Condition::resetCondition()
{
    val1 = originalVal1;
    val2 = originalVal2;
    people.clear();
}


bool Condition::isA(){
    return originalVal1=="a"||originalVal2=="a";}

bool Condition::isB(){
    return originalVal1=="b"||originalVal2=="b";}

bool Condition::isC(){
    return originalVal1=="c"||originalVal2=="c";}

string Condition::getType(){
    return type;}

string Condition::getVal1(){
    return val1;}

string Condition::getVal2(){
    return val2;}

bool Condition::getEvaluationBool(){
    return evalBool;}

string Condition::printOut()
{
    ostringstream printOut;

    if(evalBool)
        printOut<<"true";
    else
        printOut<<"false";

    printOut<<" "<<type<<" "<<val1<<" "<<val2;
    return printOut.str();
}
