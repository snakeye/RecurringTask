# Recurring Task

The RecurringTask library provides an easy way to schedule recurring tasks in Arduino-based projects. It allows you to execute a task at regular intervals or every certain number of iterations. The library supports two types of task scheduling:

* Every N iterations: Executes a task every N times the function is called.
* Time interval: Executes a task after a specified time interval (in milliseconds).

This library is designed to be lightweight, flexible, and easy to integrate into your Arduino and PlatformIO projects.

When you make something with Arduino the following snipped should be very familiar to you.

```cpp
void loop() {
  static unsigned long last = 0;

  unsigned long now = millis();
  if (now > (last + 1000)) {
    Serial.println("This line should be printed every second");
    last = now;
  }
}
```

It's widely used when you want to execute some task with period different from the main loop.

After writing the same code multiple times I extracted small but very semanticaly efficient library called *RecurringTask*. The idea and usage is very simple - you just define the period of execution in milliseconds or number of loop iterations and the library does the rest:

```cpp
#include <RecurringTask.h>

void loop()
{
    RecurringTask::interval(1000, []() {
        Serial.println("This line should be printed every second");
    });
}
```

## Functions

### RecurringTask::every()

```cpp
template <typename F>
void every(unsigned long iterations, const F &lambda);
```

* iterations: The number of iterations before the task is executed again.
* lambda: A lambda function or any callable object to execute when the specified number of iterations is reached.

### RecurringTask::interval()

```cpp
template <typename F>
void interval(unsigned long milliseconds, const F &lambda);
```

* milliseconds: The time interval in milliseconds after which the task is executed.
* lambda: A lambda function or any callable object to execute when the time interval has passed.

## Notes

* The `every()` function counts the number of calls to the function it’s inside (typically `loop()` in Arduino).
* The `interval()` function uses millis() to track time and can overflow after about 50 days. Consider adding overflow protection if running for extended periods.
* This library is designed for simple, lightweight recurring tasks in microcontroller-based projects.

## License

This library is open-source and available under the MIT License. See the LICENSE file for more details.