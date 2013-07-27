/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include"Player.h"

namespace zelda
{
namespace main 
{

using namespace std;

Player::Player(int xx, int yy, int ww, int hh, int hp): Enemy(xx,yy,32,32), _hitpoints(hp) {
	
	addPictureDown("./Zelda/pics/player1-down-32x32.bmp");
	addPictureDown("./Zelda/pics/player2-down-32x32.bmp");
	//addPictureDown("./Zelda/pics/player3-down-32x32.bmp");
	//addPictureDown("./Zelda/pics/player4-down-32x32.bmp");
	addPictureUp("./Zelda/pics/player1-up-32x32.bmp");
	addPictureUp("./Zelda/pics/player2-up-32x32.bmp");

	addPictureLeft("./Zelda/pics/player1-left-32x32.bmp");
	addPictureLeft("./Zelda/pics/player2-left-32x32.bmp");

	addPictureRight("./Zelda/pics/player1-right-32x32.bmp");
	addPictureRight("./Zelda/pics/player2-right-32x32.bmp");


	addFightPictureDown("./Zelda/pics/player1-fightdown-32x32.bmp");
	//addFightPictureDown("./Zelda/pics/player2-fightdown-32x32.bmp");
	
	addFightPictureUp("./Zelda/pics/player1-fightup-32x32.bmp");
	//addFightPictureUp("./Zelda/pics/player2-fightup-32x32.bmp");

	addFightPictureLeft("./Zelda/pics/player1-fightleft-32x32.bmp");
	//addFightPictureLeft("./Zelda/pics/player2-fightleft-32x32.bmp");

	addFightPictureRight("./Zelda/pics/player1-fightright-32x32.bmp");
	//addFightPictureRight("./Zelda/pics/player2-fightright-32x32.bmp");

	_direction = "right";
}

/*
void Player::blit(SDL_Surface **screen)
{
	SDL_Rect rectangle;
	rectangle.x = _x;
	rectangle.y = _y;
	rectangle.w = _w;
	rectangle.h = _h;
	SDL_BlitSurface (_surface,NULL,*screen,&rectangle);
}
*/


void Player::setHitPoints (int hp)
{
	_hitpoints = hp;
}
		
int Player::getHitPoints()
{
	return _hitpoints;
}

}
}
