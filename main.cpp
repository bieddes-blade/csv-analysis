#include "rapidcsv.h"
#include "parsingfunctions.h"
#include "analysisfunctions.h"
#include "queryfunctions.h"

int main() {
    std::string filename = "Soccer Performance Data.csv";
    parseCSV(filename, 0, -1);
    printMeanMaxSpeedPractice();
    printMeanMaxSpeedGame();
    printMeanSleepQuality();
    printMedianSleepQuality();
    printModeSleepQuality();
    queryMeanMaxSpeedComparison();
    queryWorstMeanSleepQuality();
}