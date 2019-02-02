#include <Arduino.h>
#include "Ultrasonic.h"

const int TRIG = 6, ECHO = 7;
Ultrasonic ultrasonic(TRIG, ECHO);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int distance = ultrasonic.update();
    if (distance == -1) {
        ultrasonic.begin();
    } else {
        Serial.println(distance);
    }
}