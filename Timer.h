//
// Created by User on 5/7/2025.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer {
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg{ Clock::now() };
public:
    void reset();
    [[nodiscard]] double elapsed() const;
};
#endif //TIMER_H
