//
// Created by User on 5/7/2025.
//

#pragma once
#include "Timer.h"


class Benchmark {
private:
    double averageValueOffset;
    double averageTimeOffset;
    Timer timer;
    std::vector<int>* randomValues;
public:
    Benchmark();
    ~Benchmark();
    bool runBenchmark(int);
    void generateRandomValues(int) const;
    double getAverageValueOffset() const;
    double getAverageTimeOffset() const;
};



