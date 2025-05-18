#pragma once
#include <cstdint>
#include <map>
#include <vector>

namespace roottablegenerator {
    std::map<int, long> generateTableUpTo(int=100);
    std::map<int, long> generateReversedTableUpTo(int=100);
    std::vector<long> generatePerfectSquareVector(int=100);
}


