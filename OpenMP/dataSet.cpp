#include "dataSet.h"

dataSet::dataSet() {
    featureVector = new std::vector<double>;
}

dataSet::~dataSet() = default;

void dataSet::addToFeatures(double val) {
    featureVector->push_back(val);
}

void dataSet::setLabel(int val) {
    label = val;
}

int dataSet::getLabel() const {
    return label;
}

std::vector<double> *dataSet::getFeatures() {
    return featureVector;
}