#include "Hero.h"


Hero::Hero(void)
{
	sGlobal->hero=this;
}


Hero::~Hero(void)
{
}

//æ≤Ã¨∑Ω∑®£¨”√”⁄…˙≥…Hero µ¿˝
Hero* Hero::heroWithinLayer()
{
	//new“ª∏ˆ∂‘œÛ
	Hero *pRet = new Hero();
	//µ˜”√init∑Ω∑®
	if (pRet && pRet->heroInit())
	{
		//Ω´ µ¿˝∑≈»Îautorelease≥ÿ£¨Õ≥“ª”…“˝«Êøÿ÷∆∂‘œÛµƒ…˙√¸÷‹∆⁄
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool Hero::heroInit()
{
	
	
	isWin=false;
	isanimate=false;
	hspeed=0;
	isDead=false;
	heroSprite = CCSprite::createWithSpriteFrame(sAnimationMgr->getSpritFrame(heronormalkey));
	//…Ë÷√√™µ„
	heroSprite->setAnchorPoint(ccp(0,0));
	//heroSprite->setAnchorPoint(ccp(46*3,46*2+2));
	//Ω´”√”⁄œ‘ æµƒheroSpriteº”µΩ◊‘º∫µƒΩ⁄µ„œ¬
	this->addChild(heroSprite);
	this->setAnchorPoint(ccp(0,0));
	//“ªø™ º≤ª¥¶”⁄move◊¥Ã¨°£
	isHeroMoving = false;
	isJumpDone=false;
	vspeed=0;
	return true;
}
void Hero::move(int i)
{
	   if (isDead)
	   {return;
	   }
	   if(i>0)
	   {

	   float targetX=this->getPositionX()+i+46;
	   for (float j=this->getPositionY();j<=(46+this->getPositionY());j++)
	   {
		   if (checkCollisionOnly(ccp(targetX,j))==kWall)
		   {
			   i=0;
		   }
	   }

	   }
	   if(i<0)
	   {
	   float targetX2=this->getPositionX()+i;
	   for (float j=this->getPositionY();j<=(46+this->getPositionY());j++)
	   {
		   if (checkCollisionOnly(ccp(targetX2,j))==kWall)
		   {
			   i=0;
		   }
	   }
	   }
		this->setPosition(this->getPositionX()+1*i,this->getPositionY());
		setViewpointCenter(this->getPosition());
		hspeed=i;
		if (!isanimate&&i!=0&&isJumpDone)
		{
			AnimationKey key;
			
			if (i<0)
			{
				key=aLeft;
			}else 
			{
				key=aRight;
			}
				
			CCAnimation *animation=sAnimationMgr->getAnimation(key);
			CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(Hero::animateDone));
			heroSprite->runAction(CCSequence::create(CCAnimate::create(animation),actionMoveDone,NULL));
			isanimate=true;
		}
	
}
void Hero::jump()
{
	
	if (isDead&&this->getPositionY()<5)
	{
		this->setPosition(this->getPositionX(),this->getPositionY()-6);
	
	}
	if (isDead)
		{
			heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
			return;
		}
	
	
	

	
	if (vspeed!=-0.4f)
	{
		CCSpriteFrameKey framekey;
		if (hspeed<0)
		{
			framekey=heroleftJumpkey;
		}
		else{
			framekey=herorightJumpkey;
		}
		heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(framekey));
	}else if(hspeed==0)
	{
		if (this->isDead)
		{heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
		}else{
		
		heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(heronormalkey));
		}
	}
	float x=this->getPositionX();
	float y=this->getPositionY();
	float targetY=this->getPositionY()+vspeed;
	for (int i=this->getPositionX()+4;i<=(this->getPositionX()+42);i++)
	{
		if (checkCollisionOnly(ccp(i,targetY))==kWall)
		{
			
			vspeed=-0.4;
			isJumpDone=true;
			return;
		}
	}
	float targetY2=this->getPositionY()+vspeed+46;
	for (int i=this->getPositionX()+4;i<=(this->getPositionX()+42);i++)
	{

		if (checkCollisionOnly(ccp(i,targetY2))==kWall)
		{
			vspeed=-0.4;
			
			return;
		}
        /*
		if (vspeed>0)
		{
			if(checHeadkCollision(ccp(i,targetY2))==khideblock)
			{
				vspeed=-0.4;
				if (sGlobal->isEffectOn)
				{
				
             CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio_gold.mp3",false);
			 }
				return;
			}
		}
         */
	}
	
	
	isJumpDone=false;
	this->setPosition(this->getPositionX(),this->getPositionY()+vspeed);
	vspeed=vspeed-0.4f;

	
}
CollisionType Hero::checkCollisionOnly(CCPoint heroPosition)
{
	//cocos2d-x◊¯±Í◊™ªªŒ™Tilemap◊¯±Í
	if (heroPosition.y<=4)
	{
		this->isDead=true;
		//heroSprite->runAction(CCRepeatForever::create(CCAnimate::create(sAnimationMgr->getAnimation(aDie))));
		
	}
	CCPoint targetTileCoord = sGlobal->gameMap->tileCoordForPosition(heroPosition);

	//»Áπ˚”¬ ø◊¯±Í≥¨π˝µÿÕº±ﬂΩÁ£¨∑µªÿkWall¿‡–Õ£¨◊Ë÷π∆‰“∆∂Ø
	if (heroPosition.x < 0 || targetTileCoord.x > sGlobal->gameMap->getMapSize().width - 1 ||  targetTileCoord.y > sGlobal->gameMap->getMapSize().height - 1)
		return kWall;
	//ªÒ»°À˙œ›«Ω±⁄≤„∂‘”¶◊¯±ÍµƒÕºøÈID
		

	int tagetid=sGlobal->gameMap->getCollidableLayer()->tileGIDAt(targetTileCoord);

	if (tagetid)
	{
		return kWall;
	}
    int deadid=sGlobal->gameMap->getTrapLayer()->tileGIDAt(targetTileCoord);
    if (deadid)
    {
        this->isDead=true;
        return kWall;
    }
    
    int wordid=sGlobal->gameMap->getWordLayer()->tileGIDAt(targetTileCoord);
    if (wordid)
    {
        printf("%d\n", wordid);
        sGlobal->globalData->setWordId(wordid-81);
        sGlobal->gameMap->getWordLayer()->removeTileAt(targetTileCoord);
        sGlobal->globalData->setOwnWord(sGlobal->globalData->getOwnWord()+1);
        printf("得到一个字，一共得到%d个字，还有%d个字等你发现\n", sGlobal->globalData->getOwnWord(), sGlobal->globalData->getLeaveWord());
        return kNone;
    }
	/*
	if (tagetid)
	{
		
		if (this->getPositionX()<240)
		{
			setLayerEmpty(ccp(0,16),14,4);
		}
		if (this->getPositionX()>576&&this->getPositionX()<15*48)
		{
			setLayerEmpty(ccp(24,16),6,4);
		}
		if (this->getPositionX()>1152&&this->getPositionX()<1248)
		{
			setLayerEmpty(ccp(48,16),4,4);
		}
		if (this->getPositionX()>28*48&&this->getPositionX()<31*48)
		{
			setLayerEmpty(ccp(56,16),6,4);
		}

		return kWall;
	}*/
    /*
	int targetTileGID = sGlobal->gameMap->getPlatformLayer()->tileGIDAt(targetTileCoord);
	//»Áπ˚ÕºøÈID≤ªŒ™0£¨±Ì æ”–«Ω
	if (targetTileGID) 
	{
		return kWall;
	}
     */
    
	if (sGlobal->gameStage==1)
	{
	

	int winID=sGlobal->gameMap->getBiqiLayer()->tileGIDAt(targetTileCoord);
	if (winID) 
	{
        if (sGlobal->globalData->getLeaveWord()==0)
        {
            if (!this->isWin)
            {
        		this->isWin=true;
                sGlobal->globalData->setHeroStrength(sGlobal->globalData->getHeroStrength()+20);
                printf("英雄战力提升20，现在的战力是%d\n", sGlobal->globalData->getHeroStrength());
        		return kbiqi;
            }
        }
        else
        {
            printf("你只有收集完所有的字才能通过，继续努力吧!\n");
            return kWall;
        }
	}
	}
	return kNone;
}
/*
CollisionType Hero::checHeadkCollision(CCPoint heroPosition)
{
	CCPoint targetTileCoord = sGlobal->gameMap->tileCoordForPosition(heroPosition);
	int hideblockId=sGlobal->gameMap->getHideBlockLayer()->tileGIDAt(targetTileCoord);
	//sGlobal->gameMap->getHideBlockLayer()->
	if (hideblockId)
	{
	 
	  CCPoint  startposition;
	  if (sGlobal->gameMap->getHideBlockLayer()->tileGIDAt(ccp(targetTileCoord.x-1,targetTileCoord.y)))
	  {
		  startposition=ccp(targetTileCoord.x-1,targetTileCoord.y);
	  }else
	  {
	         startposition=targetTileCoord;
	  }
	//   startposition=targetTileCoord;
	 int id=  sGlobal->gameMap->getPlatformLayer()->tileGIDAt(ccp(0,0));
	  sGlobal->gameMap->getPlatformLayer()->setTileGID(id,startposition);
	  sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x+1,startposition.y));
	   sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x+1,startposition.y-1));
	   sGlobal->gameMap->getPlatformLayer()->setTileGID(id,ccp(startposition.x,startposition.y-1));
	   sGlobal->gameMap->hideBlockAnimate(startposition);
	   return khideblock;
	}
	return kNone;
}
 */
void Hero::setViewpointCenter(CCPoint p)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	float x=MAX(p.x,size.width/2);
	float y=MAX(p.y,size.height/2);
	
	x=MIN(x,(sGlobal->gameMap->getMapSize().width*sGlobal->gameMap->getTileSize().width)-size.width/2);
	y=MIN(y,(sGlobal->gameMap->getMapSize().height*sGlobal->gameMap->getTileSize().height)-size.height/2);
	CCPoint actualPosition=ccp(x,y);
	CCPoint centerOfView=ccp(size.width/2,size.height/2);
	CCPoint viewPoint=ccpSub(centerOfView,actualPosition);
	int x1=viewPoint.x;
	int y1=viewPoint.y;
	int herox=p.x;
	int heroy=p.y;
	int thisx=this->getPositionX();
	int htisy=this->getPositionY();
	int mapSize=sGlobal->gameMap->getMapSize().width;
	int TileSize=sGlobal->gameMap->getTileSize().width;
	
	sGlobal->game_1_1->setPosition(viewPoint);
	int x2=0-viewPoint.x;
	int y2=0-viewPoint.y;
	//sGlobal->controlLayer->setPosition(ccp((float)x2,(float)y2));
	//controlSprite->setPosition(ccp((float)x2,(float)y2));
}
void Hero::animateDone(CCNode *sender)
{
	isanimate=false;
	//heroSprite->setDisplayFrame(sAnimationMgr->getSpritFrame(heronormalkey));
}
/*
void Hero::setLayerEmpty(CCPoint start,int width,int height)
{
	for (int i=start.y;i<height+start.y;i++)
	{
		for (int j=start.x;j<width+start.x;j++)
		{
			sGlobal->gameMap->getPlatformDynamicLayer()->removeTileAt(ccp(j,i));
		}
	}
	
}
 */
