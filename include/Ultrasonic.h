#pragma once
#include <Arduino.h>

class Ultrasonic {
   private:
   // Pin declaration
    int trigPin, echoPin;
    int echoState = LOW;
    bool inProgress = false;
    long startTime = 0;

   public:
    Ultrasonic(const int, const int);
    ~Ultrasonic();

    int begin();

    float update();
    float calculateDistance(long start, long end);
};