#ifndef _CONTROLLAYER_H
#define _CONTROLLAYER_H

#include"Utility.h"
USING_NS_CC;
/*
typedef enum
{
MoveLeft=1,MoveRight,Jump,Shoot
}ActType;
*/
class ControlLayer : public cocos2d::Layer
{
public:
	ControlLayer();
	~ControlLayer();

	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(ControlLayer);
	bool touchBegan(cocos2d::Touch *touch,cocos2d::Event *event);
	void touchMoved(cocos2d::Touch *touch,cocos2d::Event *event);
	void touchEnded(cocos2d::Touch *touch,cocos2d::Event *event);

	void  update(float dt);
	void gamePauseMenuCallBack(cocos2d::Ref* pSender);
	cocos2d::Size visibleSize;
	bool isLeft;
private:
	int _screenWidth;
	int _screenHeight;
	cocos2d::Vec2 origin;
	bool isTouched;
	int  act_type;
};

#endif
