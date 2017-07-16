#include "ControlLayer.h"

CCSprite *leftSprite;
CCSprite *rightSprite;
CCSprite *jumpSprite;
bool leftSpriteTouched;
bool rightSpriteTouched;
bool jumpSpriteTouched;
CCSize size;
CCMenuItemImage *backItem;
ControlLayer::ControlLayer(void)
{
	sGlobal->controlLayer;
}


ControlLayer::~ControlLayer(void)
{
}
bool ControlLayer::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
    char *poetry[20] = {"锄", "禾", "日", "当", "午", "汗", "滴", "禾", "下", "土", "谁", "知", "盘", "中", "餐", "粒", "粒", "皆", "辛", "苦"};
	winLayerInitTimes=0;
	failedLayerInitTimes=0;
    
	leftSpriteTouched=false;
	rightSpriteTouched=false;
	jumpSpriteTouched=false;
    
	this->setTouchEnabled(true);
    
	size=CCDirector::sharedDirector()->getWinSize();
    
	leftSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(controlLeftkey));
	leftSprite->setPosition(ccp(45,45));
	this->addChild(leftSprite);
	rightSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(controlRightkey));
	rightSprite->setPosition(ccp(45+90+20,45));
	this->addChild(rightSprite);
	jumpSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(controlJumpkey));
	jumpSprite->setPosition(ccp(size.width-70,45));
	addChild(jumpSprite);
    backItem = CCMenuItemImage::create(
                                       "Thumb_back.png",
                                       "Thumb_back_pressed.png",
                                       this,
                                       menu_selector(ControlLayer::backItemCallback));
    
    // Place the menu item bottom-right conner.
    backItem ->setPosition(ccp(36,size.height-36));
    //this->addChild(skipItem);
    CCMenu* backItemMenu = CCMenu::create(backItem , NULL);
    backItemMenu->setPosition(CCPointZero);
    addChild(backItemMenu,2);
    
//Label
	//CCDictionary* strings=CCDictionary::createWithContentsOfFile("Poetry.xml");
	//const char *info=((CCString*)strings->objectForKey("Info"))->m_sString.c_str();
	CCLabelTTF *ttf=CCLabelTTF::create("悯农","Arial",18);
	ttf->setPosition(ccp(size.width-100,size.height-10));
    ttf->setColor(ccc3(1,1,1));
    ttf->setVisible(true);
	this->addChild(ttf);
for(int j=1;j<5;++j)
{
	for(int i=1;i<=5;++i)
	{
		CCLabelTTF* label=CCLabelTTF::create(poetry[(j-1)*5+(i-1)],"Arial",15);
		label->setPosition(ccp(size.width-170+i*30,size.height-30*j));
		label->setColor(ccc3(1,1,1)); 
		label->setTag((j-1)*5+(i-1));
		label->setVisible(false);
		this->addChild(label);
	}
}


///////////////////


    this->scheduleUpdate();
	
	return true;
}


void  ControlLayer::ccTouchesBegan (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
  CCPoint	location=touch->getLocationInView();
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);
	//◊Û∞¥≈•
	if (location.x<90&&location.y<90)
	{
		leftSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlLeftPressedkey));
		leftSpriteTouched=true;
	}else if (location.x>90&&location.x<180&&location.y<90)//”“∞¥≈•
	{
		rightSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlRightPressedkey));
		rightSpriteTouched=true;
	}
	if (location.x>size.width-140&&location.y<90)//Ã¯
	{
		jumpSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlJumpPressedkey));
		jumpSpriteTouched=true;
	}

}
void  ControlLayer::ccTouchesEnded (cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
	CCPoint	location=touch->getLocationInView();
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);
	if (location.x<90&&location.y<90)
	{
		leftSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlLeftkey));
		leftSpriteTouched=false;
	}else if (location.x>90&&location.x<180&&location.y<90)
	{
		rightSpriteTouched=false;
		rightSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlRightkey));
	}
	if (location.x>size.width-140&&location.y<90)
	{
		jumpSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlJumpkey));
		jumpSpriteTouched=false;
	}
	
	
	
}
void ControlLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch *touch=(CCTouch *)pTouches->anyObject();
	CCPoint	location=touch->getLocationInView();
	// touch==NULL;
	location=CCDirector::sharedDirector()->convertToGL(location);
	if (!(location.x<90&&location.y<90))
	{
		if (location.x<size.width/2)
		{
		
		leftSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlLeftkey));
		leftSpriteTouched=false;
		}
	}
	if (!(location.x>110&&location.x<200&&location.y<90))
	{
		if (location.x<size.width/2)
		{
		rightSpriteTouched=false;
		rightSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlRightkey));
		}
	}
	if (!(location.x>(size.width-135)&&location.y<90))
	{
		if (location.x>size.width/2)
		{
			jumpSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(controlJumpkey));
			jumpSpriteTouched=false;
		}
	}

}

void ControlLayer::backItemCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->popScene();
}
void ControlLayer::update(float dt)
{
    int myWordId = sGlobal->globalData->getWordId();
    if (myWordId < 20 && myWordId >= 0)
    {
        getChildByTag(myWordId) -> setVisible(true);
    }
	
	if (sGlobal->hero->isDead)
	{
		this->setTouchEnabled(false);
	}
	if (sGlobal->hero->isDead&&failedLayerInitTimes==0)
	{

	   CCLayer *failedLayer=FailedLayer::create();
	   sGlobal->game_1_1->addChild(failedLayer,2);
	//	CCLayer *victoryLayer=VictoryLayer::create();
	//	sGlobal->game_1_1->addChild(victoryLayer);
		failedLayerInitTimes=1;
		if (sGlobal->isEffectOn)
		{
		
//		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_boos.mp3",false);
		}
	}
	if(sGlobal->hero->isWin&&winLayerInitTimes==0)
	{
		CCLayer *victoryLayer=VictoryLayer::create();
			sGlobal->game_1_1->addChild(victoryLayer);
		winLayerInitTimes=1;
		if (sGlobal->isEffectOn)
		{

//			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_congratulations.mp3",false);
		}
	}
	int hspeed=0;
	if (leftSpriteTouched)
	{
		hspeed=-3;
	}else if (rightSpriteTouched)
	{
		hspeed=3;
	}else{
		hspeed=0;
	}
	
	sGlobal->hero->move(hspeed);
	if (jumpSpriteTouched&&sGlobal->hero->isDead==false)
	{
		if (sGlobal->hero->isJumpDone)
		{
			if (sGlobal->isEffectOn)
			{
			
//			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_jump.mp3",false);
			}
			sGlobal->hero->isJumpDone=false;
			sGlobal->hero->vspeed=11;
		}

	}
  sGlobal->hero->jump();
  int x=0-sGlobal->game_1_1->getPositionX();
   int y=0-sGlobal->game_1_1->getPositionY();
  this->setPosition(ccp(x,y));
}
