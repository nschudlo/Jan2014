#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include <vector>

#include "storygoal.h"
#include "story.h"

class Director
{
public:
    static Director* Instance();

    void loadGoals(std::string filename);
    void loadStories(std::string filename);

private:
    Director(){}
    static Director* m_pInstance;

    void evaluateGoalLine(std::string line);
    void evaluateStoryLine(std::string line);
    std::string vectorToString(std::vector<std::string> vec,int start, int end);

    StoryGoal *currentGoal;
    Story *currentStory;

    std::vector<StoryGoal*> storyGoals;
    std::vector<Story*> stories;

};

#endif // DIRECTOR_H
