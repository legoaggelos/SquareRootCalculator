//
// Created by User on 5/7/2025.
//
#include "RootTableGenerator.h"
#include "NumberUtil.h"
namespace roottablegenerator {
    std::map<int, long> generateTableUpTo(const int limit) {
        std::map<int, long> map = {};
        for (std::int16_t i = 0; i <= limit; i++) {
            map.insert({static_cast<int>(i), static_cast<long>(i)*static_cast<long>(i)});
        }
        return map;
    }
    std::map<int, long> generateReversedTableUpTo(const int limit) {
        std::map<int, long> map = {};
        for (std::int16_t i = 0; i <= limit; i++) {
            map.insert({static_cast<long>(i)*static_cast<long>(i),static_cast<int>(i)});
        }
        return map;
    }
    std::vector<long> generatePerfectSquareVector(const int limit) {
        std::vector<long> vec = {};
        for (int i = 0; i <= limit; ++i) {
            vec.push_back(static_cast<long>(i)*static_cast<long>(i));
        }
        return vec;
    }
}