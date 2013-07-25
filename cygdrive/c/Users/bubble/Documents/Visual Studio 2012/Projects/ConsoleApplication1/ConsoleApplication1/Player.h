/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "include/SDL.h"
#include<string>
#include"Img.h"
#include"ImgSys.h"
#include "Enemy.h"

namespace zelda
{
namespace main 
{

using namespace std;
class Player : public Enemy
{
	public:
		Player(int xx, int yy, int ww, int hh, int hp);
		virtual ~Player() {}
		//void blit(SDL_Surface **screen);

		void setHitPoints (int hp);
		int getHitPoints();

	private:
		//NOTE
		Player(const zelda::image::Img& rhs);
		Player operator=(const zelda::image::Img& rhs);

		//SDL_Surface *_surface;
		//int _x,_y,_w,_h;
		unsigned long _hitpoints;
	public:
};
}
}

#endif
