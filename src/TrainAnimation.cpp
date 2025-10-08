#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <cstring>
#include <cstdlib>

class TrainAnimation {
public:
    void initializeTerminalScreen();
    void processCommandLineArguments(int argc, char* argv[]);
    void renderAnimation();
    void endTerminalSession();

private:
    void renderLogoTrain();
    void renderD51Train();
    void renderC51Train();
    void renderMan();
    void renderSmoke();
    void captureUserInput();

    struct termios originalTermios;
    bool showLogoTrain = false;
    bool showD51Train = false;
    bool showC51Train = false;
    bool showMan = false;
    int x = 0;
};

void TrainAnimation::initializeTerminalScreen() {
    tcgetattr(STDIN_FILENO, &originalTermios);
    struct termios newTermios = originalTermios;
    newTermios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
}

void TrainAnimation::processCommandLineArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0) {
            showLogoTrain = true;
        } else if (strcmp(argv[i], "-F") == 0) {
            showD51Train = true;
        } else if (strcmp(argv[i], "-l") == 0) {
            showC51Train = true;
        } else if (strcmp(argv[i], "-c") == 0) {
            showMan = true;
        }
    }
}

void TrainAnimation::renderAnimation() {
    while (true) {
        x--;
        std::cout << "\033[2J\033[H"; // Clear screen and move cursor to home position
        if (showLogoTrain) renderLogoTrain();
        if (showD51Train) renderD51Train();
        if (showC51Train) renderC51Train();
        if (showMan) renderMan();
        renderSmoke();
        captureUserInput();
        usleep(100000); // Pause for 100 milliseconds
    }
}

void TrainAnimation::endTerminalSession() {
    tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
}

void TrainAnimation::renderLogoTrain() {
    std::cout << "Logo Train at position " << x << std::endl;
}

void TrainAnimation::renderD51Train() {
    std::cout << "D51 Train at position " << x << std::endl;
}

void TrainAnimation::renderC51Train() {
    std::cout << "C51 Train at position " << x << std::endl;
}

void TrainAnimation::renderMan() {
    std::cout << "Man at position " << x << std::endl;
}

void TrainAnimation::renderSmoke() {
    std::cout << "Smoke at position " << x << std::endl;
}

void TrainAnimation::captureUserInput() {
    if (std::cin.peek() != EOF) {
        char c = std::cin.get();
        if (c == 'q') {
            endTerminalSession();
            exit(0);
        }
    }
}