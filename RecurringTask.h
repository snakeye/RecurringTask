#pragma once

namespace RecurringTask
{

template <typename F>
void every(int iterations, const F &lambda)
{
    static int iterationsCount = 0;

    iterationsCount++;
    if (iterationsCount >= iterations)
    {
        lambda();
        iterationsCount = 0;
    }
}

template <typename F>
void interval(unsigned long milliseconds, const F &lambda)
{
    static unsigned long lastExecution = 0;

    unsigned long now = millis();
    if (now > (lastExecution + milliseconds))
    {
        lambda();
        lastExecution = now;
    }
}

} // namespace RecurringTask