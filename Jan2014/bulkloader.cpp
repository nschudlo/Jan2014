#include "bulkloader.h"
#include <person.h>
#include <relationship.h>
#include <worldobject.h>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <fstream>
#include <string>
//CYCLE_MAX is used to count the number of different items in the bulk load file
//<Item><Action><Person><Relationship>
#define CYCLE_MAX 3
#define NUM_PERSON_PARAM 2
#define NUM_ITEM_PARAM 1
#define NUM_RELATIONSHIP_PARAM 4
#define NUM_ACTION_PARAM 1

#define S_TO_I(string) boost::lexical_cast<int>(string)


using namespace std;
//using namespace boost;

//enum BulkFileType{=0,=1,=2};

BulkLoader::BulkLoader(vector<WorldObject*> *_worldObjects,vector<Relationship*> *_relationships,vector<Person*> *_people)
{

    worldObjects = _worldObjects;
    relationships = _relationships;
    people = _people;
    // Person* nick = createPerson("Nick",0);
    // people->push_back(nick);
    // Person* nikki = createPerson("Nikki",1);
    // people->push_back(nikki);

    // relationships->push_back(addRelationship(nick, nikki, 0, 2));
    // relationships->push_back(addRelationship(nikki,nick,5,1));

    loadfile("BulkLoad.txt");

}

void BulkLoader::loadfile(string filename)
{
    string line;
    ifstream file(filename.c_str());

    string currentPerson;

    //Open the file
    if(file.is_open())
    {

        //Cycle through the file, looking for different
        //types everytime
        for(int cycle=0; cycle<CYCLE_MAX; cycle++)
        {
            cout<<"NEW CYCLE"<<endl;
            while(getline(file, line))
            {
                testString(line,cycle, currentPerson);
            }
            file.clear();
            file.seekg(0,ios::beg);
        }
        file.close();
    }
    else cout<<"Unable to open file "<<filename<<endl;
}

void BulkLoader::testString(string line, int cycle, string &currentPerson)
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


        //vector<string> tokens;
        //tokens.assign(tok.begin(),tok.end());
        //cout<<"Number of tokens is " <<std::distance(tok.begin(),tok.end())<<endl;

        //tokens[0];

        //BOOST_FOREACH(string t, tokens)
        //{
        //    cout << t<<"."<<endl;
        //}

        //After the first cycle store which person was last seen
        //This is for use in the bulk load file. The bulk load can
        //give a person items or relationships by listing these after
        //declaring the person
        if(cycle !=0 && type.compare("Person")==0)
        {
            currentPerson = info[0];
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

                //cout<<info[0]<<endl;


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

                //cout<<type<<endl;
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
                Person* personOne=getPerson(info[0]);
                Person* personTwo=getPerson(info[1]);
                if(!personOne)
                {
                    cout<< info[0] << " was not found"<<endl;
                    break;
                }
                if(!personTwo)
                {
                    cout<< info[1] << " was not found"<<endl;
                    break;
                }



                addRelationship(personOne, personTwo, S_TO_I(info[2]),S_TO_I(info[3]));
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
    worldObjects->push_back(new WorldObject(name));
    return worldObjects->back();
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
    for(int index=0; index<(int)people->size(); index++)
    {
        if(worldObjects->at(index)->getName()==name)
            return worldObjects->at(index);
    }

    return 0;
}