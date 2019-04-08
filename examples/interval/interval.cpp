#include <Arduino.h>

#include <RecurringTask.h>

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    RecurringTask::interval(1000, []() {
        Serial.println("This line should be printed every 1000 milliseconds");
    });
}