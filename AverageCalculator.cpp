//
// Created by User on 5/7/2025.
//

#include "AverageCalculator.h"
namespace AverageCalculator {
    template<typename T>
    T calculateAverage(const std::vector<T>& data) {
        T sum = 0;
        for (const T number : data) {
            sum+=number;
        }
        return static_cast<long double>(sum)/data.size();
    }
    template double calculateAverage<double>(const std::vector<double>&);
}