#ifndef _HERO_H
#define _HERO_H
#include "Utility.h"
USING_NS_CC;
//#include"Utility.h"
class Hero : public cocos2d::Node
{
public:
	Hero();
	~Hero();
	static Hero* heroWithinLayer();
	bool heroInit();
	void move(int i);
	
	void jump();
	void shoot(bool isLeft);
	void RemoveBullet(cocos2d::Sprite *s);
	float hspeed;
	float vspeed;

	cocos2d::Vector<cocos2d::Sprite*> Bullets;
	float BulletVelocity;

	void  createMoveAnimate();
    
    //CollisionType checkCollision(Vec2 heroPosition);
	void setViewPointCenter(Point p);
    CollisionType checkCollisionOnly(Vec2 heroPosition);
    CollisionType checkHeadkCollision(Vec2 heroPosition);
    
private:
	Sprite *heroSprite;
	
};
#endif
