#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "PhysicsWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add a button the open the PhysicsWorld scene
    auto btnOpenPhysicsWorld = ui::Button::create("PNG/playerShip1_blue.png");
    btnOpenPhysicsWorld->setTitleText("Enter Physics World!");
    btnOpenPhysicsWorld->setTitleFontSize(30);
    btnOpenPhysicsWorld->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.75));

    // add event listener
    btnOpenPhysicsWorld->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType type){
        switch (type){
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                // TODO: transition to the PhysicsWorldScene with a transition effect.
                Director::getInstance()->pushScene(TransitionSlideInR::create(1,PhysicsWorldScene::createScene()));
                break;
            default:
                break;
        }
    });

    this->addChild(btnOpenPhysicsWorld);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("To be or not to be that is the question.", "fonts/Marker Felt.ttf", 20);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label);

    // add "Background" splash screen"
    auto background = Sprite::create("Backgrounds/blue.png");
    background->setAnchorPoint(Vec2::ZERO);

    // scale to fit the screen
    background->setScale(visibleSize.width/background->getContentSize().width,
                         visibleSize.height/background->getContentSize().height);

    // add the sprite as a child to this layer
    this->addChild(background, -1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
