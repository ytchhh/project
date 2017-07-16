#include "GameMap.h"
CCSprite *hideBlock;
CCSprite* goldSprite;
GameMap::GameMap(void)
{
	sGlobal->gameMap=this;
}


GameMap::~GameMap(void)
{
	this->unscheduleAllSelectors();
}
/*用不到
void GameMap::removeFloor(CCPoint point)
{
	
	int maxy=sGlobal->gameMap->getMapSize().height;
	int heroheight=sGlobal->hero->getContentSize().height;
	for (int y=maxy;y>=point.y;y--)
	{
		int id=platformDynamicLayer->tileGIDAt(point);
		if(id)
		{
			CCSprite *sprite=platformDynamicLayer->tileAt(point);
			float s=(maxy-point.y)*this->getTileSize().height+heroheight;//“™◊ﬂµƒæ‡¿Î
			CCMoveTo *ccmoveto=CCMoveTo::create(s/9.0f,ccp(point.x*this->getTileSize().width,-heroheight));
		    sprite->runAction(ccmoveto);
			platformDynamicLayer->removeTileAt(point);
		}
	}
}
 */

//æ≤Ã¨∑Ω∑®£¨”√”⁄…˙≥…GameMap µ¿˝
//无需修改
GameMap* GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	//new“ª∏ˆ∂‘œÛ
	GameMap *pRet = new GameMap();
	//µ˜”√init∑Ω∑®
	if (pRet->initWithTMXFile(tmxFile))
	{
		//µ˜”√∂ÓÕ‚µƒinit∑Ω∑®
		pRet->extraInit();
		//Ω´ µ¿˝∑≈»Îautorelease≥ÿ£¨Õ≥“ª”…“˝«Êøÿ÷∆∂‘œÛµƒ…˙√¸÷‹∆⁄
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
//TliedMap∂ÓÕ‚µƒ≥ı ºªØ∑Ω∑®
void GameMap::extraInit()
{
	//ø™∆Ù∏˜∏ˆÕº≤„µƒŒ∆¿Ìøπæ‚≥›
	enableAnitiAliasForEachLayer();
	//≥ı ºªØ∏˜≤„∂‘œÛ
	 //platformLayer = this->layerNamed("Platform");
	ObjectsLayer = this->layerNamed("Objects");
	CollidableLayer = this->layerNamed("Collidable");
	LayerLayer = this->layerNamed("Layer");
    BiqiLayer = this->layerNamed("biqi");
    BiqiLayer->setVisible(false);
    TrapLayer = this->layerNamed("trap");
    WordLayer = this->layerNamed("word");
    notBiqiLayer = this->layerNamed("notBiqi");
    //ObjectsLayer->setVisible(false);
	//hideBlockLayer->setVisible(false);
	//platformDynamicLayer->setVisible(false);
	//itemLayer = this->layerNamed("item");
	//doorLayer = this->layerNamed("door");

	
}
//不用修改
void GameMap::enableAnitiAliasForEachLayer()
{
	CCArray * pChildrenArray = this->getChildren();
	CCSpriteBatchNode* child = NULL;
	CCObject* pObject = NULL;
	//±È¿˙TilemapµƒÀ˘”–Õº≤„
	CCARRAY_FOREACH(pChildrenArray, pObject)
	{
		child = (CCSpriteBatchNode*)pObject;
		if(!child)
			break;
		//∏¯Õº≤„µƒŒ∆¿Ìø™∆Ùøπæ‚≥›
		child->getTexture()->setAntiAliasTexParameters();
	}
}

//no
//¥”cocos2d-x◊¯±Í◊™ªªŒ™Tilemap◊¯±Í
CCPoint GameMap::tileCoordForPosition(CCPoint position)
{
	int x = position.x / this->getTileSize().width;
	int y = (((this->getMapSize().height) * this->getTileSize().height) - position.y) / this->getTileSize().height;
	return ccp(x, y);
}

//no
//¥”Tilemap◊¯±Í◊™ªªŒ™cocos2d-x◊¯±Í
CCPoint GameMap::positionForTileCoord(CCPoint tileCoord)
{
	CCPoint pos =  ccp((tileCoord.x * this->getTileSize().width),
		((this->getMapSize().height - tileCoord.y) * this->getTileSize().height));
	return pos;
}
//∑µªÿµÿ∞Â≤„
CCTMXLayer* GameMap::getObjectsLayer()
{
    return ObjectsLayer;
}
CCTMXLayer* GameMap::getCollidableLayer()
{
	return CollidableLayer;
}
CCTMXLayer* GameMap::getLayerLayer()
{
	return LayerLayer;
}
CCTMXLayer* GameMap::getBiqiLayer()
{
    return BiqiLayer;
}
CCTMXLayer* GameMap::getTrapLayer()
{
    return TrapLayer;
}
CCTMXLayer* GameMap::getWordLayer()
{
    return WordLayer;
}
CCTMXLayer* GameMap::getnotBiqiLayer()
{
    return notBiqiLayer;
}
/*
CCTMXLayer* GameMap::getBiqiLayer()
{
	return biqiLayer;
}
 */
/*
void GameMap::hideBlockAnimate(CCPoint target)
{
	
	target=positionForTileCoord(target);
	target=ccp(target.x,target.y-24);
	hideBlock=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(whyBlockKey));
	hideBlock->setAnchorPoint(ccp(0,0));
	hideBlock->setPosition(target);
	sGlobal->game_1_1->addChild(hideBlock );

	
	CCPointArray* array=CCPointArray::create(2);
	array->addControlPoint(ccp(target.x,target.y+10));
	array->addControlPoint(target);
	CCCardinalSplineTo *cardinal=CCCardinalSplineTo::create(0.4f,array,0);
	//CCFiniteTimeAction* action=cardinal->release();
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(GameMap::blockMoveFinished));
	
	hideBlock->runAction(CCSequence::create(cardinal,actionMoveDone,NULL));
	goldSprite=CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(goldCoinkey));
   goldSprite->setAnchorPoint(ccp(0,0));
   goldSprite->setPosition(ccp(target.x+10,target.y+48));
	CCFiniteTimeAction *actionMove=CCMoveBy::create(0.9f,ccp(0,60));

	CCFiniteTimeAction* goldMoveDone=CCCallFuncN::create(this,callfuncN_selector(GameMap::removeGold));
	sGlobal->game_1_1->addChild(goldSprite );
	goldSprite->runAction(CCSequence::create(actionMove,goldMoveDone,NULL));
}
*/
/*
void GameMap::blockMoveFinished(CCNode *sender)
{

	hideBlock->setDisplayFrame(sAnimationMgr->getSpritFrame(firmBlockKey));
}
 */
/*
void GameMap::removeGold(CCNode *sender)
{
	CCFadeOut* fadeout=CCFadeOut::create(0.8f);
	goldSprite->runAction(fadeout);
}
*/