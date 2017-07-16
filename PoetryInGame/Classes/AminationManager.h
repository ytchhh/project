#ifndef _AMINATIONMANAGER_H
#define _AMINATIONMANAGER_H
//#include"Utility.h
#include"cocos2d.h"
#include"Gbase.h"
USING_NS_CC;
class AnimationManager : public Gbase<AnimationManager>
{
public:
	AnimationManager();
	~AnimationManager();

	bool initAnimationMap();
	Animation *getAnimation(int key);
	Animate *createAnimate(int key);
	Animate *createAnimate(const char *key);
	SpriteFrame* getSpriteFrame(int key);

	Animation* createHeroMovingAnimationByDirection();
	Animation* createMoveAnimation();
	Animation* createJumpAnimation();
	Animation* createShootAnimation();

};

#define sAnimationMgr AnimationManager::instance()
#endif
