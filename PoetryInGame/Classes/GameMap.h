#ifndef _GAMEMAP_H
#define _GAMEMAP_H
#include"Utility.h"
class GameMap:public cocos2d::Node
{
public:
	GameMap();
	~GameMap();

static	TMXTiledMap* gameMapWithTMXFile(const char *tmxFile);
private:
//	static cocos2d::TMXTiledMap* _tileMap;
};
#endif
