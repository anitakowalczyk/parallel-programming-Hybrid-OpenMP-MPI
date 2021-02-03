#include "Service.h"
#include <stdlib.h>
#include <sstream>
#include <cstdio>


Service::Service() {
    allData = new std::vector<dataSet *>;
}
Service::~Service() = default;

void Service::writeFeaturesToCsv(std::vector<dataSet *> *dataset, int rows, int columns) {
    std::ofstream file("data.csv");

    int counter = 0;
    for(int i = 0; i < rows; ++i)    {
        for(int j = 0; j < columns; ++j)
        {
            auto value = dataset->at(i)->getFeatures()->at(j);
            counter++;
            file << value;
            if (!(j != columns)) continue;
            file << ",";
        }
        file << dataset->at(i)->getLabel();
        file << "\n";
    }
    file.close();
}

void Service::readFeaturesFromCsv(std::string filename) {
    std::ifstream featuresFile(filename);
    std::string line;
    std::getline(featuresFile, line);
    int countColumns = countWords(line, ',') - 1;

    while(std::getline(featuresFile, line))
    {
        std::stringstream ss(line);
        int column = 0;
        dataSet *data = new dataSet();
        double value;
        while(ss >> value){
            if (column != countColumns) {
                data->addToFeatures(value);
            } else {
                data->setLabel(value);
            }
            column++;
            if(ss.peek() == ',') ss.ignore();
        }

        allData->push_back(data);
    }
    featuresFile.close();
}

std::vector<dataSet *> *Service::getAllData() {
    return allData;
}

int Service::countWords(const std::string& text, char delimiter) {
    std::stringstream stream(text);
    std::string temp;
    int counter = 0;
    while(getline(stream, temp, delimiter)) {
        counter++;
    }

    return counter;
}