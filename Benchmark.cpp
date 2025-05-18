//
// Created by User on 5/7/2025.
//

#include "Benchmark.h"

#include <iostream>

#include "AverageCalculator.h"
#include "Random.h"
#include "RootCalculator.h"
#include "Timer.h"
#include "utility"

Benchmark::Benchmark() {
    timer={};
    averageValueOffset=-1;
    averageTimeOffset=-1;
    randomValues={std::make_unique<std::vector<int>>()};
}
void Benchmark::generateRandomValues(const int amount) const {
    for (int i = 0; i < amount; ++i) {
        randomValues->push_back(Random::get(1,1000000));
    }
}

Benchmark& Benchmark::operator=(Benchmark&& other) noexcept {
    if (this!=&other) {
        this->averageTimeOffset=other.averageTimeOffset;
        this->averageValueOffset=other.averageValueOffset;
        this->timer=other.timer;
        this->randomValues.reset();
        this->randomValues=std::move(other.randomValues);
        other.randomValues=nullptr;
    }
    return *this;
}

bool Benchmark::runBenchmark(const int amountOfRandomValues) {
    if (amountOfRandomValues<1) {
        return false;
    }
    generateRandomValues(amountOfRandomValues);
    auto* timerOffsets = new std::vector<double>();
    auto* valueOffsets = new std::vector<double>();
    for (int i = 0; i < amountOfRandomValues; ++i) {
        timer.reset();
        const auto approxValue=rootcalculator::calculateApproximateRoot(randomValues->at(i));
        const double approxTime=timer.elapsed();
        timer.reset();
        const auto exactValue=rootcalculator::calculateExactRoot<double>(randomValues->at(i));
        const double exactTime=timer.elapsed();
        timerOffsets->push_back(approxTime-exactTime);
        valueOffsets->push_back(std::abs(approxValue-exactValue));
    }
    averageValueOffset=AverageCalculator::calculateAverage<double>(*valueOffsets);
    averageTimeOffset=AverageCalculator::calculateAverage<double>(*timerOffsets);
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
    randomValues.reset();
    std::cout<<"Object destructed.";
}

Benchmark::Benchmark(const Benchmark& other) {
    this->averageTimeOffset=other.averageTimeOffset;
    this->averageValueOffset=other.averageValueOffset;
    this->timer=other.timer;
    this->randomValues={std::make_unique<std::vector<int>>()};
    std::ranges::copy(*other.randomValues, std::back_inserter(*(this->randomValues)));
}

Benchmark& Benchmark::operator=(const Benchmark& other) {
    if (this!=&other) {
        this->averageTimeOffset=other.averageTimeOffset;
        this->averageValueOffset=other.averageValueOffset;
        this->timer=other.timer;
        this->randomValues.reset();
        this->randomValues={std::make_unique<std::vector<int>>()};
        std::ranges::copy(*other.randomValues, std::back_inserter(*(this->randomValues)));
    }
    return *this;
}

Benchmark::Benchmark(Benchmark&& other) noexcept {
    this->averageTimeOffset=other.averageTimeOffset;
    this->averageValueOffset=other.averageValueOffset;
    this->timer=other.timer;
    this->randomValues=std::move(other.randomValues);
    other.randomValues=nullptr;
}



