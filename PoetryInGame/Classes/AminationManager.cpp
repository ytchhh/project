#include"AminationManager.h"
#include"Gbase.h"
#include"Global.h"
//DECLARE_GBASE_MAMBER(AnimationManager);

AnimationManager::AnimationManager()
{}
AnimationManager::~AnimationManager()
{}
bool AnimationManager::initAnimationMap()
{
	return true;
}

SpriteFrame *AnimationManager::getSpriteFrame(int key)
{

	return NULL;
}

Animate* AnimationManager::createAnimate(int key)
{

	return NULL;
}

Animate* AnimationManager::createAnimate(const char *key)
{

	return NULL;
}

Animation* AnimationManager::getAnimation(int key)
{

	return NULL;
}

Animation*  AnimationManager::createMoveAnimation()
{
	auto animation = Animation::create();
	for(int i=1;i<4;++i)
	{
		std::string frameName = "hero";
		frameName.append(StringUtils::format("%d",i)).append(".png");
		animation->addSpriteFrameWithFile(frameName.c_str());
	}
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
    return animation;
}
Animation*  AnimationManager::createHeroMovingAnimationByDirection()
{
	return this->createMoveAnimation();
}

Animation*  AnimationManager::createJumpAnimation()
{

	return this->createMoveAnimation();
}

Animation*  AnimationManager::createShootAnimation()
{
	Animation* animation = Animation::create();
	for(int i=5;i<8;++i)
	{
		std::string frameName="hero";
		frameName.append(StringUtils::format("%d",i)).append(".png");
		animation->addSpriteFrameWithFile(frameName.c_str());
	}
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
	return animation;
}
