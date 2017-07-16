//
//  PkScene.cpp
//  PoetryInGame
//
//  Created by LHG on 3/25/17.
//
//
#include"./pk_Animation.h"
#include"PkScene.h"
PkScene::PkScene(void)
{}
PkScene::~PkScene(void)
{}

CCScene* PkScene::scene()
{
    CCScene *scene = NULL;
    do
    {
        scene = cocos2d::CCScene::create();
        CC_BREAK_IF(! scene);
        
        PkScene *layer = PkScene::create();
        CC_BREAK_IF(! scene);
        
        scene->addChild(layer);
    }while(0);
    return scene;
}

bool PkScene::init()
{
    bool bRet = false;
    do
    {CCSprite* bgSprite=CCSprite::create("bg_pkScene.png");
        bgSprite->setAnchorPoint(ccp(0,0));
        bgSprite->setPosition(ccp(0,0));
        
        addChild(bgSprite);
        
         CCSize size = CCDirector::sharedDirector()->getWinSize();
       CCSprite* bgSprite2=CCSprite::create("pkScene.png");
      bgSprite2->setPosition(ccp(size.width / 2, size.height/2));
       addChild(bgSprite2);
       

	CCSprite* hero=CCSprite::create("Panda15.png");
	hero->setAnchorPoint(ccp(0,0));
	hero->setPosition(ccp(size.width/2-200,size.height/2));
	addChild(hero);
	
	CCSprite* boss=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(bosskey));
	boss->setPosition(ccp(size.width/2+50,size.height/2));
	boss->setAnchorPoint(ccp(0,0));
	addChild(boss);


	CCLabelTTF *hScore=CCLabelTTF::create("Hero Score: 18 ","Arial",24);
	hScore->setPosition(ccp(size.width/2-150,size.height/2-100));
	hScore->setColor(ccc3(1,1,1));
	hScore->setTag(22);
	this->addChild(hScore);
        
	CCLabelTTF *bScore=CCLabelTTF::create("Boss Score: 18 ","Arial",24);
	bScore->setPosition(ccp(size.width/2+100,size.height/2-100));
	bScore->setColor(ccc3(1,1,1));
	bScore->setTag(23);
	this->addChild(bScore);
        CCMenuItemImage *musicItem = CCMenuItemImage::create(
                                                             "StageSelect_tinyblock_pressed.png",
                                                             "StageSelect_tinyblock_locked.png",
                                                             this,
                                                             menu_selector(PkScene::pkCallback));
        musicItem->setPosition(ccp(size.width/2, size.height/2));
        CCMenu* pMenu = CCMenu::create(musicItem, NULL);
        pMenu->setPosition(CCPointZero);
        addChild(pMenu);


        CCMenuItemImage *back2Item = CCMenuItemImage::create(
                                                             "Thumb_back.png",
                                                             "Thumb_back__pressed.png",
                                                             this,
                                                             menu_selector(PkScene::MenuCallback));
        back2Item->setPosition(ccp(size.width/2, size.height/2-50));
        CCMenu* pMenu2 = CCMenu::create(back2Item, NULL);
        pMenu2->setPosition(size.width/2-50, 150);
        addChild(pMenu2);
        bRet=true;
        
    }while(0);
      return bRet;
  

}
void PkScene::MenuCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}
void PkScene::pkCallback(CCObject*  pSender)
{
	CCScene* pk_animation=pk_Animation::scene();
	CCDirector::sharedDirector()->pushScene((CCTransitionSlideInR::create(0.1f,pk_animation)));
	


}
/*
void PkScene::ensurePkItemCallback(CCObject* pSender)
{
         CCSize size = CCDirector::sharedDirector()->getWinSize();
   CCSprite* pk_background=CCSprite::create("4.jpg");
   pk_background->setAnchorPoint(ccp(0,0));
   pk_background->setPosition(ccp(size.width/4,size.height/4));
   addChild(pk_background,1);

   CCFadeIn* fadein1=CCFadeIn::create(1.0f);
   CCFadeIn* fadein2=CCFadeIn::create(0.1f);

   CCSpriteFrame *frame1= CCSpriteFrame::create("1.png",CCRectMake(0,0,400,400));
   CCSpriteFrame* frame2=CCSpriteFrame::create("2.png",CCRectMake(0,0,400,400));
   CCSpriteFrame *frame3= CCSpriteFrame::create("3.png",CCRectMake(0,0,400,400));
   CCSpriteFrame* frame4=CCSpriteFrame::create("4.png",CCRectMake(0,0,400,400));
   CCSpriteFrame *frame5= CCSpriteFrame::create("5.png",CCRectMake(0,0,400,400));
   CCSpriteFrame* frame6=CCSpriteFrame::create("6.png",CCRectMake(0,0,400,400));
   CCSpriteFrame *frame7= CCSpriteFrame::create("7.png",CCRectMake(0,0,400,400));
   CCSpriteFrame* frame8=CCSpriteFrame::create("8.png",CCRectMake(0,0,400,400));
	CCArray* array=CCArray::createWithCapacity(8);
	array->addObject(frame1);
	array->addObject(frame2);
	array->addObject(frame3);
	array->addObject(frame4);
	array->addObject(frame5);
	array->addObject(frame6);
	array->addObject(frame7);
	array->addObject(frame8);

	CCAnimation*  animation=CCAnimation::createWithSpriteFrames(array,1.0f);
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(PkScene::animateFinished));
	pk_background->runAction(CCSequence::create(CCSpawn::createWithTwoActions(fadein1,CCAnimate::create(animation)),actionMoveDone,NULL));
//	CC_BREAK_IF(!CCLayer::init());
	CCMenuItemImage* back1=CCMenuItemImage::create("Thumb_back.png","Thumb_back_pressed.png",this,menu_selector(PkScene::pkCallback));
//	CC_BREAK_IF(!back1);
	back1->setPosition(ccp(size.width/2-50,100));
	CCMenu* pkMenu=CCMenu::create(back1,NULL);
	pkMenu->setPosition(CCPointZero);
//	CC_BREAK_IF(!pkMenu);
	this->addChild(pkMenu,1);

}
}
void  PkScene::animateFinished(CCObject* pSender)
{
	//
}

*/
