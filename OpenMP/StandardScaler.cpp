#include "StandardScaler.h"
#include <omp.h>

double StandardScaler::calculateStandardDeviation(std::vector<dataSet *> *dataSet, int col, int rows, double mean) {
    double standardDeviation = 0;
    #pragma omp parallel for shared(standardDeviation, mean, rows, col)
    for (int row = 0; row < rows; row++) {
        auto temp = dataSet->at(row)->getFeatures()->at(col) - mean;
        standardDeviation += temp;
    }
    return (standardDeviation/rows)-1;
}

double StandardScaler::calculateMean(std::vector<dataSet *> *dataSet, int col, int rows) {
    double mean = 0;
    #pragma omp parallel for shared(dataSet, mean, rows, col)
    for (int row = 0; row < rows; row++) {
        auto temp = dataSet->at(row)->getFeatures()->at(col);
        mean += temp;
    }
    return mean/rows;
}

std::vector<dataSet *> *StandardScaler::runStandardization(Service *service, int &rowsOut, int &columnsOut) {
    auto dataset = service->getAllData();
    int rows = dataset->size();
    int columns = dataset->at(0)->getFeatures()->size();
    rowsOut = rows;
    columnsOut = columns;

    double* mean = new double[columns];
    double* std = new double[columns];

    #pragma omp parallel for shared(mean, std, columns, dataset)
    for(int i = 0; i < columns; i++) {
        mean[i] = calculateMean(dataset, i, rows);
        std[i] = calculateStandardDeviation(dataset, i, rows, mean[i]);
    }

    #pragma omp parallel for shared(mean, std, columns, dataset)
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            double value = (dataset->at(row)->getFeatures()->at(col) - mean[col])/std[col];
            dataset->at(row)->getFeatures()->at(col) = value;
        }
    }

    return dataset;
}

int main(int argc, char* argv[])
{
    int threads = 6;
    omp_set_num_threads(threads);

    Service *service = new Service();
    std::string path("../winequality-white.csv");

    service->readFeaturesFromCsv(path);
    double start = omp_get_wtime();
    StandardScaler *standardScaler = new StandardScaler();

    int rows, columns;
    auto scaledWithStandardScaler = standardScaler->runStandardization(service, rows, columns);
    double end = omp_get_wtime();

    service->writeFeaturesToCsv(scaledWithStandardScaler, rows, columns);

    double result = end - start;
    printf("Algorithm took: %f (seconds).\n", result);
}
