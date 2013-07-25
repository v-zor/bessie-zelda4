/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "EnemyDemon2.h"

namespace zelda
{
namespace main
{

EnemyDemonBlue::EnemyDemonBlue(int xx, int yy) : Enemy(xx,yy,32,32), _count1(100), _count2(200), _hitpoints(1), _leftstop(20), _rightstop(200)
{

	addPictureDown("./Zelda/pics/DemonBlue1-down-32x32.bmp");
	addPictureDown("./Zelda/pics/DemonBlue2-down-32x32.bmp");

	addPictureUp("./Zelda/pics/DemonBlue1-up-32x32.bmp");
	addPictureUp("./Zelda/pics/DemonBlue2-up-32x32.bmp");

	addPictureLeft("./Zelda/pics/DemonBlue1-left-32x32.bmp");
	addPictureLeft("./Zelda/pics/DemonBlue2-left-32x32.bmp");

	addPictureRight("./Zelda/pics/DemonBlue1-right-32x32.bmp");
	addPictureRight("./Zelda/pics/DemonBlue2-right-32x32.bmp");	
}

EnemyDemonBlue::~EnemyDemonBlue()
{}


void EnemyDemonBlue::updateanddraw(SDL_Surface **screen)
{

	if (_direction == "left")
		_x -= 1;
	else if (_direction == "right")
		_x += 1;

	if (_x > _rightstop)
		_direction = "left";
	if (_x < _leftstop)
		_direction = "right";

	blit(screen);

}

void EnemyDemonBlue::doCollision(GameEngine const& engine, int fight)
{
	if (fight) {
		_hitpoints -= 1;
	}

	//FIXME god mode
	//const_cast<Player&>(player).setHitPoints(const_cast<Player&>(player).getHitPoints() - 1);
}

int EnemyDemonBlue::translate(double xx, double yy)
{
	static_cast<Entity *>(this)->translate(xx,yy);
	_leftstop += xx;
	_rightstop += xx;
	
	return 0;
}

}
}
