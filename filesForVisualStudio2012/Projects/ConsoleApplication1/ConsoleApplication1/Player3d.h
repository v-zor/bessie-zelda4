/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef PLAYER3D_H
#define PLAYER3D_H

#include "include/SDL.h"
#include<string>
#include"Img.h"
#include"ImgSys.h"
#include "Enemy3d.h"
//#include "GameEngine.h"

namespace zelda
{
namespace main 
{
class GameEngine;
using namespace std;
class Player3d : public Player
{
	public:
		Player3d(int xx, int yy, int zz, int ww, int hh, int dd, int hp);
		virtual ~Player3d() {}
		//void blit(SDL_Surface **screen);
		int rotate();
		int translate(GameEngine const& gameengine);
		int translate(double xx, double yy, double zz);
		inline int get_z() { return _z; }
		inline void set_z(int z) { _z = z; }
		inline int get_d() { return _d; }
		inline void set_d(int d) { _d = d; }

	private:
		//NOTE
		Player3d(const zelda::image::Img& rhs);
		Player3d operator=(const zelda::image::Img& rhs);

	int _z,_d;
	double _theta1, _theta2, _theta3;

	public:
};
}
}

#endif
