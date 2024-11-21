#pragma once

#include <string>
#include "rapidcsv.h"
#include "analysisfunctions.h"

extern void parseCSV(std::string & filename, int columnHeaders = 0, int rowHeaders = 0, 
              char separator = ',');

extern void processRow(rapidcsv::Document & doc, int index);