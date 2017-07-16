#include "Global.h"
DECLARE_SINGLETON_MEMBER(Global);

Global::Global(void)
{
	isEffectOn=true;
	isMusicOn=true;
	gameStage=1;
	IQ=250;
    globalData=new GlobalData();
}


Global::~Global(void)
{
	game_1_1=NULL;
	gameMap=NULL;
    
    delete globalData;
    globalData=NULL;
}
