#include "relationship.h"
#include <person.h>
#include <iostream>

using namespace std;

enum relationship{Parent=0, Child=1, Sibling=2, Married=3, Family=4, SO=5, Strangers=6,
                  Friends=7, Enemies=8, Teacher=9, Student=10, Working=11, Community=12};

/**
 * @brief Relationship::Relationship
 * @param _one The perspective of this relationship (who is thinking this)
 * @param _two The target of the perspective (who they are thinking about)
 * @param type
 * @param status
 */
Relationship::Relationship(Person *_one, Person *_two, int type, int status)
{
    one = _one;
    two = _two;

    one->addRelationship(this);
    //two->addRelationship(this);

    relationshipState = type;//friends
    relationshipStrength = status;//average
    cout<<"Relationship created: "<<one->getName()<<", "<<two->getName()<<endl;
}

void Relationship::setState(int state, int strength)
{
    relationshipState = state;
    relationshipStrength = strength;
}

std::string Relationship::getOne()
{
    return one->getName();
}

std::string Relationship::getTwo()
{
    return two->getName();
}

int Relationship::getState()
{
    return relationshipState;
}

int Relationship::getStrength()
{
    return relationshipStrength;
}

void Relationship::setPersonOne(Person *_new)
{
    one = _new;
}

void Relationship::printRelationship()
{
    cout<<relationshipToString()<<endl;
}

string Relationship::relationshipToString()
{

    string relOutput = "";
    relOutput.append(two->getName() +" is a");
    //cout << two->getName() <<" is a";

    string currStrength = " ";
    switch(relationshipStrength)
    {
    case 0:currStrength=" bad";break;
    case 1:currStrength="n average";break;
    case 2:currStrength=" good";break;
    }

    relOutput.append(currStrength);

    switch(relationshipState)
    {
    case 0:
        if(two->getGender()==0)
            relOutput.append(" father to ");
        //cout<<currStrength<<" father to ";
        else
            relOutput.append(" mother to ");
        //cout<<currStrength<<" mother to ";
        break;

    case 1:
        if(two->getGender()==0)
            relOutput.append(" son to ");
        //cout<<currStrength<<" son to ";
        else
            relOutput.append(" daughter to ");
        //cout<<currStrength<<" daughter to ";
        break;

    case 2:
        if(two->getGender()==0)
            relOutput.append(" brother to ");
        //cout<<currStrength<<" brother to ";
        else
            relOutput.append(" sister to ");
        //cout<<currStrength<<" sister to ";
        break;

    case 3:
        if(two->getGender()==0)
            relOutput.append(" husband to ");
        //cout<<currStrength<<" husband to ";
        else
            relOutput.append(" wife to ");
        //cout<<currStrength<<" wife to ";
        break;

    case 4:
        relOutput.append(" family member to ");
        //cout<<currStrength<<" family members to ";
        break;

    case 5:
        if(two->getGender()==0)
            relOutput.append(" boyfriend to ");
        //cout<<currStrength<<" boyfriend to ";
        else
            relOutput.append(" girlfriend to ");
        //cout<<currStrength<<" girlfriend to ";
        break;

    case 6:
        relOutput.append(" stranger to ");
        //cout<<currStrength<<" strangers to ";
        break;

    case 7:
        relOutput.append(" friend with ");
        //cout<<currStrength<<" friend with ";
        break;

    case 8:
        relOutput.append(" enemy with ");
        //cout<<currStrength<<" enemy with ";
        break;

    case 9:
        relOutput.append(" teacher to ");
        //cout<<currStrength<<" teacher to ";
        break;

    case 10:
        relOutput.append(" student to ");
        //cout<<currStrength<<" student to ";
        break;

    case 11:
        relOutput.append(" coworker to ");
        //cout<<currStrength<<" coworker to ";
        break;

    case 12:
        relOutput.append(" community member to ");
        //cout<<currStrength<<" community member to ";
        break;
    }

    relOutput.append(one->getName());
    //cout<<one->getName()<<endl;

    return relOutput;
    /* switch(relationshipState)
    {
    case 0:cout<<currStrength<<" parent and child to each other"<<endl;break;
    case 1:cout<<currStrength<<" siblings to each other"<<endl;break;
    case 2:cout<<currStrength<<" family members to each other"<<endl;break;
    case 3:cout<<"in a "<<currStrength<<" relationship"<<endl;break;
    case 4:cout<<"on "<<currStrength<<" terms as strangers"<<endl;break;
    case 5:cout<<currStrength<<" friends"<<endl;break;
    case 6:cout<<currStrength<<" enemies"<<endl;break;
    case 7:cout<<"a "<<currStrength<<" teacher and student combination"<<endl;break;
    case 8:cout<<currStrength<<" co-workers to each other"<<endl;break;
    case 9:cout<<currStrength<<" community members to each other"<<endl;break;
    }
    */
}
