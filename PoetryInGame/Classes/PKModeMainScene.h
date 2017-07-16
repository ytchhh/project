#ifndef     _PKMODE_MAIN_SCENE_H
#define     _PKMODE_MAIN_SCENE_H

#include "cocos2d.h"

class PKModeMainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();

    void ensurePKMenuCallBack(cocos2d::Ref* pSender);
    void backMainMenuCallBack(cocos2d::Ref* pSender);
    
    CREATE_FUNC(PKModeMainScene);
};




#endif  
