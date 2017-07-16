//
//  PkScene.h
//  PoetryInGame
//
//  Created by LHG on 3/25/17.
//
//

#ifndef PkScene_h
#define PkScene_h

#include "BZDMX.h"
class PkScene : public cocos2d::CCLayer
{
public:
    PkScene(void);
    ~PkScene(void);
    virtual bool init();
    static cocos2d::CCScene* scene();
    void ensurePkItemCallback(CCObject* pSender);
    CREATE_FUNC(PkScene);
	void  pkCallback(CCObject* pSender);
	void animateFinished(CCObject*  pSender);
	void MenuCallback(CCObject*  pSender);
};

#endif /* PkScene_h */
