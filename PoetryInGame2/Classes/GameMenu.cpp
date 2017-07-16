#include "GameMenu.h"


GameMenu::GameMenu(void)
{
}


GameMenu::~GameMenu(void)
{
}
CCScene* GameMenu::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		GameMenu *layer = GameMenu::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

 bool GameMenu::init()
 {
	 bool bRet = false;
	 do 
	 {
		  
		  CCSprite* bgSprite=CCSprite::create("backgrund-1-1.png");
		  bgSprite->setAnchorPoint(ccp(0,0));
		  bgSprite->setPosition(ccp(0,0));
		bgSprite->setScaleX(0.8);
		bgSprite->setScaleY(0.8);
		  addChild(bgSprite);

//		  CCSprite* bgSprite2=CCSprite::create("Startup_frame.png");
		  //bgSprite->setAnchorPoint(ccp(0,0));
//		  CCSize size = CCDirector::sharedDirector()->getWinSize();
//		  bgSprite2->setPosition(ccp(size.width / 2, size.height/2));
		//  float a=(float)480/800;
		// float b=(float)320/480;
		//  bgSprite2->setScaleX((float)480/800);
		//  bgSprite2->setScaleY((float)320/480);
		  //bgSprite2->setScaleX(0.9f);
		//  bgSprite2->setScaleY(0.9f);
//		  addChild(bgSprite2);
//		  CCSprite* title =CCSprite::create("Startup_lbl_title_zh.png");
//		  title->setPosition(ccp(size.width/2,size.height-135));
//		  addChild(title);
//		  CCSprite* photo_border=CCSprite::create("Startup_photo_border.png");
//		  photo_border->setPosition(ccp(230,200));

//		  addChild(photo_border);
//		  CCSprite* saveher=CCSprite::create("Startup_lbl_saveher.png");
//		  saveher->setPosition(ccp(230,240));

//		  addChild(saveher);
//		  CCSprite* herface=CCSprite::create("Startup_herface1.png");
//		  herface->setPosition(ccp(230,180));
		  
//		  addChild(herface,2);
//		  herface->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(biqiSmile))));
		  CCMenuItemImage *startItem = CCMenuItemImage::create(
			  "starting-3.png",
			  "starting-4.png",
			  this,
			  menu_selector(GameMenu::startButtonCallback));
		  CC_BREAK_IF(! startItem);

		  // Place the menu item bottom-right conner.
		  startItem->setPosition(ccp(400,270));
		  //this->addChild(skipItem);
		  CCMenu* pMenu = CCMenu::create(startItem, NULL);
		  pMenu->setPosition(CCPointZero);
		  addChild(pMenu);
         
         //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
		  CCMenuItemImage *pkItem = CCMenuItemImage::create(
			  "pk-3.png",
			  "pk-4.png",
			  this,
			  menu_selector(GameMenu::pkItemCallback));
		  CC_BREAK_IF(! pkItem);

		  // Place the menu item bottom-right conner.
		  pkItem->setPosition(ccp(400,205));
		  //this->addChild(skipItem);
		  CCMenu* pkItemMenu = CCMenu::create(pkItem, NULL);
		  pkItemMenu->setPosition(CCPointZero);
		  addChild(pkItemMenu);
         
		   //,,,,,,,,,,,,,,,,,,,,,,
		  CCMenuItemImage *quitItem = CCMenuItemImage::create(
			  "quit-3.png",
			  "quit-4.png",
			  this,
			  menu_selector(GameMenu::quitItemCallback));
		  CC_BREAK_IF(! quitItem);

		  // Place the menu item bottom-right conner.
		  quitItem->setPosition(ccp(400,70));
		  //this->addChild(skipItem);
		  CCMenu* quitItemMenu = CCMenu::create(quitItem, NULL);
		  quitItemMenu->setPosition(CCPointZero);
		  addChild(quitItemMenu);
		  //,,,,,,,,,,,,,,,,,,,,,,
		  CCMenuItemImage *optionItem = CCMenuItemImage::create(
			  "setting-3.png",
			  "setting-4.png",
			  this,
			  menu_selector(GameMenu::optionItemCallback));
		  CC_BREAK_IF(! optionItem );

		  // Place the menu item bottom-right conner.
		  optionItem ->setPosition(ccp(400,140));
		  //this->addChild(skipItem);
		  CCMenu* optionItemMenu = CCMenu::create(optionItem , NULL);
		  optionItemMenu->setPosition(CCPointZero);
		  addChild(optionItemMenu);
		  //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio_bgm_home.mp3",true);
		  bRet = true;
	 }while(0);
	 return bRet;

 }
 void GameMenu::startButtonCallback(CCObject* pSender)
 {
	 CCScene *stageSelect=StageSelect::scene();
	 //CCDirector::sharedDirector()->replaceScene( CCTransitionJumpZoom::create(1.0f,stageSelect));
	 CCDirector::sharedDirector()->pushScene( (CCTransitionSlideInR::create(1, stageSelect)));
 }
 void 	GameMenu::pkItemCallback(CCObject* pSender)
 {
	 CCScene *setting=PkScene::scene();
	 CCDirector::sharedDirector()->pushScene(setting);
 }
void GameMenu::quitItemCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->popScene();
}
 void 	GameMenu::optionItemCallback(CCObject* pSender)
 {
	   CCScene *setting=SettingScene::scene();
	  CCDirector::sharedDirector()->pushScene(setting);
 }
