#include "parsingfunctions.h"

void parseCSV(std::string & filename, int columnHeaders, int rowHeaders, char separator) {
    /*

    parses a CSV file using the rapidcsv library

    columnHeaders should be set to 0 if there are column headers in the CSV and to -1 otherwise
    rowHeaders should be set to 0 if there are row headers in the CSV and to -1 otherwise
    if the file uses an alternative separator, it can be specified using the separator parameter

    */

    rapidcsv::Document doc(filename, rapidcsv::LabelParams(columnHeaders, rowHeaders),
                           rapidcsv::SeparatorParams(separator));

    size_t columnCount = doc.GetColumnCount();
    size_t rowCount = doc.GetRowCount();

    for (size_t index = 0; index < rowCount; ++index) {
        processRow(doc, index);
    }
}

void processRow(rapidcsv::Document & doc, int index) {
    /*

    processes a row of the CSV file

    */

    std::string name = doc.GetCell<std::string>("Name", index);
    std::string sessionType = doc.GetCell<std::string>("Session_Type", index);
    float sleepQuality = doc.GetCell<float>("Sleep_Quality", index);
    float maxSpeed = doc.GetCell<float>("Max_Speed", index);

    if (sessionType == "Practice") {
        calculateMaxSpeedPractice(name, maxSpeed);
    } else {
        calculateMaxSpeedGame(name, maxSpeed);
    }

    calculateSleepQuality(name, sleepQuality);
}