package src;

#ifndef MANRENDERER_H
#define MANRENDERER_H

class ManRenderer {
public:
    ManRenderer();
    ~ManRenderer();

    void renderIdle();
    void renderWalking();
    void renderRunning();
    void renderJumping();
    void renderFalling();
};

#endif // MANRENDERER_H