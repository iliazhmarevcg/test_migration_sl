#include "AnimationOptions.h"
#include <cstring>

AnimationOptions::AnimationOptions() : enableAnimation(false), animationSpeed(1.0) {}

void AnimationOptions::processArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--enable-animation") == 0) {
            enableAnimation = true;
        } else if (strcmp(argv[i], "--animation-speed") == 0 && i + 1 < argc) {
            animationSpeed = std::stod(argv[++i]);
        }
    }
}