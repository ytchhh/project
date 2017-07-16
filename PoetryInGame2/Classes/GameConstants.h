#ifndef __GAME_CONSTANTS_H__
#define __GAME_CONSTANTS_H__

typedef enum {
	hdie =  0,//À¿Õˆ
	hnormal=1,//’˝≥£
	hleftJump=2,//œÚ◊ÛÃ¯
	hrightJump=5,
	hright=4,//œÚ”“∑ΩœÚ
	hleft=3,//
	hjump=6,//œÚ…œ∑ΩœÚ

} HeroDirection;//”¬ ø∑ΩœÚ

typedef enum
{
	kNone = 1,//ø…“‘Õ®––
	kWall,//«Ω
	kItem,//ŒÔ∆∑
	kDoor,//√≈
	khideblock,
	kbiqi
	
} CollisionType;//≈ˆ◊≤¿‡–Õ


//里面定义了这个游戏中所有会出现的动画的代号
typedef enum
{
	anormal=0,
	aLeftjump,
	arightjump,
	aDie ,//
	aLeft,//œÚ◊Û––◊ﬂ∂Øª≠
	aRight,//œÚ”“––◊ﬂ∂Øª≠
	aother,
	heroCry,
	victory,
	biqiSmile,
} AnimationKey;//∂Øª≠ƒ£∞Êº¸÷µ
typedef enum
{
	heronormalkey=0,
	heroleftJumpkey,
	herorightJumpkey,
	controlLeftkey ,//
	controlLeftPressedkey,
	controlRightkey,
	controlRightPressedkey,
	controlJumpkey,
	controlJumpPressedkey,
	whyBlockKey,
	firmBlockKey,
	goldCoinkey,
	failedboxkey,
	cryFramekey,
	onkey,
	offkey,
	bosskey,
}CCSpriteFrameKey;//CCSpriteFrameƒ£∞Êº¸÷µ
enum 
{
	kZMap = 0,//µÿÕºµƒzOrder
	kZNPC,
	kZTeleport,
	kZHero,//”¬ øæ´¡ÈµƒzOrder
	kZTip,//Ã· æ–≈œ¢µƒzOrder
};//GameLayer÷–∏˜≤ø∑÷µƒœ‘ æzOrderº∞tag

enum 
{
	kGameLayer = 0,
	kControlLayer,
	kFadeLayer,
};

enum{
	eSize = 50,
};
#endif
