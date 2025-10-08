package src;

#ifndef TERMINALMANAGER_H
#define TERMINALMANAGER_H

class TerminalManager {
public:
    void initializeTerminal();
    void endTerminalSession();
    void disableLineBuffering();
    void disableEchoing();
};

#endif // TERMINALMANAGER_H