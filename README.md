# Recurring Task

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