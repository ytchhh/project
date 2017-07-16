#ifndef _MAINGAME_H
#define _MAINGAME_H

#include"cocos2d.h"




USING_NS_CC;

class MainGame:public cocos2d::Layer
{
public:
	MainGame();
	~MainGame();
	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(MainGame);
	cocos2d::Size  visibleSize;
private:
};

#endif
