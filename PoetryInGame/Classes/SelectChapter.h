#ifndef _SELECT_CHAPTER_H
#define _SELECT_CHAPTER_H

#include "cocos2d.h"
#include "Welcome.h"
#include "./MainGame.h"

class SelectChapter : public cocos2d::Layer
{
public :
    static cocos2d::Scene *createScene();
    virtual bool init();
    void backMenuCallBack(cocos2d::Ref* pSender);
    void chapter1MenuCallBack(cocos2d::Ref* pSender);
    CREATE_FUNC(SelectChapter);
	void MainGameMenuCallBack(cocos2d::Ref *pSender);
};

#endif
