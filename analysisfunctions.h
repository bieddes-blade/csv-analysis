#pragma once

#include <map>
#include <string>
#include <vector>

extern std::map<std::string, float> sumMaxSpeedPractice, sumMaxSpeedGame, sumSleepQuality;
extern std::map<std::string, int> numPracticeSessions, numGameSessions;
extern std::map<std::string, std::vector<float>> medianSleepQuality;
extern std::map<std::string, std::map<float, int>> modeSleepQuality;

extern void calculateMaxSpeedPractice(std::string & name, float maxSpeed);

extern void calculateMaxSpeedGame(std::string & name, float maxSpeed);

extern void calculateSleepQuality(std::string & name, float sleepQuality);