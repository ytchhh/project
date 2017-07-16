#include "PKModeMainScene.h"
#include "Welcome.h"

USING_NS_CC;

Scene *PKModeMainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PKModeMainScene::create();
    scene->addChild(layer);

    return scene;
}

bool PKModeMainScene::init()
{
    if (!Layer::init())
    {
        return false; 
    }

    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bgSprite = Sprite::create("PKMode/bg.png");
    bgSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    auto backMainMenuItem = MenuItemImage::create(
            "PKMode/backMainMenuNormal.png", "PKMode/backMainMenuSelected.png",
            CC_CALLBACK_1(PKModeMainScene::backMainMenuCallBack, this));
    auto backMainMenu = Menu::create(backMainMenuItem, NULL);
    backMainMenu->setPosition(450, 30);

    auto ensurePKItem = MenuItemImage::create(
            "PKMode/ensurePKNormal.png", "PKMode/ensurePKSelected.png",
            CC_CALLBACK_1(PKModeMainScene::ensurePKMenuCallBack, this));
    auto ensurePKMenu = Menu::create(ensurePKItem, NULL);
    ensurePKMenu->setPosition(850, 30);

    this->addChild(bgSprite);
    this->addChild(ensurePKMenu);
    this->addChild(backMainMenu);
    return true;
}

void PKModeMainScene::ensurePKMenuCallBack(cocos2d::Ref* pSender)
{
    log("ensure pk");
}

void PKModeMainScene::backMainMenuCallBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(
            TransitionFlipX::create(1, Welcome::createScene()));
}
