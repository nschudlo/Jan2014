#include "locationloader.h"
#include "location.h"

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <fstream>

using namespace std;

LocationLoader::LocationLoader(std::vector<Location*> *_locations, string filename)
{
    locations = _locations;
    loadfile(filename);
}

void LocationLoader::loadfile(string filename)
{
    string line;
    ifstream file(filename.c_str());

    string currentLocation ="";

    //Open the file
    if(file.is_open())
    {
        while(getline(file, line))
        {
            testString(line, currentLocation);
        }
        file.close();
    }
    else cout<<"Unable to open file "<<filename<<endl;
}

void LocationLoader::testString(string line, string &currentLocation)
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

        //If a major location
        if(type.compare("Location")==0)
        {
            string loc = vectorToString(info,0,info.size());
            createLocation(loc);
            currentLocation = loc;
        }
        else //A location the current location can go to
            if(type.compare("GoTo")==0)
            {
                string loc ="";
                if(info.at(0).compare("Both")==0)
                    loc = vectorToString(info,1,info.size());
                else
                    loc = vectorToString(info,0,info.size());

                Location* newLoc = createLocation(loc);
                Location* currLoc = getLocation(currentLocation);

                if(currLoc==0)
                {
                    cout<<"Current location not found"<<endl;
                    return;
                }

                currLoc->addGoTo(newLoc);
                newLoc->addComeFrom(currLoc);

                //If the new location can also travel back
                if(info.at(0).compare("Both")==0)
                {
                    newLoc->addGoTo(currLoc);
                    currLoc->addComeFrom(newLoc);
                }
            }
    }
}

string LocationLoader::vectorToString(vector<string> vec, int start, int end)
{
    if(end>vec.size())
        end=vec.size();

    string output="";
    for(int index=start; index<(int)end; index++)
    {
        output = output+vec.at(index)+" ";
    }
    return output;
}

Location* LocationLoader::createLocation(string name)
{
    //Prevents creating the same location multiple times
    Location* loc = getLocation(name);
    if(loc==0)
    {
        locations->push_back(new Location(name));
        return locations->back();
    }
    else
        return loc;
}

Location* LocationLoader::getLocation(std::string name)
{
    for(int index=0; index<(int)locations->size(); index++)
    {
        if(locations->at(index)->getLocation()==name)
            return locations->at(index);
    }
    return 0;
}
