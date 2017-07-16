//
//  PkScene.h
//  PoetryInGame
//
//  Created by LHG on 3/25/17.
//
//

 #pragma once


#include "BZDMX.h"
class pk_Animation : public cocos2d::CCLayer
{
public:
    pk_Animation(void);
    ~pk_Animation(void);
    virtual bool init();
    static cocos2d::CCScene* scene();
    void playPkAnimation();
    CREATE_FUNC(pk_Animation);
	void  PkSceneCallback(CCObject* pSender);
	void animateFinished(CCObject*  pSender);
	void ShowGameResult(CCObject* pSender);
};

