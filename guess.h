namespace guess {

class GuessHandler {
private:
    int  buffer[10];
    int  count;
    bool completed;
    int  lastButton;

public:
    GuessHandler();

    void setup();
    void update();
    bool getCompleted();
};

}
