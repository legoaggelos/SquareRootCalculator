//
// Created by User on 5/7/2025.
//

#pragma once
#include "Timer.h"


class Benchmark {
    double averageValueOffset;
    double averageTimeOffset;
    Timer timer;
    std::unique_ptr<std::vector<int>> randomValues;
public:
    Benchmark();
    ~Benchmark();
    Benchmark(const Benchmark&);
    Benchmark& operator=(const Benchmark&);
    Benchmark(Benchmark&&) noexcept ;
    Benchmark& operator=(Benchmark&&) noexcept ;
    bool runBenchmark(int);
    void generateRandomValues(int) const;
    double getAverageValueOffset() const;
    double getAverageTimeOffset() const;
};



