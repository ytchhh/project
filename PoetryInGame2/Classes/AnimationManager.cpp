#include "AnimationManager.h"

DECLARE_SINGLETON_MEMBER(AnimationManager);
AnimationManager::AnimationManager(void)
{
}


AnimationManager::~AnimationManager(void)
{
}

//将地图中所有要用到的图片加载到缓存CCSpriteFrameCache
bool AnimationManager::initAnimationMap()
{
	char temp[20];
	
	sprintf(temp, "%d", aRight);
	//º”‘ÿ”¬ øœÚ”“◊ﬂµƒ∂Øª≠
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hright), temp);
	sprintf(temp, "%d", aLeft);
	//º”‘ÿ”¬ øœÚ◊Û◊ﬂµƒ∂Øª≠
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hleft), temp);
	sprintf(temp, "%d", aDie);
	//º”‘ÿ”¬ øÀ¿Õˆµƒ∂Øª≠
	CCAnimationCache::sharedAnimationCache()->addAnimation(createHeroMovingAnimationByDirection(hdie), temp);
	 
	sprintf(temp, "%d", heroCry);
	
	CCAnimationCache::sharedAnimationCache()->addAnimation(createCryAnimation(), temp);

	sprintf(temp, "%d", victory);

	CCAnimationCache::sharedAnimationCache()->addAnimation(createVictoryAnimation(), temp);
	
	sprintf(temp, "%d", biqiSmile);

	CCAnimationCache::sharedAnimationCache()->addAnimation(createBiqiSmile(), temp);
	/*
	CCSpriteFrame *heronormal, *heroleftJump, *herorightJump;

	//µ⁄∂˛∏ˆ≤Œ ˝±Ì æœ‘ æ«¯”Úµƒx, y, width, height£¨∏˘æ›direction¿¥»∑∂®œ‘ æµƒy◊¯±Í

	CCTexture2D *heroTexture = CCTextureCache::sharedTextureCache()->addImage("hero.png");
	heronormal = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*1, eSize*0, eSize, eSize));
	heroleftJump = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*2, eSize*0, eSize, eSize));
	herorightJump = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*3, eSize*0, eSize, eSize));
*/
	CCSpriteFrame* heronormal=CCSpriteFrame::create("panda10-3.png",CCRectMake(0,0,50,50));
	CCSpriteFrame* heroleftJump=CCSpriteFrame::create("panda3-4.png",CCRectMake(0,0,50,50));
	CCSpriteFrame* herorightJump=CCSpriteFrame::create("panda3-3.png",CCRectMake(0,0,50,50));

	CCSpriteFrame *controlLeft=CCSpriteFrame::create("Thumb_dpad_left.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlLeftPressed=CCSpriteFrame::create("Thumb_dpad_left_pressed.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlRight=CCSpriteFrame::create("Thumb_dpad_right.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlRightPressed=CCSpriteFrame::create("Thumb_dpad_right_pressed.png",CCRectMake(0,0,90,90));
	CCSpriteFrame *controlJump=CCSpriteFrame::create("Thumb_dpad_jump.png",CCRectMake(0,0,135,90));
	CCSpriteFrame *controlJumpPressed=CCSpriteFrame::create("Thumb_dpad_jump_pressed.png",CCRectMake(0,0,135,90));
	sprintf(temp, "%d", heronormalkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(heronormal,temp);
	sprintf(temp, "%d", heroleftJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(heroleftJump,temp);
	sprintf(temp, "%d", herorightJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(herorightJump,temp);
	sprintf(temp, "%d", controlLeftkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlLeft,temp);
	sprintf(temp, "%d", controlLeftPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlLeftPressed,temp);
	sprintf(temp, "%d", controlRightkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlRight,temp);
	sprintf(temp, "%d", controlRightPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlRightPressed,temp);
	sprintf(temp, "%d", controlJumpkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlJump,temp);
	sprintf(temp, "%d", controlJumpPressedkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(controlJumpPressed,temp);
    
	CCTexture2D *tileTexture = CCTextureCache::sharedTextureCache()->addImage("Tile_source.png");
    
	CCSpriteFrame *whyBlock=CCSpriteFrame::createWithTexture(tileTexture, cocos2d::CCRectMake(0, 96, 48, 48));
	sprintf(temp, "%d", whyBlockKey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(whyBlock,temp);
	CCSpriteFrame *firmBlock=CCSpriteFrame::createWithTexture(tileTexture, cocos2d::CCRectMake(240, 0, 48, 48));
	sprintf(temp, "%d", firmBlockKey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(firmBlock,temp);
    
	CCSpriteFrame *gold=CCSpriteFrame::create("gold.png",CCRectMake(0,0,48,48));
	sprintf(temp, "%d", goldCoinkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(gold,temp);
	CCSpriteFrame *box=CCSpriteFrame::create("Navigator_tv.png",CCRectMake(0,0,527,418));
	sprintf(temp, "%d", failedboxkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(box,temp);

	CCSpriteFrame *cryFrame=CCSpriteFrame::create("Navigator_lose_image_1.png",CCRectMake(0,0,179,176));
	sprintf(temp, "%d", cryFramekey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(cryFrame,temp);

	CCSpriteFrame *onFrame=CCSpriteFrame::create("Switch_on.png",CCRectMake(0,0,130,58));
	sprintf(temp, "%d", onkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(onFrame,temp);
	
	CCSpriteFrame *offFrame=CCSpriteFrame::create("Switch_off.png",CCRectMake(0,0,130,58));
	sprintf(temp, "%d", offkey);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(offFrame,temp);

CCSpriteFrame* boss=CCSpriteFrame::create("monster1.png",CCRectMake(0,0,200,170));
sprintf(temp,"%d",bosskey);
CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(boss,temp);

//PK animation



	CCSpriteFrame* right1=CCSpriteFrame::create("panda1-1.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* right2=CCSpriteFrame::create("panda2-2.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* right3=CCSpriteFrame::create("panda3-3.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* left1=CCSpriteFrame::create("panda1-2.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* left2=CCSpriteFrame::create("panda2-3.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* left3=CCSpriteFrame::create("panda3-4.png",CCRectMake(0,0,49,49));
	/*
	sprintf(temp,"%d",Right1);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(right1,temp);
	sprintf(temp,"%d",Right2);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(right2,temp);
	sprintf(temp,"%d",Right3);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(right3,temp);
	
	sprintf(temp,"%d",Left1);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(left1,temp);
	sprintf(temp,"%d",Left2);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(left2,temp);
	sprintf(temp,"%d",Left3);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(left3,temp);
	*/
	return true;
}

//根据每一个动作的key值返回相应的fram
CCSpriteFrame * AnimationManager::getSpritFrame(int key)
{
	char temp[20];
	sprintf(temp, "%d", key);
	return CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(temp);
}

//根据不同的方向创建不同方向的图片
CCAnimation* AnimationManager::createHeroMovingAnimationByDirection(HeroDirection direction)
{
	CCSpriteFrame* right1=CCSpriteFrame::create("panda4-4.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* right2=CCSpriteFrame::create("panda5-5.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* right3=CCSpriteFrame::create("panda6-6.png",CCRectMake(0,0,49,49));
	
	CCSpriteFrame* left1=CCSpriteFrame::create("panda4-5.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* left2=CCSpriteFrame::create("panda5-6.png",CCRectMake(0,0,49,49));
	CCSpriteFrame* left3=CCSpriteFrame::create("panda6-7.png",CCRectMake(0,0,49,49));
	CCArray* animFrames=new CCArray(3);
	if(direction==hleft)
	{
		animFrames->addObject(left1);
		animFrames->addObject(left2);
		animFrames->addObject(left3);
	}
	else
	{
		animFrames->addObject(right1);
		animFrames->addObject(right2);
		animFrames->addObject(right3);
	}
	CCAnimation* animation=CCAnimation::createWithSpriteFrames(animFrames,0.09f);
	animFrames->release();
	return animation;



/*
	CCTexture2D *heroTexture = CCTextureCache::sharedTextureCache()->addImage("Hero_image.png");
	CCSpriteFrame *frame0, *frame1, *frame2;
	CCArray* animFrames ;
	//µ⁄∂˛∏ˆ≤Œ ˝±Ì æœ‘ æ«¯”Úµƒx, y, width, height£¨∏˘æ›direction¿¥»∑∂®œ‘ æµƒy◊¯±Í
	
	
	frame0 = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*0, eSize*direction, eSize, eSize));
	frame1 = CCSpriteFrame::createWithTexture(heroTexture, cocos2d::CCRectMake(eSize*1, eSize*direction, eSize, eSize));

	
	 animFrames = new CCArray(2);
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.09f);

	animFrames->release();
	
	return animation;

*/	
/*
	if(direction==4)
	{
		CCArray *animFrames;
//	CCSpriteFrame* frame1 = CCSpriteFrame::create("panda1-1.png",CCRectMake(0,0,49,49));
//	CCSpriteFrame* frame2 = CCSpriteFrame::create("panda2-2.png",CCRectMake(0,0,49,49));
//	CCSpriteFrame* frame3 = CCSpriteFrame::create("panda3-3.png",CCRectMake(0,0,49,49));
		CCSpriteFrame* frame4 = CCSpriteFrame::create("panda4-4.png",CCRectMake(0,0,49,49));
		CCSpriteFrame* frame5 = CCSpriteFrame::create("panda5-5.png",CCRectMake(0,0,49,49));
		CCSpriteFrame* frame6 = CCSpriteFrame::create("panda6-6.png",CCRectMake(0,0,49,49));
		animFrames=new CCArray(3);
		animFrames->addObject(frame4);
		animFrames->addObject(frame5);
		animFrames->addObject(frame6);
//	animFrames->addObject(frame4);
//	animFrames->addObject(frame5);
//	animFrames->addObject(frame6);
		CCAnimation* animation= CCAnimation::createWithSpriteFrames(animFrames,0.9f);
		animFrames->release();
		return animation;
	}
//
	else if(direction==hleft)
	{
		CCArray* animFrames;
		CCSpriteFrame* frame1=CCSpriteFrame::create("panda3-4.png",CCRectMake(0,0,49,49));
		CCSpriteFrame* frame2 = CCSpriteFrame::create("panda4-5.png",CCRectMake(0,0,49,49));
		CCSpriteFrame* frame3 = CCSpriteFrame::create("panda5-6.png",CCRectMake(0,0,49,49));
		animFrames = new CCArray(3);
		animFrames->addObject(frame1);
		animFrames->addObject(frame2);
		animFrames->addObject(frame3);
		CCAnimation* animation=CCAnimation::createWithSpriteFrames(animFrames,0.9f);
		animFrames->release();
		return animation;
	
	}
	else 
	{
		//return NULL;
	}
	*/
}
//ªÒ»°øﬁ∆¸∂Øª≠
//创建动画
CCAnimation* AnimationManager::createCryAnimation()
{
	CCSpriteFrame *frame0, *frame1, *frame2,*frame3;
	CCArray* animFrames =CCArray::createWithCapacity(4);
    //CCRectMake   选择的是图片中的哪个区域
	frame0=CCSpriteFrame::create("Navigator_lose_image_1.png",CCRectMake(0,0,179,176));
	frame1=CCSpriteFrame::create("Navigator_lose_image_2.png",CCRectMake(0,0,179,176));
	frame2=CCSpriteFrame::create("Navigator_lose_image_3.png",CCRectMake(0,0,179,176));
	frame3=CCSpriteFrame::create("Navigator_lose_image.png",CCRectMake(0,0,179,176));
	
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	animFrames->addObject(frame3);
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
	animFrames->release();
	
	return animation;
}
CCAnimation* AnimationManager::createVictoryAnimation()
{

	CCSpriteFrame *frame0, *frame1;
	CCArray* animFrames =CCArray::createWithCapacity(2);
	frame0=CCSpriteFrame::create("Navigator_win_image_2.png",CCRectMake(0,0,179,176));
	frame1=CCSpriteFrame::create("Navigator_win_image_1.png",CCRectMake(0,0,179,176));


	animFrames->addObject(frame0);
	animFrames->addObject(frame1);

	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
	animFrames->release();

	return animation;
}
//ªÒ»°÷∏∂®∂Øª≠ƒ£∞Ê
CCAnimation* AnimationManager::getAnimation(int key)
{
	char temp[20];
	sprintf(temp, "%d", key);
	return CCAnimationCache::sharedAnimationCache()->animationByName(temp);
}

//ªÒ»°“ª∏ˆ÷∏∂®∂Øª≠ƒ£∞Êµƒ µ¿˝
CCAnimate* AnimationManager::createAnimate(int key)
{
	//ªÒ»°÷∏∂®∂Øª≠ƒ£∞Ê
	CCAnimation* anim = getAnimation(key);
	if(anim)
	{
		//∏˘æ›∂Øª≠ƒ£∞Ê…˙≥…“ª∏ˆ∂Øª≠ µ¿˝
		return CCAnimate::create(anim);
	}
	return NULL;
}

//ªÒ»°“ª∏ˆ÷∏∂®∂Øª≠ƒ£∞Êµƒ µ¿˝
CCAnimate* AnimationManager::createAnimate(const char* key)
{
	//ªÒ»°÷∏∂®∂Øª≠ƒ£∞Ê
	CCAnimation* anim = CCAnimationCache::sharedAnimationCache()->animationByName(key);
	if(anim)
	{
		//∏˘æ›∂Øª≠ƒ£∞Ê…˙≥…“ª∏ˆ∂Øª≠ µ¿˝
		return CCAnimate::create(anim);
	}
	return NULL;
}
CCAnimation* AnimationManager::createBiqiSmile()
{

	CCSpriteFrame *frame0, *frame1,*frame2;
	CCArray* animFrames =CCArray::createWithCapacity(3);
	frame0=CCSpriteFrame::create("Startup_herface1.png",CCRectMake(0,0,97,92));
	frame1=CCSpriteFrame::create("Startup_herface2.png",CCRectMake(0,0,97,92));
    frame2=CCSpriteFrame::create("Startup_herface3.png",CCRectMake(0,0,97,92));

	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.6f);
	animFrames->release();

	return animation;
}
