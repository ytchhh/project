#include "ControlLayer.h"
#include"Hero.h"
#include"Global.h"
#include"Gbase.h"
USING_NS_CC;
ControlLayer::ControlLayer()
{
	SGlobal->controlLayer=this;

}
ControlLayer::~ControlLayer(){}
bool ControlLayer::init()
{
    if (!Layer::init())
    {
        return false; 
    }

    //setTouchEnabled(true);
    //setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

    //get the size of window
	isTouched=false;
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    _screenWidth = visibleSize.width;
    _screenHeight = visibleSize.height;



    auto playerLeft = Sprite::create("player_control/playerLeftNormal.png"); 
    playerLeft->setPosition(Vec2(100, 80));
    this->addChild(playerLeft, 10, 100);

    auto playerRight = Sprite::create( "player_control/playerRightNormal.png");
    playerRight->setPosition(Vec2(200, 80));
    this->addChild(playerRight, 10, 101);

    //menuLeft->setAnchorPoint(Vec2::ZERO);

    auto playerJump = Sprite::create( "player_control/playerJumpNormal.png");
    playerJump->setPosition(Vec2(300, 80));
    this->addChild(playerJump, 10, 102);

    auto playerShoot = Sprite::create( "player_control/playerShootNormal.png");
    playerShoot->setPosition(Vec2(400, 80));
    this->addChild(playerShoot, 10, 103);

    auto menuGamePause = Menu::create();
    auto gamePause = MenuItemImage::create(
            "gamePauseNormal.png", "gamePauseSelected.png", 
            CC_CALLBACK_1(ControlLayer::gamePauseMenuCallBack, this));
    menuGamePause->addChild(gamePause);
    menuGamePause->setPosition(Vec2(450,80));
    this->addChild(menuGamePause);

    //menuRight->setAnchorPoint(Vec2(_screenWidth, 0));


this->scheduleUpdate();
log("update   s s  s ");
    return true;
}

void ControlLayer::onEnter()
{
    Layer::onEnter();
    log("ControlLayer onEnter");
    auto listener = EventListenerTouchOneByOne::create();

    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(ControlLayer::touchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(ControlLayer::touchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(ControlLayer::touchEnded, this);

    EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener,
            getChildByTag(101));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), 
            getChildByTag(100));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(),
            getChildByTag(102));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(),
            getChildByTag(103));

}
void ControlLayer::onExit()
{
    Layer::onExit();
    log("ControlLayer onExit");
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}


void ControlLayer::gamePauseMenuCallBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(
           TransitionFlipY::create(1, SelectChapter::createScene())); 
}

bool ControlLayer::touchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    log("onTouchBegan ControlLayer");
    auto target = static_cast<Sprite *>(event->getCurrentTarget());
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
    Rect rect = Rect(0, 0, s.width, s.height);

    if (rect.containsPoint(locationInNode))
    {
		isTouched = true;
        log("sprite x = %f, y = %f", locationInNode.x, locationInNode.y); 
        log("sprite tag = %d", target->getTag());
        switch(target->getTag())
        {
            case 100:
              //  SGlobal->hero->move(-1);
			//	isLeft=true;
				act_type=1;			
                    break;
            case 101:
            //     SGlobal->hero->move(1);
			//	 isLeft=false;
			act_type = 2;
                break;
            case 102:
        //        SGlobal->hero->jump();
	//			log("Jump had finished.");
	act_type=3;
                break;
            case 103:
			//	SGlobal->hero->shoot(isLeft);
              //  log("shooted finished");
			  act_type=4;
                break;
        }
      //  return false;
    }
    return false;
}

void ControlLayer::touchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    log("onTouchMoved");
    
}

void ControlLayer::touchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    /*
    log("onTouchEnded");
    auto target = static_cast<Sprite *>(event->getCurrentTarget());
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
    Rect rect = Rect(0, 0, s.width, s.height);

    if (rect.containsPoint(locationInNode))
    {
        log("sprite x = %f, y = %f", locationInNode.x, locationInNode.y); 
        log("sprite tag = %d", target->getTag());

    }
    */
   

}
void  ControlLayer::update(float dt)
{
	log("update start");
	if(isTouched)
	{
		switch(act_type)
		{
			case 1:
			SGlobal->hero->move(-1);
			log("moveLeft..");
			break;
			case 2:
			SGlobal->hero->move(1);
			log("moveRight..");
			break;
			case 3:
			SGlobal->hero->jump();
			log("Jump..");
			break;
			case 4:
			SGlobal->hero->shoot(isLeft);
			log("shoot..");
			break;
		}
		isTouched=false;
	}
	log("update finished");
}
