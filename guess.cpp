#include "guess.h"
#include "utils.h"

namespace guess {

const int PIN_AG = 5;
const int PIN_HM = 6;
const int PIN_NS = 7;
const int PIN_TZ = 8;
const int PIN_CLEAR = 9;

const int PINS[] = {PIN_AG, PIN_HM, PIN_NS, PIN_TZ};

GuessHandler::GuessHandler() : buffer{}, count(0), completed(false) {}

void GuessHandler::setup() {
    utils::setOutput(PIN_AG);
    utils::setOutput(PIN_HM);
    utils::setOutput(PIN_NS);
    utils::setOutput(PIN_TZ);
    utils::setOutput(PIN_CLEAR);
}

void GuessHandler::update() {
    if (completed) {
        return;
    }

    if (utils::buttonPressed(PIN_CLEAR)) {
        for (int& letter : buffer) {
            letter = 0;
        }

        count = 0;
    } else {
        for (const int& pin : PINS) {
            if (pin != lastButton && count < 10 && utils::buttonPressed(pin)) {
                buffer[count] = pin;
                count += 1;

                lastButton = pin;
            }
        }
    }

    if (lastButton != -1 && !utils::buttonPressed(lastButton)) {
        lastButton = -1;
    }

    completed =
        buffer[0] == PIN_HM &&
        buffer[1] == PIN_HM &&
        buffer[2] == PIN_HM &&
        buffer[3] == PIN_AG &&
        buffer[4] == PIN_TZ;
}

bool GuessHandler::getCompleted() {
    return completed;
}

}
