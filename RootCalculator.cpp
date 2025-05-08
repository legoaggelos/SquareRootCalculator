//
// Created by User on 5/7/2025.
//

#include "RootCalculator.h"

#include <vector>

#include "NumberUtil.h"
#include "root_table_generator.h"
#include <cmath>

namespace RootCalculator {
    double calculateApproximateRoot(int number) {
        if (number<0) {
            return -1;
        }
        std::vector<long> table = RootTableGenerator::generatePerfectSquareVector(std::min(number,32000));
        int nearestPerfectSquare = NumberUtil::findClosestNumberInOrderedList(table, number);
        return static_cast<double>(number+nearestPerfectSquare)/(2*calculateExactRootOfExactSquare(nearestPerfectSquare));
        //TODO: extract last part in separate method
    }

    int calculateExactRootOfExactSquare(int number) {
        return RootTableGenerator::generateReversedTableUpTo(std::min(number,32000)).at(number);
    }

    double calculateExactRoot(int number) {
        return std::sqrt(number);
    }

}
