//
// Created by bit_chef on 11/5/15.
//

#ifndef MYGAME_PHYSICSWORLDSCENE_H
#define MYGAME_PHYSICSWORLDSCENE_H

#include "cocos2d.h"

class PhysicsWorldScene : public cocos2d::Layer  {

public:
    static cocos2d::Scene* createScene();
    CREATE_FUNC(PhysicsWorldScene);
    virtual bool init() override;
private:
    cocos2d::Director* _director;
    cocos2d::Size _visibleSize;
};


#endif //MYGAME_PHYSICSWORLDSCENE_H
