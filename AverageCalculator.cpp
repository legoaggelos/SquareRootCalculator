//
// Created by User on 5/7/2025.
//

#include "AverageCalculator.h"
namespace AverageCalculator {
    double calculateAverage(std::vector<double>* data) {
        long double sum = 0;
        long count = 0;
        for (const double number : *data) {
            count++;
            sum+=number;
        }
        return (sum)/count;
    }
}