//
// Created by bit_chef on 11/5/15.
//

#include "PhysicsWorldScene.h"

USING_NS_CC;

bool PhysicsWorldScene::init() {
    if (!Layer::init()) {
        return false;
    }

    _director = Director::getInstance();
    _visibleSize = _director->getVisibleSize();

    // set the background.
    auto background = Sprite::create("Backgrounds/purple.png");
    background->setAnchorPoint(Vec2::ZERO);
    background->setScale(_visibleSize.width / background->getContentSize().width,
                         _visibleSize.height / background->getContentSize().height);
    this->addChild(background, 0);

    // PhysicsBody for the UFO
    auto ufoPhysicsBody = PhysicsBody::createCircle(45.0f, PhysicsMaterial(1.0f, 1.0f, 0.5f));

    // Physics body for a meteor
    auto  meteorPhysicsBody = PhysicsBody::createBox(Size(101.0f,84.0f),PhysicsMaterial(0.5f,1.0f,0.5f),Vec2::ZERO);
    meteorPhysicsBody->setDynamic(false);

    // add UFO to test.
    auto ufoYellow = Sprite::create("PNG/ufoYellow.png");
    ufoYellow->setPosition(_visibleSize.width / 2, _visibleSize.height - ufoYellow->getContentSize().height);
    ufoYellow->setPhysicsBody(ufoPhysicsBody);

    // add meteor to on ground level below the Ufo
    auto meteor = Sprite::create("PNG/Meteors/meteorGrey_big1.png");
    meteor->setPosition(_visibleSize.width / 2, _visibleSize.height * 0.1);
    meteor->setPhysicsBody(meteorPhysicsBody);

    this->addChild(meteor);

//
    this->addChild(ufoYellow);
//
    return true;
}

Scene *PhysicsWorldScene::createScene() {
    auto scene = Scene::createWithPhysics();
    auto layer = PhysicsWorldScene::create();
    scene->addChild(layer);
    return scene;
}
