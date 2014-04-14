#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include <vector>

#include "storygoal.h"
#include "story.h"

class Story;

class Director
{
public:
    static Director* Instance();

    void runStoryLoop();

    void loadGoals(std::string filename);
    void loadStories(std::string filename);

    std::vector<Condition*> getGoalQueue();
    std::vector<Story*> getStories();
    std::vector<Story*> getStoryQueue();
    std::vector<Story*> getTriggerStories();
    Story* getCurrentActiveStory();

    // StoryGoal* getGoal(std::string name);
    Story* getStory(std::string name);

    void addStoryGoal(Condition * condition);
    void addToStoryQueue(Story* story);

    bool compareConditions(Condition* condition1, Condition* condition2);
    bool compareConditionsSet(Condition* condition1, Condition* condition2);
    void findStory(Condition* condition);

    void completeActiveStory();

private:
    Director();
    static Director* m_pInstance;
    Evaluator* evaluator;

    void evaluateGoalLine(std::string line);
    void evaluateStoryLine(std::string line);
    std::string vectorToString(std::vector<std::string> vec,int start, int end);

    //StoryGoal *currentGoal;
    Story *currentStory, *activeStory;

    std::vector<Story*> possibleStories; //all stories
    std::vector<Story*> triggerStories; //stories with all pre
    std::vector<Story*> storyQueue; //List of currently active

    // std::vector<StoryGoal*> storyGoals;
    std::vector<Story*> stories;


    std::vector<Condition*> goalQueue;

    bool changeMade;

};

#endif // DIRECTOR_H
