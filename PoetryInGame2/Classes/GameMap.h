#pragma once
#include "BZDMX.h"
class GameMap : public cocos2d::CCTMXTiledMap
{
public:
	GameMap(void);
	~GameMap(void);

    /*
	CC_PROPERTY_READONLY(CCTMXLayer*, platformLayer, PlatformLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, hideBlockLayer, HideBlockLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, platformDynamicLayer,PlatformDynamicLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, biqiLayer,BiqiLayer);
     */
	CC_PROPERTY_READONLY(CCTMXLayer*, ObjectsLayer, ObjectsLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, CollidableLayer, CollidableLayer);
	CC_PROPERTY_READONLY(CCTMXLayer*, LayerLayer, LayerLayer);
    CC_PROPERTY_READONLY(CCTMXLayer*, BiqiLayer, BiqiLayer);
    CC_PROPERTY_READONLY(CCTMXLayer*, TrapLayer, TrapLayer)
    CC_PROPERTY_READONLY(CCTMXLayer*, WordLayer, WordLayer)
    CC_PROPERTY_READONLY(CCTMXLayer*, notBiqiLayer, notBiqiLayer)

	// 声明一个成员变量以及get##funName函数，没有set函数。get##funName函数只有声明，而没有定义。代码如下:
	//静态方法，用于生成GameMap实例
	static GameMap* gameMapWithTMXFile(const char *tmxFile);
	//TiledMap和cocos2d-x坐标系相互转换的方法
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
	//void hideBlockAnimate(CCPoint target);
	//void blockMoveFinished(CCNode *sender);
	//void removeGold(CCNode *sender);
	//动画移除砖块
	//void removeFloor(CCPoint point);
protected:
	//TiledMap额外的初始化方法
	void extraInit();
	//开启各图层的纹理抗锯齿
	void enableAnitiAliasForEachLayer();
};

