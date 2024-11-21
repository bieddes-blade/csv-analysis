#pragma once

#include <map>
#include <string>
#include <vector>

extern std::map<std::string, double> sumMaxSpeedPractice, sumMaxSpeedGame, sumSleepQuality;
extern std::map<std::string, int> numPracticeSessions, numGameSessions;
extern std::map<std::string, std::vector<double>> medianSleepQuality;
extern std::map<std::string, std::map<double, int>> modeSleepQuality;

extern void calculateMaxSpeedPractice(std::string & name, double maxSpeed);

extern void calculateMaxSpeedGame(std::string & name, double maxSpeed);

extern void calculateSleepQuality(std::string & name, double sleepQuality);