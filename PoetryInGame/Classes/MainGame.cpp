#include"MainGame.h"
#include"Global.h"
#include"SelectChapter.h"
#include"GameMap.h"
#include"Gbase.h"
USING_NS_CC;

MainGame::MainGame()
{
	SGlobal->mainGame=this;
}
MainGame::~MainGame()
{}
Scene* MainGame::createScene()
{
	auto scene=Scene::create();
	auto layer=MainGame::create();
	scene->addChild(layer);
	return scene;
}

bool MainGame::init()
{
	if(!Layer::init())
	{
		return false;
	}
	 visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
    
	TMXTiledMap *map=TMXTiledMap::create("map/Chapter1Map35.tmx");
	this->addChild(map);
	TMXObjectGroup *group = map->getObjectGroup("Objects");
	ValueMap spawnPoint = group->getObject("hero");

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();


	ControlLayer* controlLayer1 = ControlLayer::create();
	controlLayer1->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(controlLayer1);

	Hero* hero1 = Hero::heroWithinLayer();
	hero1->setPosition(Vec2(200,200));
	this->addChild(hero1,10,123);

	return true;

}
