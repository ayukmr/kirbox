#include "completion.h"
#include "utils.h"

namespace completion {

const int PIN_OPENER = 10;

CompletionHandler::CompletionHandler() : triggered(false) {}

void CompletionHandler::setup() {
    utils::setOutput(PIN_OPENER);
    utils::disablePin(PIN_OPENER);
}

void CompletionHandler::trigger() {
    utils::enablePin(PIN_OPENER);
    triggered = true;
}

bool CompletionHandler::getTriggered() {
    return triggered;
}

}
