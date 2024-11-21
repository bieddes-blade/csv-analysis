#include "analysisfunctions.h"

std::map<std::string, float> sumMaxSpeedPractice, sumMaxSpeedGame, sumSleepQuality;
std::map<std::string, int> numPracticeSessions, numGameSessions;
std::map<std::string, std::vector<float>> medianSleepQuality;
std::map<std::string, std::map<float, int>> modeSleepQuality;

void calculateMaxSpeedPractice(std::string & name, float maxSpeed) {
    /*

    to calculate the mean maximum speed of each player during practice sessions, we need to count
    the sum of all maximum speeds (stored in sumMaxSpeedPractice) and divide it by the number
    of practice sessions each player participated in (stored in numPracticeSessions)

    */

    if (sumMaxSpeedPractice.find(name) == sumMaxSpeedPractice.end()) {
        sumMaxSpeedPractice[name] = maxSpeed;
    } else {
        sumMaxSpeedPractice[name] += maxSpeed;
    }

    if (numPracticeSessions.find(name) == numPracticeSessions.end()) {
        numPracticeSessions[name] = 1;
    } else {
        numPracticeSessions[name] += 1;
    }
}

void calculateMaxSpeedGame(std::string & name, float maxSpeed) {
    /*

    to calculate the mean maximum speed of each player during game sessions, we need to count
    the sum of all maximum speeds (stored in sumMaxSpeedGame) and divide it by the number
    of game sessions each player participated in (stored in numGameSessions)

    */

    if (sumMaxSpeedGame.find(name) == sumMaxSpeedGame.end()) {
        sumMaxSpeedGame[name] = maxSpeed;
    } else {
        sumMaxSpeedGame[name] += maxSpeed;
    }

    if (numGameSessions.find(name) == numGameSessions.end()) {
        numGameSessions[name] = 1;
    } else {
        numGameSessions[name] += 1;
    }
}

void calculateSleepQuality(std::string & name, float sleepQuality) {
    /*

    to calculate the mean sleep quality for each player, we need to count the sum of all sleep
    qualities (stored in sumSleepQuality) and divide it by the number of sessions each player
    participated in (numPracticeSessions + numGameSessions)

    */

    if (sumSleepQuality.find(name) == sumSleepQuality.end()) {
        sumSleepQuality[name] = sleepQuality;
    } else {
        sumSleepQuality[name] += sleepQuality;
    }

    /*

    to calculate the median sleep quality for each player, we need to store all sleep qualities for
    each player in a vector, sort the vector, and choose the value in the middle

    */

    if (medianSleepQuality.find(name) == medianSleepQuality.end()) {
        medianSleepQuality[name] = std::vector<float>();
    }
    medianSleepQuality[name].push_back(sleepQuality);

    /*

    to calculate the mode sleep quality for each player, we need to store the frequencies of different
    sleep qualities for each player in a map and choose the most frequent sleep quality

    */

    if (modeSleepQuality[name].find(sleepQuality) == modeSleepQuality[name].end()) {
        modeSleepQuality[name][sleepQuality] = 1;
    } else {
        modeSleepQuality[name][sleepQuality] += 1;
    }
}