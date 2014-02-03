#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <person.h>

class Person;

class Relationship
{
public:
    Relationship(Person *_one, Person *_two, int type, int status);

    void setPersonOne(Person *_new);
    void printRelationship();

    void setState(int state, int strength);
    int getState();
    int getStrength();

    std::string getOne();
    std::string getTwo();


private:
    Person *one;
    Person *two;

    //Parent-Child, Sibling, Family, Lovers, Strangers
    //Friends, Grandparent, Enemies, Teacher-Student
    //Working, Community
    int relationshipState;
    int relationshipStrength; //0=bad, 1=average, 2=good

};

#endif // RELATIONSHIP_H
