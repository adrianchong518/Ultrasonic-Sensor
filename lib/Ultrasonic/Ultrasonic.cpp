#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(const int _trigPin, const int _echoPin) {
    trigPin = _trigPin;
    echoPin = _echoPin;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

Ultrasonic::~Ultrasonic() {}

int Ultrasonic::begin() {
    if (inProgress) {
        return -1;
    } else {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(5);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        inProgress = true;
        return 0;
    }
}

float Ultrasonic::update() {
    int echo = digitalRead(echoPin);
    if (echo != echoState) {
        echoState = echo;
        if (echoState == HIGH) {
            startTime = micros();
        } else {
            inProgress = false;
            return calculateDistance(startTime, micros());
        }
    }

    return -1;
}

float Ultrasonic::calculateDistance(long start, long end) {
    if (end - start >= 125000) {
        return -1;
    }
    long duration = end - start;
    float distance = duration * 0.0343 / 2;

    return distance;
}