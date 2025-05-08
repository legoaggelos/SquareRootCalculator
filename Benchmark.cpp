//
// Created by User on 5/7/2025.
//

#include "Benchmark.h"

#include <iostream>

#include "AverageCalculator.h"
#include "Random.h"
#include "RootCalculator.h"
#include "Timer.h"

Benchmark::Benchmark() {
    timer={};
    averageValueOffset=-1;
    averageTimeOffset=-1;
    randomValues = new std::vector<int>();
}
void Benchmark::generateRandomValues(int amount) const {
    for (int i = 0; i < amount; ++i) {
        randomValues->push_back(Random::get(1,1000000));
    }
}

bool Benchmark::runBenchmark(int amountOfRandomValues) {
    if (amountOfRandomValues<1) {
        return false;
    }
    generateRandomValues(amountOfRandomValues);
    auto* timerOffsets = new std::vector<double>();
    auto* valueOffsets = new std::vector<double>();
    for (int i = 0; i < amountOfRandomValues; ++i) {
        timer.reset();
        double approxValue=RootCalculator::calculateApproximateRoot(randomValues->at(i));
        double approxTime=timer.elapsed();
        timer.reset();
        double exactValue=RootCalculator::calculateExactRoot(randomValues->at(i));
        double exactTime=timer.elapsed();
        timerOffsets->push_back(approxTime-exactTime);
        valueOffsets->push_back(std::abs(approxValue-exactValue));
    }
    averageValueOffset=AverageCalculator::calculateAverage(valueOffsets);
    averageTimeOffset=AverageCalculator::calculateAverage(timerOffsets);
    delete timerOffsets;
    delete valueOffsets;
    return true;
}
double Benchmark::getAverageTimeOffset() const {
    return averageTimeOffset;
}
double Benchmark::getAverageValueOffset() const {
    return averageValueOffset;
}


Benchmark::~Benchmark() {
    delete randomValues;
    std::cout<<"Object destructed.";
}



