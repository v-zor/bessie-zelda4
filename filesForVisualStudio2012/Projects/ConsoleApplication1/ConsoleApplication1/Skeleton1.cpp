/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "Skeleton1.h"

namespace zelda
{
namespace main
{

Skeleton1::Skeleton1(int xx, int yy) : Enemy(xx,yy,32,32), _count1(100), _count2(200), _hitpoints(1)
{
/***
	addPictureDown("./Zelda/pics/DemonRed1-down-32x32.bmp");
	addPictureDown("./Zelda/pics/DemonRed2-down-32x32.bmp");

	addPictureUp("./Zelda/pics/DemonRed1-up-32x32.bmp");
	addPictureUp("./Zelda/pics/DemonRed2-up-32x32.bmp");
***/
	addPictureLeft("./Zelda/pics/Skeleton1-left-32x32.bmp");
	addPictureLeft("./Zelda/pics/Skeleton2-left-32x32.bmp");
	addPictureLeft("./Zelda/pics/Skeleton3-left-32x32.bmp");

	addPictureRight("./Zelda/pics/Skeleton1-right-32x32.bmp");
	addPictureRight("./Zelda/pics/Skeleton2-right-32x32.bmp");
	addPictureRight("./Zelda/pics/Skeleton3-right-32x32.bmp");
}

Skeleton1::~Skeleton1()
{}


void Skeleton1::updateanddraw(SDL_Surface **screen)
{

	if (_direction == "left")
		_x -= 1;
	else if (_direction == "right")
		_x += 1;

	if (_x > 200)
		_direction = "left";
	if (_x < 20)
		_direction = "right";

	blit(screen);

}

void Skeleton1::doCollision(GameEngine const& engine, int fight)
{
	if (fight) {
		_hitpoints -= 1;
	}
	//FIXME go mode
	//const_cast<Player&>(player).setHitPoints(const_cast<Player&>(player).getHitPoints() - 1);

}

}
}
