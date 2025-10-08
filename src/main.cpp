#include "TrainAnimation.h"

int main(int argc, char* argv[]) {
    TrainAnimation trainAnimation;
    trainAnimation.initializeTerminalScreen();
    trainAnimation.processCommandLineArguments(argc, argv);
    trainAnimation.renderAnimation();
    trainAnimation.endTerminalSession();
    return 0;
}