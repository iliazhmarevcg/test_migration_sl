#include "TerminalManager.h"
#include <ncurses.h>

TerminalManager::TerminalManager() {
    initscr();
    cbreak();
    noecho();
}

TerminalManager::~TerminalManager() {
    endwin();
}

void TerminalManager::disableLineBuffering() {
    cbreak();
}

void TerminalManager::disableEchoing() {
    noecho();
}