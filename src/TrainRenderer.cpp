#include "TrainRenderer.h"
#include <ncurses.h>
#include <unistd.h>

TrainRenderer::TrainRenderer() : x(0), y(10), trainModel(0) {}

void TrainRenderer::setTrainModel(int model) {
    trainModel = model;
}

void TrainRenderer::renderTrain() {
    switch (trainModel) {
        case 0:
            mvprintw(y, x, "====TRAIN====");
            break;
        case 1:
            mvprintw(y, x, "====FAST TRAIN====");
            break;
        default:
            mvprintw(y, x, "====DEFAULT TRAIN====");
            break;
    }
}

void TrainRenderer::renderSmoke() {
    mvprintw(y - 1, x + 5, "( )");
    mvprintw(y - 2, x + 6, "( )");
}

void TrainRenderer::renderMan() {
    mvprintw(y + 1, x + 3, " O ");
    mvprintw(y + 2, x + 3, "/|\\");
    mvprintw(y + 3, x + 3, "/ \\");
}

void TrainRenderer::startAnimationLoop() {
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    while (true) {
        clear();
        renderTrain();
        renderSmoke();
        renderMan();
        refresh();

        x--;
        if (x < -20) x = COLS;

        usleep(100000);

        int ch = getch();
        if (ch == 'q' || ch == 'Q') break;
    }

    endwin();
}