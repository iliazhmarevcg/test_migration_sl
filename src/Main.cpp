#include "TerminalManager.h"
#include "AnimationOptions.h"
#include "TrainRenderer.h"
#include <iostream>
#include <csignal>
#include <unistd.h>

bool running = true;

void signalHandler(int signum) {
    running = false;
}

int main(int argc, char* argv[]) {
    signal(SIGINT, signalHandler);

    TerminalManager terminalManager;
    AnimationOptions animationOptions(argc, argv);
    TrainRenderer trainRenderer(animationOptions);

    terminalManager.initialize();

    while (running) {
        trainRenderer.render();
        terminalManager.refresh();
        usleep(100000); // Sleep for 100 milliseconds
    }

    terminalManager.cleanup();
    return 0;
}