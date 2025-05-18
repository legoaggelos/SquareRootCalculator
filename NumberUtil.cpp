//
// Created by User on 5/7/2025.
//

#include "NumberUtil.h"

#include <cmath>
#include <iostream>

namespace numberutil {
    long  findClosestNumberInOrderedList(const std::vector<long>& list, const long number) {
        long high=list.size()-1;
        long middleValue;
        long low = 0;
        while (high-low>1) {
            const long middle = low+(high-low)/2;
            middleValue = list[middle];
            if (middleValue>number) {
                high=middle;
            } else if (middleValue<number){
                low=middle;
            } else if (middleValue==number) {
                return middleValue;
            }
        }
        if (std::abs(list[high]-number)>std::abs(list[low]-number)) {
            return list[low];
        }
        return list[high];
    }
}
