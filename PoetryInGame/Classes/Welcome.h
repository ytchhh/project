#ifndef     _FIRSTSCENE_H_
#define     _FIRSTSCENE_H_
#include "cocos2d.h"

class Welcome : public cocos2d::Layer
{
public :
    static cocos2d::Scene *createScene();
    virtual bool init();
    void menuStartCallBack(cocos2d::Ref* pSender);
    void menuSettingCallBack(cocos2d::Ref* pSender);
    void menuExitCallBack(cocos2d::Ref* pSender);
    void menuPKModeCallBack(cocos2d::Ref* pSender);
    CREATE_FUNC(Welcome);

};

#endif
