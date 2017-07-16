#include"Hero.h"
#include"./AminationManager.h"
#include"Global.h"
#include"Gbase.h"
Hero::Hero()
{
	SGlobal->hero=this;
}
Hero::~Hero()
{}

Hero* Hero::heroWithinLayer()
{
	Hero *pRet = new Hero();
	if(pRet && pRet->heroInit())
	{
		pRet->autorelease();
		return pRet;
	}
	return NULL;
}
bool Hero::heroInit()
{
	hspeed=0;
	vspeed=0;
	
	heroSprite = Sprite::create("hero1.png");
	heroSprite->setAnchorPoint(Vec2(0,0));
	this->addChild(heroSprite);	
	return true;
}	

void Hero::move(int i)
{
	log("move...move....................................move");
    
    if (isDead)
    { return ; }
    if (i > 0)
    {
        float targetX = this->getPositionX()+i+Sprite_Size; 
        for (float j=this->getPositionY();j<=(Sprite_Size+this->getPositionY()); j++)
        {
            if (checkCollisionOnly(ccp())) 
        }
    }

	float x=this->getPosition().x;
	float y=this->getPosition().y;
	
	float step=0;
    log("x=%f,,y=%f..",x,y);
	sAnimationMgr->createMoveAnimation();
	
	if(i<0)
	{
		SGlobal->hero->runAction(FlipX::create(false));
		step = -10;
	}
	else
	{
		SGlobal->hero->runAction(FlipX::create(true));
		step = 10;
	}

	this->runAction(MoveTo::create(1.0f,Vec2(x+step,y)));
/*
	this->createMoveAnimate();

	Animation *animation=Animation::create();
	for(int i=1;i<=4;++i)
	{
		std::string frameName="hero";
		frameName.append(StringUtils::format("%d",i)).append(".png");
		animation->addSpriteFrameWithFile(frameName.c_str());
	}
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
	Animate *animate =  Animate::create(animation);

	this->runAction(Sequence::create(animate,animate->reverse(),NULL));
*/
	log("Hero::createMoveAnimte()");
	auto action=sAnimationMgr->createMoveAnimation();
	auto animate=Animate::create(action);
	this->runAction(Sequence::create(animate,animate->reverse(),NULL));

}
void Hero::jump()
{
	log("jump....");
	float x=this->getPosition().x;
	float y=this->getPosition().y;
	this->runAction(MoveTo::create(1.0f,Vec2(x,y+10)));
	this->createMoveAnimate();
	auto action=sAnimationMgr->createJumpAnimation();
	auto animate=Animate::create(action);
	this->runAction(Sequence::create(animate,NULL));

}
void Hero::shoot(bool isLeft)
{
	BulletVelocity = 20;
	log("shoot...........");
	float x=this->getPosition().x;
	float y=this->getPosition().y;

	auto Bullet=Sprite::create("skill6.png");
    if (Bullet == NULL)
    {
        log("Bullet is not created.\n");
        exit(1);
    }
	Bullet->setScaleX(0.3);
	Bullet->setScaleY(0.3);
	Bullet->setPosition(Vec2(x,y));

	this->addChild(Bullet);
	Bullets.pushBack(Bullet);
	float d;
	float s;
	if(isLeft)
	{
		s=-10;
		Bullet->runAction(FlipX::create(true));
		d=s/BulletVelocity;
	}	
	else
	{
		s=10+SGlobal->controlLayer->visibleSize.width;
		Bullet->runAction(FlipX::create(false));
		d=(SGlobal->controlLayer->visibleSize.width)/BulletVelocity;
	}
	auto move = MoveTo::create(d,Vec2(s,y));
	auto cf = CallFunc::create(CC_CALLBACK_0(Hero::RemoveBullet,this,Bullet));
	auto seq = Sequence::create(move,cf,NULL);
	Bullet->runAction(seq);

	auto action=sAnimationMgr->createShootAnimation();
	auto animate=Animate::create(action);
	this->runAction(Sequence::create(animate,animate->reverse(),NULL));
	
}

void Hero::RemoveBullet(cocos2d::Sprite *s)
{
	if(s->getPosition().x>SGlobal->mainGame->visibleSize.width||s->getPosition().x<0)
	{
		log("Remove Bullet..");
		s->removeFromParentAndCleanup(true);
		Bullets.eraseObject(s);
	}
}
void Hero::createMoveAnimate()
{
	Animation *animation=Animation::create();
	for(int i=1;i<=4;++i)
	{
		std::string frameName="hero";
		frameName.append(StringUtils::format("%d",i)).append(".png");
		animation->addSpriteFrameWithFile(frameName.c_str());
	}
	animation->setDelayPerUnit(0.2f);
	animation->setRestoreOriginalFrame(true);
	Animate *animate =  Animate::create(animation);
	this->runAction(Sequence::create(animate,animate->reverse(),NULL));
	log("Hero::createMoveAnimte()");	
}

CollisionType Hero::checkCollisionOnly(Vec2 heroPosition)
{
    return KWall;
}

CollisionType Hero::checkHeadkCollision(Vec2 heroPosition)
{
    return KWall;
}
