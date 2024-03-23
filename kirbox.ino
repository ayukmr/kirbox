#include "color.h"
#include "guess.h"
#include "completion.h"

using color::ColorHandler;
using guess::GuessHandler;
using completion::CompletionHandler;

ColorHandler      colorHandler;
GuessHandler      guessHandler;
CompletionHandler completionHandler;

void setup() {
    colorHandler.setup();
    guessHandler.setup();
    completionHandler.setup();
}

void loop() {
    if (completionHandler.getTriggered()) {
        return;
    }

    colorHandler.update();
    guessHandler.update();

    if (colorHandler.getCompleted() && guessHandler.getCompleted()) {
        completionHandler.trigger();
    }
}
