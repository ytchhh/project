#include "AppDelegate.h"
#include "Welcome.h"

USING_NS_CC;

AppDelegate::AppDelegate(){}
AppDelegate::~AppDelegate(){}

bool AppDelegate::applicationDidFinishLaunching()
{
    Director *director = Director::getInstance();
    auto glview = director -> getOpenGLView();
    if (!glview)
    {
        glview = GLViewImpl::create("Poetry"); 
        director -> setOpenGLView(glview);
    }

    director -> setDisplayStats(false);

    //director -> setAnimationInterval(1.0/80);

    Scene *fScene = Welcome::createScene();
    if (fScene == NULL)
    {
        log("welcome not create.");
        exit(1);
    }

    director -> runWithScene(fScene);
    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance() -> stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance() -> startAnimation();
}
