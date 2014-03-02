#include "bulkloader.h"
#include <person.h>
#include <relationship.h>
#include <worldobject.h>
#include "locationloader.h"
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

#include <iostream>
#include <fstream>
#include <string>
//CYCLE_MAX is used to count the number of different items in the bulk load file
//<Item><Action><Person><Relationship>
#define CYCLE_MAX 3
#define NUM_PERSON_PARAM 2
#define NUM_ITEM_PARAM 1
#define NUM_RELATIONSHIP_PARAM 3
#define NUM_ACTION_PARAM 1
#define NUM_ACTION_PARAM_PLUS 2

#define S_TO_I(string) boost::lexical_cast<int>(string)


using namespace std;

BulkLoader::BulkLoader(vector<WorldObject*> *_o,
                       vector<Relationship*> *_r,
                       vector<Person*> *_p,
                       vector<Action*> *_a,
                       vector<Location*> *_l, string filename)
{

    worldObjects = _o;
    relationships = _r;
    people = _p;
    actions = _a;
    locations = _l;

    LocationLoader(locations, "locations.txt");

    Person test = Person("Test  ", 1);

    loadfile(filename);

}

void BulkLoader::loadfile(string filename)
{
    string line;
    ifstream file(filename.c_str());

    string currentPerson;
    string currentItem;

    //Open the file
    if(file.is_open())
    {

        //Cycle through the file, looking for different
        //types everytime
        for(int cycle=0; cycle<=CYCLE_MAX; cycle++)
        {
            currentPerson = "";
            while(getline(file, line))
            {
                testString(line,cycle, currentPerson, currentItem);
            }
            file.clear();
            file.seekg(0,ios::beg);
        }
        file.close();
    }
    else cout<<"Unable to open file "<<filename<<endl;
}

void BulkLoader::testString(string line, int cycle, string &currentPerson, string &currentItem)
{
    //Skip comment lines and blank lines
    if(line[0] == '#' || line.empty())
        return;
    else
    {
        //tokenize the line
        boost::tokenizer<> tok(line);
        boost::tokenizer<>::iterator tokenIterator=tok.begin();

        //Pull out the <type> from the line
        string type = *tokenIterator++;

        //Assign the remaining tokens to the info string vector
        vector<string> info;
        info.assign(tokenIterator, tok.end());

        //Count the number of parameters
        int numParams = std::distance(tok.begin(),tok.end())-1;

        //This changes all uppercase in any names to lower
        to_lower(info[0]);

        //For every cycle after the first, store which person was last seen
        //This is for use in the bulk load file. The bulk load can
        //give a person items, action, or relationships by listing these after
        //declaring the person
        if(cycle !=0 && type.compare("Person")==0)
        {
            currentPerson = info[0];
        }

        if(type.compare("Item")==0)
        {
            currentItem = info[0];
        }

        switch (cycle)
        {
        case 0: //Person
            if(type.compare("Person")==0)
            {
                //check if the right number of params is in the file
                if(numParams != NUM_PERSON_PARAM)
                {
                    cout<<"ERROR: wrong number of (Person) params"<<endl;
                    break;
                }

                createPerson(info[0], S_TO_I(info[1]));//boost::lexical_cast<int>(info[1]));
            }


            break;
        case 1: //Item
            if(type.compare("Item")==0)
            {
                //check if the right number of params is in the file
                if(numParams != NUM_ITEM_PARAM)
                {
                    cout<<"ERROR: wrong number of (Item) params"<<endl;
                    break;
                }

                WorldObject* object = createObject(info[0]);
                Person* currPerson = getPerson(currentPerson);
                if(currPerson != 0)
                    currPerson->holdItem(object);

            }

            break;
        case 2: //Relationship
            if(type.compare("Relationship")==0)
            {
                //check if the right number of params is in the file
                if(numParams != NUM_RELATIONSHIP_PARAM)
                {
                    cout<<"ERROR: wrong number of (Relationship) params"<<endl;
                    break;
                }

               // Person* personOne=getPerson(info[0]);
                //Person* personTwo=getPerson(info[1]);

                Person* personOne = getPerson(currentPerson);
                Person* personTwo = getPerson(info[0]);

                if(!personOne)
                {
                    cout<< "<Relationship> is not following under a person"<<endl;
                    break;
                }
                if(!personTwo)
                {
                    cout<< info[0] << " was not found"<<endl;
                    break;
                }

                addRelationship(personOne, personTwo, S_TO_I(info[1]),S_TO_I(info[2]));
            }
            break;
        case 3: //Actions
            if(type.compare("Action")==0)
            {
                if(!(numParams == NUM_ACTION_PARAM || numParams == NUM_ACTION_PARAM_PLUS))
                {
                    cout<<"ERROR: wrong number of (Action) params"<<endl;
                    break;
                }

                Person* currPerson = getPerson(currentPerson);
                WorldObject* currItem = getItem(currentItem);

                //Create the action and stores it globally
                Action* action = getAction(info[0]);
                if(action == 0)
                    action = createAction(info[0]);

                //If action is to be given to a person or object
                //this statement should be true
                if(numParams==NUM_ACTION_PARAM_PLUS)
                {
                    string actionType = info[1];

                    if(currPerson==0)
                    {
                        if(currItem !=0)
                        {
                            if(actionType.compare("do")==0)
                                currItem->addActionDo(action);
                            else
                                currItem->addActionGet(action);
                        }
                    }
                    else
                    {
                        if(actionType.compare("do")==0)
                            currPerson->addActionDo(action);
                        else
                            currPerson->addActionGet(action);
                    }
                }
            }
            else
                if(type.compare("Location")==0)
                {

                     Person* currPerson = getPerson(currentPerson);
                     string locName = vectorToString(info,0,(int)info.size());
                     //to_lower(locName);
                     Location* loc = getLocation(locName);
                     if(loc == 0)
                     {
                         cout<<"ERROR: location "<<locName<<" not found"<<endl;
                         break;
                     }

                     currPerson->setCurrLocation(loc);
                }
            break;
        }
    }

}

Person* BulkLoader::createPerson(std::string name, int gender)
{

    people->push_back(new Person(name,gender));
    return people->back();
}

WorldObject *BulkLoader::createObject(std::string name)
{
    WorldObject* object = getItem(name);
    if(object != 0)
        return object;
    else
    {
        worldObjects->push_back(new WorldObject(name));
        return worldObjects->back();
    }
}

Action *BulkLoader::createAction(std::string name)
{
    actions->push_back(new Action(name));
    return actions->back();
}

Relationship *BulkLoader::addRelationship(Person *one, Person *two, int type, int status)
{
    if(one != 0 && two != 0)
    {
        relationships->push_back(new Relationship(one, two, type, status));
        return relationships->back();
    }
    return 0;
}

Person* BulkLoader::getPerson(std::string name)
{
    for(int index=0; index<(int)people->size(); index++)
    {
        if(people->at(index)->getName()==name)
            return people->at(index);
    }

    return 0;
}

WorldObject* BulkLoader::getItem(std::string name)
{
    for(int index=0; index<(int)worldObjects->size(); index++)
    {
        if(worldObjects->at(index)->getName()==name)
            return worldObjects->at(index);
    }

    return 0;
}

Action* BulkLoader::getAction(std::string name)
{
    for(int index=0; index<(int)actions->size(); index++)
    {
        if(actions->at(index)->getName()==name)
            return actions->at(index);
    }

    return 0;
}

Location* BulkLoader::getLocation(std::string name)
{
    for(int index=0; index<(int)locations->size(); index++)
    {
        if(locations->at(index)->getName()==name)
            return locations->at(index);
    }

    return 0;
}

string BulkLoader::vectorToString(vector<string> vec, int start, int end)
{
    if(end>(int)vec.size())
        end=vec.size();

    string output="";
    for(int index=start; index<(int)end; index++)
    {
        output = output+vec.at(index)+" ";
    }
    trim(output);
    to_lower(output);
    return output;
}
