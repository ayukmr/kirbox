#include "utils.h"
#include "arduino.h"

namespace utils {

void setInput(int pin) {
    pinMode(pin, INPUT);
}

void setOutput(int pin) {
    pinMode(pin, OUTPUT);
}

void enablePin(int pin) {
    digitalWrite(pin, HIGH);
}

void disablePin(int pin) {
    digitalWrite(pin, LOW);
}

bool buttonPressed(int pin) {
    return digitalRead(pin) == HIGH;
}

}
