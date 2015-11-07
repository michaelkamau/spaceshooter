//
// Created by bit_chef on 11/4/15.
//

#ifndef MYGAME_PAUSE_H
#define MYGAME_PAUSE_H

#include "cocos2d.h"

class Pause : cocos2d::Layer{

    cocos2d::Scene*createScene();

    CREATE_FUNC(Pause);

    virtual std::string getDescription() const override;

    virtual bool init() override;
};


#endif //MYGAME_PAUSE_H
