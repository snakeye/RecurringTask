# Recurring Task

The RecurringTask library provides an easy way to schedule recurring tasks in Arduino-based projects. It allows you to execute a task at regular intervals or every certain number of iterations. The library supports two types of task scheduling:

* Every N iterations: Executes a task every N times the function is called.
* Time interval: Executes a task after a specified time interval (in milliseconds).

This library is designed to be lightweight, flexible, and easy to integrate into your Arduino and PlatformIO projects.

When you make something with Arduino the following snippet should be very familiar to you. We don't want to lock the loop for the whole second, but we do not need to print the message with every call.

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

After repeatedly writing the same code, I decided to extract it into a small yet highly efficient library called *RecurringTask*. The concept and usage are straightforward — simply define the execution period in milliseconds or the number of loop iterations, and the library takes care of the rest.

```cpp
#include <RecurringTask.h>

void printEverySecond() 
{
  Serial.println("This line should be printed every second");
}

void loop()
{
    RecurringTask::interval(1000, printEverySecond);
}
```

## Functions

### RecurringTask::every()

```cpp
template <typename Callable>
unsigned long every(unsigned long iterations, const Callable &task)
```

* iterations: The number of iterations before the task is executed again.
* callable: A lambda function or any callable object to execute when the specified number of iterations is reached.

### RecurringTask::interval()

```cpp
template <typename Callable>
void interval(unsigned long milliseconds, const Callable &task)
```

* milliseconds: The time interval in milliseconds after which the task is executed.
* callable: A lambda function or any callable object to execute when the time interval has passed.

## Notes

* The `every()` function counts the number of calls to the function it’s inside (typically `loop()` in Arduino).
* The `interval()` function uses millis() to track time and can overflow after about 50 days. Consider adding overflow protection if running for extended periods.
* This library is designed for simple, lightweight recurring tasks in microcontroller-based projects.

## License

This library is open-source and available under the MIT License. See the LICENSE file for more details.