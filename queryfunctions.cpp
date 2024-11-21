#include "queryfunctions.h"
#include "analysisfunctions.h"

void queryMeanMaxSpeedComparison() {
    /*

    calculates which players have a higher average maximum speed during game sessions than practice
    sessions

    */

    for (auto const& [key, val] : sumMaxSpeedPractice) {
        double meanMaxSpeedPractice = val / numPracticeSessions[key];
        double meanMaxSpeedGame = sumMaxSpeedGame[key] / numGameSessions[key];
        if (meanMaxSpeedGame > meanMaxSpeedPractice) {
            std::cout << key << "\n";
        }
    }
    std::cout << "\n";
}

void queryWorstMeanSleepQuality() {
    std::vector<std::string> names;
    double worstQuality = INF;
    for (auto const& [key, val] : sumSleepQuality) {
        double quality =  val / (double)(numPracticeSessions[key] + numGameSessions[key]);
        if (quality < worstQuality) {
            names.clear();
            names.push_back(key);
            worstQuality = quality;
        } else if (quality == worstQuality) {
            names.push_back(key);
        }
    }

    for (auto name : names) {
        std::cout << name << "\n";
    }
    std::cout << "\n";
}

void printMeanMaxSpeedPractice() {
    for (auto const& [key, val] : sumMaxSpeedPractice) {
        std::cout << key << " " << val / numPracticeSessions[key] << "\n";
    }
    std::cout << "\n";
}

void printMeanMaxSpeedGame() {
    for (auto const& [key, val] : sumMaxSpeedGame) {
        std::cout << key << " " << val / numGameSessions[key] << "\n";
    }
    std::cout << "\n";
}

void printMeanSleepQuality() {
    for (auto const& [key, val] : sumSleepQuality) {
        std::cout << key << " " << val / (double)(numPracticeSessions[key] + numGameSessions[key]) << "\n";
    }
    std::cout << "\n";
}

void printMedianSleepQuality() {
    for (auto & [key, val] : medianSleepQuality) {
        std::sort(val.begin(), val.end());
        size_t index = val.size() / 2;
        std::cout << key << " " << val[index] << "\n";
    }
    std::cout << "\n";
}

void printModeSleepQuality() {
    for (auto const& [key, val] : modeSleepQuality) {
        int maxFrequency = -1;
        double mostFrequent = -1;
        for (auto const& [innerKey, innerValue] : val) {
            if (innerValue > maxFrequency) {
                maxFrequency = innerValue;
                mostFrequent = innerKey;
            }
        }
        std::cout << key << " " << mostFrequent << "\n";
    }
    std::cout << "\n";
}