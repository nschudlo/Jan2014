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
    cout << two->getName() <<" is a";
    string currStrength = " ";
    switch(relationshipStrength)
    {
    case 0:currStrength=" bad";break;
    case 1:currStrength="n average";break;
    case 2:currStrength=" good";break;
    }



    switch(relationshipState)
    {
    case 0:
        if(two->getGender()==0)
            cout<<currStrength<<" father to ";
        else
            cout<<currStrength<<" mother to ";
        break;

    case 1:
        if(two->getGender()==0)
            cout<<currStrength<<" son to ";
        else
            cout<<currStrength<<" daughter to ";
        break;

    case 2:
        if(two->getGender()==0)
            cout<<currStrength<<" brother to ";
        else
            cout<<currStrength<<" sister to ";
        break;

    case 3:
        if(two->getGender()==0)
            cout<<currStrength<<" husband to ";
        else
            cout<<currStrength<<" wife to ";
        break;

    case 4:
        cout<<currStrength<<" family members to ";break;

    case 5:
        if(two->getGender()==0)
            cout<<currStrength<<" boyfriend to ";
        else
            cout<<currStrength<<" girlfriend to ";
        break;

    case 6:cout<<currStrength<<" strangers to ";break;

    case 7:cout<<currStrength<<" friend with ";break;

    case 8:cout<<currStrength<<" enemy with ";break;

    case 9:cout<<currStrength<<" teacher to ";break;

    case 10:cout<<currStrength<<" student to ";break;

    case 11:cout<<currStrength<<" coworker to ";break;

    case 12:cout<<currStrength<<" community member to ";break;
    }

    cout<<one->getName()<<endl;

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
