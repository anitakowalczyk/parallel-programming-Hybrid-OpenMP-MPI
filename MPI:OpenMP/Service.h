#ifndef PRIR_Service_H
#define PRIR_Service_H

#include <fstream>
#include "stdint.h"
#include <string>
#include <map>
#include <unordered_set>
#include "dataSet.h"
#include <vector>

class Service {
    std::vector<dataSet *> *allData;

public:
    Service();
    ~Service();
    std::vector<dataSet *> *getAllData();
    void writeFeaturesToCsv(double *dataset, int rows, int columns);
    void readFeaturesFromCsv(std::string file);
    int countWords(const std::string& text, char delimiter);
};

#endif //PRIR_Service_H