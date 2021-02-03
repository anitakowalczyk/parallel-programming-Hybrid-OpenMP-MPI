#include "stdint.h"
#include "stdio.h"
#include <vector>

class dataSet {
    std::vector<double> *featureVector;
    int label{};

public:
    dataSet();
    ~dataSet();
    void setLabel(int val);
    int getLabel() const;
    void addToFeatures(double val);
    std::vector<double> * getFeatures();
};