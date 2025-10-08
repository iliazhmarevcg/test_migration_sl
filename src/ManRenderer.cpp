#include "ManRenderer.h"

void ManRenderer::renderManAnimation(const Train& train, bool accidentFlag) {
    if (accidentFlag) {
        renderAccidentAnimation(train.getPosition());
    } else {
        renderNormalAnimation(train.getPosition());
    }
}

void ManRenderer::renderAccidentAnimation(const Position& position) {
    // Implementation for rendering accident animation based on position
}

void ManRenderer::renderNormalAnimation(const Position& position) {
    // Implementation for rendering normal animation based on position
}