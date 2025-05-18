//
// Created by User on 5/7/2025.
//

#include "rootcalculator.h"

#include <vector>

#include "NumberUtil.h"
#include "RootTableGenerator.h"
#include <cmath>

namespace rootcalculator {
    static const auto table = roottablegenerator::generatePerfectSquareVector(32000);
    static const auto reversedTable = roottablegenerator::generateReversedTableUpTo(32000);
    template<typename T>
    T calculateApproximateRoot(const T number) {
        if (number<0) {
            return -1;
        }
        const int nearestPerfectSquare = numberutil::findClosestNumberInOrderedList(table, number);
        return calculateApproximateRoot(number, nearestPerfectSquare);

    }
    template int calculateApproximateRoot<int>(int);
    template<typename T>
    T calculateApproximateRoot(const T number, const long nearestPerfectSquare) {
        if (number<0) {
            return -1;
        }
        return static_cast<double>(number+nearestPerfectSquare)/(2*calculateExactRootOfExactSquare(nearestPerfectSquare));
    }
    int calculateExactRootOfExactSquare(const int number) {
        return reversedTable.at(number);
    }
    template<typename T>
    T calculateExactRoot(const T number) {
        return std::sqrt(number);
    }
    template double calculateExactRoot<double>(double);
}
