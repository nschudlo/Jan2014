#include "person.h"
#include "worldobject.h"
#include <iostream>

using namespace std;

Person::Person(string name, int gender)
{
    this->name = name;
    this->mood = 5;
    this->gender = gender;

    cout<<"Created a person named: "<<this->name<<endl;
}

void Person::setName(std::string newName)
{
    this->name = newName;
}

string Person::getName()
{
    return this->name;
}

int Person::getGender()
{
    return this->gender;
}

void Person::addRelationship(Relationship *rel)
{
    relationships.push_back(rel);
}

void Person::listRelationships()
{
    for(unsigned int index=0; index<this->relationships.size(); index++)
    {
        try{
            relationships.at(index)->printRelationship();
        }catch(exception e){cout<<"No more relationships \n";}
    }
}

void Person::setMood(int mood)
{
    this->mood = mood;
}

int Person::getMood()
{
    return this->mood;
}

vector<WorldObject*> Person::getItemsHeld()
{
    return this->itemsHeld;
}

void Person::holdItem(WorldObject *object)
{
    this->itemsHeld.push_back(object);
}

Relationship* Person::getRelationship(string name)
{
    for (unsigned int index=0; index<relationships.size();index++)
    {
        try{
            if(relationships.at(index)->getOne()==name || relationships.at(index)->getTwo()==name)
                return relationships.at(index);
        }catch(exception e){cout<<"No more items \n";}
    }

    return 0;
}

int Person::isHolding(string objectName)
{
    int holding=0;

    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(itemsHeld.at(index)->getName()==objectName)
                holding++;
        }catch(exception e){cout<<"No more items \n";}
    }
    return holding;
}

void Person::dropAll(string object)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(itemsHeld.at(index)->getName()==object)
            {
                itemsHeld.erase(itemsHeld.begin()+index);
                holding++;
                index--;
            }
        }catch(exception e){cout<<"No more items \n";}
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::dropItem(string object)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        try{
            if(this->itemsHeld.at(index)->getName()==object)
            {
                itemsHeld.erase(itemsHeld.begin()+index);
                holding++;
                break;
            }
        }catch(exception e){cout<<"No more items \n";}
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::dropItem(string object, int count)
{
    int holding = 0;
    for(unsigned int index=0; index<this->itemsHeld.size(); index++)
    {
        if(holding < count)
        {
            try{
                if(this->itemsHeld.at(index)->getName()==object)
                {

                        itemsHeld.erase(itemsHeld.begin()+index);
                        holding++;

                }
            }catch(exception e){cout<<"No more items \n";}
        }
        else
            break;
    }
    cout<<holding << " " << object << "(s) removed.\n";
}

void Person::printAllItems()
{
    cout<<"Items Held:";

    for(unsigned int f=0; f < itemsHeld.size(); f++)
    {
       try{ cout<<" "<<itemsHeld.at(f)->getName();}
        catch(exception e){cout<<" none";}
    }
    cout<<endl;
}

void Person::printDetails()
{
    cout<<"-----------------------"<<endl;
    cout<<"Detailed Info For: "<<this->name<<endl;
    cout<<"\tGender: "<<gender<<endl;
    cout<<"\t";
    printAllItems();
    cout<<endl;
    cout<<"\t";
    listRelationships();
    cout<<endl;
    cout<<"-----------------------"<<endl;


}


