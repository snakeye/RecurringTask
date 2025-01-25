#pragma once

namespace RecurringTask
{

    template <typename Callable>
    unsigned long every(unsigned long iterations, const Callable &task)
    {
        static unsigned long iterationsCount = 0;

        iterationsCount++;
        if (iterationsCount >= iterations)
        {
            task();
            iterationsCount = 0;
        }

        return iterationsCount;
    }

    template <typename Callable>
    void interval(unsigned long milliseconds, const Callable &task)
    {
        static unsigned long lastExecution = 0;

        unsigned long now = millis();
        if ((now - lastExecution) >= milliseconds)
        {
            task();
            lastExecution = now;
        }
    }

} // namespace RecurringTask
