#include"Gbase.h"
#include"GameMap.h"

GameMap::GameMap()
{
	SGlobal->gameMap=this;
}

GameMap::~GameMap()
{
	//
}

TMXTiledMap* GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	//GameMap::_tileMap=TMXTiledMap::create(tmxFile);
	//return GameMap::_tileMap;
	return NULL;

}
