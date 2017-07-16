#ifndef _GLOBAL_H
#define _GLOBAL_H
#include"Utility.h"
#include"Gbase.h"
class GameMap;
class Hero;
class ControlLayer;
class MainGame;
class Global:public Gbase<Global>
{
public:
	Global();
	~Global();
	GameMap *gameMap;
	Hero *hero;
	ControlLayer *controlLayer;
	MainGame *mainGame;

};
#define SGlobal Global::instance()

#endif
