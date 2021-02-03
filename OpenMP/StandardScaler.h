#ifndef PRIR_STANDARDSCALER_H
#define PRIR_STANDARDSCALER_H

#include "Service.h"
#include <vector>

class StandardScaler {
public:
    StandardScaler() = default;
    ~StandardScaler() = default;
    std::vector<dataSet *> * runStandardization(Service *service, int &rowsOut, int &columnsOut);
    double calculateStandardDeviation(std::vector<dataSet *> *data, int col, int rows, double mean);
    double calculateMean(std::vector<dataSet *> *data, int col, int n_row);
};

#endif //PRIR_STANDARDSCALER_H