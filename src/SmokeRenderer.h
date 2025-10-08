package src;

#ifndef SMOKERENDERER_H
#define SMOKERENDERER_H

class SmokeRenderer {
public:
    SmokeRenderer();
    ~SmokeRenderer();

    void initialize();
    void render();
    void update(float deltaTime);
    void cleanup();
};

#endif // SMOKERENDERER_H