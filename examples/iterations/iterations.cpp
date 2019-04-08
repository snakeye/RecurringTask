#include <Arduino.h>

#include <RecurringTask.h>

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    RecurringTask::every(1000, []() {
        Serial.println("This line should be printed 1000 iterations of main loop");
    });

    delay(1);
}