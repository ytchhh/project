#ifndef _GAMECONSTANTS_H
#define _GAMECONSTANTS_H

#define Sprite_Size 35

typedef enum
{
	MoveLeft=1,
    MoveRight,
    Jump
}HeroDirection;

typedef enum
{
    KNone = 1,  //可以通行
    KWall,      //不可以通行 
    KWord,      //字
    KEvil      //怪物
}CollisionType;

#endif
