#include "Welcome.h"
#include "SelectChapter.h"
#include "PKModeMainScene.h"

USING_NS_CC;

Scene *Welcome::createScene()
{ 
    auto scene = Scene::create();
    auto layer = Welcome::create();
    scene -> addChild(layer);

    return scene;
}

bool Welcome::init()
{
    if (!Layer::init())
    {
        return false; 
    }
    //获得窗口大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //背景
    auto backgroundSprite = Sprite::create("welcomBackgroud.png");
    if (backgroundSprite == NULL)
    {
        log("backgroudSprite is not create.");
        return false;
    }

    //设置背景精灵的位置
    backgroundSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    //配置菜单选项的属性
    auto startItem = MenuItemImage::create(
        "startNormal.png", "startSelected.png", 
        CC_CALLBACK_1(Welcome::menuStartCallBack, this));
    auto settingItem = MenuItemImage::create(
           "settingNormal.png", "settingSelected.png", 
           CC_CALLBACK_1(Welcome::menuSettingCallBack, this));
    auto exitItem = MenuItemImage::create(
           "exitNormal.png", "exitSelected.png", 
           CC_CALLBACK_1(Welcome::menuExitCallBack, this));
    auto PKModeItem = MenuItemImage::create(
           "PKMode/PKModeNormal.png", "PKMode/PKModeSelected.png", 
           CC_CALLBACK_1(Welcome::menuPKModeCallBack, this));
    //设置各个菜单选项的位置
    startItem->setPosition(
            Vec2(origin.x + visibleSize.width/2 - startItem->getContentSize().width/2 + 40,
                origin.y + visibleSize.height/2 ));
    PKModeItem->setPosition(
            Vec2(origin.x + visibleSize.width/2 - startItem->getContentSize().width/2 + 40,
                origin.y + visibleSize.height/2 - 60));
    settingItem->setPosition(
            Vec2(origin.x + visibleSize.width/2 - startItem->getContentSize().width/2 + 40,
                origin.y + visibleSize.height/2 - 120));
    exitItem->setPosition(
            Vec2(origin.x + visibleSize.width/2 - startItem->getContentSize().width/2 + 40,
                origin.y + visibleSize.height/2 - 180));

    //创建菜单
    auto startMenu = Menu::create(startItem, NULL);
    auto PKModeMenu = Menu::create(PKModeItem, NULL);
    auto settingMenu = Menu::create(settingItem, NULL);
    auto exitMenu = Menu::create(exitItem, NULL);


    //设置菜单位置
    startMenu->setPosition(Vec2::ZERO);
    PKModeMenu->setPosition(Vec2::ZERO);
    settingMenu->setPosition(Vec2::ZERO);
    exitMenu->setPosition(Vec2::ZERO);

    //将创建好的背景精灵添加到welcome场景中
    this->addChild(backgroundSprite);

    //将创建好的菜单添加到welcome场景中
    this->addChild(startMenu);
    this->addChild(PKModeMenu);
    this->addChild(settingMenu);
    this->addChild(exitMenu);



    
    return true;
}

void Welcome::menuStartCallBack(cocos2d::Ref* pSender)
{
    //特效切换场景
    Director::getInstance()->replaceScene(
            TransitionFadeTR::create(1, SelectChapter::createScene()));
    
}

void Welcome::menuSettingCallBack(cocos2d::Ref* pSender)
{
    printf("setting\n");
}

void Welcome::menuExitCallBack(cocos2d::Ref* pSender)
{
    //程序执行结束，释放运行场景
    Director::getInstance()->end();
}

void Welcome::menuPKModeCallBack(cocos2d::Ref* pSender)
{
    auto PKMode =  PKModeMainScene::createScene();
    if (PKMode == NULL)
    {
        log("PKModeMainScene is not created.\n");
        exit(1);
    }
    Director::getInstance()->replaceScene(TransitionFadeTR::create(1, PKMode));
}
