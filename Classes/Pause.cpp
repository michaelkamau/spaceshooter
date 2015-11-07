//
// Created by bit_chef on 11/4/15.
//

#include "Pause.h"

std::string Pause::getDescription() const {
    return Layer::getDescription();
}

bool Pause::init() {
    return Layer::init();
}

cocos2d::Scene *Pause::createScene() {
    return nullptr;
}
