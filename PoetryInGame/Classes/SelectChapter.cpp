#include "SelectChapter.h"
#include"MainGame.h"
USING_NS_CC;

Scene *SelectChapter::createScene()
{
    auto scene = Scene::create();
    auto layer = SelectChapter::create();
    scene->addChild(layer);
    return scene;
}

bool SelectChapter::init()
{
    if (!Layer::init())
    {
        return false; 
    }
    //获得窗口大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //背景
    auto backgroundSprite = Sprite::create("selectChapter.png");

    //设置背景精灵的位置
    backgroundSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    //返回按钮
    //配置菜单选项的属性
    auto backMenuItem = MenuItemImage::create(
        "backMenuNormal.png", "backMenuSelected.png", 
        CC_CALLBACK_1(SelectChapter::backMenuCallBack, this));
    backMenuItem->setPosition(Vec2(30, 20));
    
    //返回按钮
    auto backMenu = Menu::create(backMenuItem, NULL);
    backMenu->setPosition(Vec2(30, 20));

    ////////////关卡设置
    auto MainGameMenuItem = MenuItemImage::create(
            "chapter1MenuNormal.png", "chapter1MenuSelected.png", 
            CC_CALLBACK_1(SelectChapter::MainGameMenuCallBack, this));
    if (MainGameMenuItem == NULL)
        exit(0);
    //chapter1MenuItem->setPosition(Vec2(origin.x + visibleSize.width/2,
    //            origin.y + visibleSize.height/2));
    auto MainGameMenu = Menu::create(MainGameMenuItem, NULL); 
    if (MainGameMenu == NULL)
        exit(0);
    MainGameMenu->setPosition(Vec2(60,
                origin.y + visibleSize.height - 200));


    //添加背景精灵
    this->addChild(backgroundSprite);
    this->addChild(MainGameMenu);
    this->addChild(backMenu);

    return true;
}

void SelectChapter::backMenuCallBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(
            TransitionFadeBL::create(1, Welcome::createScene()));
}

void SelectChapter::MainGameMenuCallBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(
            TransitionFlipX::create(1, MainGame::createScene()));
}
