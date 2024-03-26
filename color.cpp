#include "color.h"
#include "utils.h"

namespace color {

const int PIN_R = 2;
const int PIN_G = 3;
const int PIN_B = 4;

ColorHandler::ColorHandler() : completed(false) {}

void ColorHandler::setup() {
    utils::setOutput(PIN_R);
    utils::setOutput(PIN_G);
    utils::setOutput(PIN_B);
}

void ColorHandler::update() {
    if (completed) {
        return;
    }

    completed =
        utils::buttonPressed(PIN_G) &&
        utils::buttonPressed(PIN_B) &&
        !utils::buttonPressed(PIN_R);
}

bool ColorHandler::getCompleted() {
    return completed;
}

}
