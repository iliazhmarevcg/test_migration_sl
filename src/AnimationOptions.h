#ifndef ANIMATIONOPTIONS_H
#define ANIMATIONOPTIONS_H

#include <string>
#include <vector>

class AnimationOptions {
public:
    bool ACCIDENT;
    bool FLY;
    bool LOGO;
    bool C51;

    AnimationOptions();
    void processArguments(const std::vector<std::string>& args);
};

#endif // ANIMATIONOPTIONS_H