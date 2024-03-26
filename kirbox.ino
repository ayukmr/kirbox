#include "color.h"
#include "guess.h"

#include "Servo.h"

using color::ColorHandler;
using guess::GuessHandler;

ColorHandler colorHandler;
GuessHandler guessHandler;

Servo servo;
bool completed = false;

void setup() {
    colorHandler.setup();
    guessHandler.setup();
    Serial.begin(9600);
}

void loop() {
    if (completed) {
        return;
    }

    colorHandler.update();
    guessHandler.update();

    if (colorHandler.getCompleted() && guessHandler.getCompleted()) {
        completed = true;

        servo.attach(10);
        servo.write(180);

        delay(125);

        servo.write(90);
        servo.detach();
    }
}
