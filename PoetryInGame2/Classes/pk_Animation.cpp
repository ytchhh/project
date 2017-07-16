//
//  PkScene.cpp
//  PoetryInGame
//
//  Created by LHG on 3/25/17.
//
//

#include "pk_Animation.h"

pk_Animation::pk_Animation(void)
{}
pk_Animation::~pk_Animation(void)
{}

CCScene* pk_Animation::scene()
{
    CCScene *scene = NULL;
    do
    {
        scene = cocos2d::CCScene::create();
        CC_BREAK_IF(! scene);
        
        pk_Animation *layer = pk_Animation::create();
        CC_BREAK_IF(! scene);
        
        scene->addChild(layer);
    }while(0);
    return scene;
}

bool pk_Animation::init()
{
    bool bRet = false;
    do
    {CCSprite* bgSprite=CCSprite::create("4.jpg");
        bgSprite->setAnchorPoint(ccp(0,0));
        bgSprite->setPosition(ccp(0,0));
        
        addChild(bgSprite);
        
         CCSize size = CCDirector::sharedDirector()->getWinSize();
//        CCSprite* bgSprite2=CCSprite::create("pkScene.png");
        //bgSprite->setAnchorPoint(ccp(0,0));
  //      bgSprite2->setPosition(ccp(size.width / 2, size.height/2));
//        addChild(bgSprite2);
  /*     

	CCSprite* hero=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(heronormalkey));
	hero->setScaleY(2.0);
	hero->setScaleY(2.0);
	hero->setAnchorPoint(ccp(0,0));
	hero->setPosition(ccp(size.width/2-200,size.height/2+20));
	addChild(hero);
	
	CCSprite* boss=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(bosskey));
	boss->setPosition(ccp(size.width/2+50,size.height/2+20));
	boss->setAnchorPoint(ccp(0,0));
	addChild(boss);
*/

        //  float a=(float)480/800;
        // float b=(float)320/480;
        //  bgSprite2->setScaleX((float)480/800);
        //  bgSprite2->setScaleY((float)320/480);
        //bgSprite2->setScaleX(0.9f);
        //  bgSprite2->setScaleY(0.9f);
        
        
        
        
        
        
       
        CCMenuItemImage *musicItem = CCMenuItemImage::create(
                                                             "Thumb_back.png",
                                                             "Thumb_back_pressed.png",
                                                             this,
                                                             menu_selector(pk_Animation::PkSceneCallback));
        musicItem->setPosition(ccp(size.width/2, size.height/2));
        CCMenu* pMenu = CCMenu::create(musicItem, NULL);
        pMenu->setPosition(size.width/2-50, 200);
        addChild(pMenu);
	playPkAnimation();
	
//	ShowGameResult();


        bRet=true;
        
    }while(0);
    return bRet;

}

void pk_Animation::playPkAnimation()
{
         CCSize size = CCDirector::sharedDirector()->getWinSize();
//   CCSprite* pk_background=CCSprite::create("4.jpg");
//   pk_background->setAnchorPoint(ccp(0,0));
//   pk_background->setPosition(ccp(size.width/4,size.height/4));
//   addChild(pk_background,1);

   CCFadeIn* fadein1=CCFadeIn::create(0.3f);
   CCFadeIn* fadein2=CCFadeIn::create(0.1f);


   CCSpriteFrame *frame1= CCSpriteFrame::create("1.png",CCRectMake(0,0,800,800));
   CCSpriteFrame* frame2=CCSpriteFrame::create("2.png",CCRectMake(0,0,800,800));
   CCSpriteFrame *frame3= CCSpriteFrame::create("3.png",CCRectMake(0,0,800,800));
   CCSpriteFrame* frame4=CCSpriteFrame::create("4.png",CCRectMake(0,0,800,800));
   CCSpriteFrame *frame5= CCSpriteFrame::create("5.png",CCRectMake(0,0,800,800));
   CCSpriteFrame* frame6=CCSpriteFrame::create("6.png",CCRectMake(0,0,800,800));
   CCSpriteFrame *frame7= CCSpriteFrame::create("7.png",CCRectMake(0,0,800,800));
   CCSpriteFrame* frame8=CCSpriteFrame::create("8.png",CCRectMake(0,0,800,800));
	CCArray* array=CCArray::createWithCapacity(8);
	array->addObject(frame1);
	array->addObject(frame2);
	array->addObject(frame3);
	array->addObject(frame4);
	array->addObject(frame5);
	array->addObject(frame6);
	array->addObject(frame7);
	array->addObject(frame8);

	CCSprite* sprite= CCSprite::createWithSpriteFrame(frame1);
	sprite->setPosition(ccp(size.width/2,size.height/2));
	addChild(sprite);

	CCAnimation*  animation=CCAnimation::createWithSpriteFrames(array,0.5f);
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(pk_Animation::ShowGameResult));
	sprite->runAction(CCSequence::create(CCSpawn::createWithTwoActions(fadein1,CCAnimate::create(animation)),CCAnimate::create(animation),actionMoveDone,NULL));/*CCSequence::create(CCSpawn::createWithTwoActions(fadein1,CCAnimate::create(animation))),NULL);*/
//	CC_BREAK_IF(!CCLayer::init());
/*
	CCMenuItemImage* back1=CCMenuItemImage::create("Thumb_back.png","Thumb_back_pressed.png",this,menu_selector(PkScene::pkCallback));
//	CC_BREAK_IF(!back1);
	back1->setPosition(ccp(size.width/2-50,100));
	CCMenu* pkMenu=CCMenu::create(back1,NULL);
	pkMenu->setPosition(CCPointZero);
//	CC_BREAK_IF(!pkMenu);
	this->addChild(pkMenu,1);
*/
}

void pk_Animation::ShowGameResult(CCObject* pSender)
{
         CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCLabelTTF* result=CCLabelTTF::create("Hero  is  Win!!","Arial",30);
	result->setColor(ccc3(1,1,1));
	result->setPosition(ccp(size.width/2,size.height/2-100));
	result->setTag(10);
	this->addChild(result);
}


void pk_Animation::PkSceneCallback(CCObject*  pSender)
{
	CCDirector::sharedDirector()->popScene();
}
void  pk_Animation::animateFinished(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}
