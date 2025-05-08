//
// Created by User on 5/7/2025.
//
#include "Timer.h"

#include <chrono>

    // Type aliases to make accessing nested type easier




    void Timer::reset()
    {
        m_beg = Clock::now();
    }

    [[nodiscard]] double Timer::elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
