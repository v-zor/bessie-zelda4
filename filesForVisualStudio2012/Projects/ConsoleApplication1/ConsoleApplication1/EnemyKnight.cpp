/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "EnemyKnight.h"

namespace zelda
{
namespace main
{

EnemyKnight::EnemyKnight(int xx, int yy) : Enemy(xx,yy,32,32), _count1(100), _count2(200)
{

	addPictureDown("./Zelda/pics/demon1-down-32x32.bmp");
	addPictureDown("./Zelda/pics/demon2-down-32x32.bmp");

	addPictureUp("./Zelda/pics/demon1-up-32x32.bmp");
	addPictureUp("./Zelda/pics/demon2-up-32x32.bmp");

	addPictureLeft("./Zelda/pics/demon1-left-32x32.bmp");
	addPictureLeft("./Zelda/pics/demon2-left-32x32.bmp");

	addPictureRight("./Zelda/pics/demon1-right-32x32.bmp");
	addPictureRight("./Zelda/pics/demon2-right-32x32.bmp");	
}

EnemyKnight::~EnemyKnight()
{}


void EnemyKnight::updateanddraw(SDL_Surface **screen)
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

void EnemyKnight::doCollision(GameEngine const& engine, int fight)
{
	//FIXME god mode
	//const_cast<Player&>(player).setHitPoints(const_cast<Player&>(player).getHitPoints() - 1);

}

}
}
