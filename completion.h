namespace completion {

class CompletionHandler {
private:
    bool triggered;

public:
    CompletionHandler();

    void setup();
    void trigger();
    bool getTriggered();
};

}
