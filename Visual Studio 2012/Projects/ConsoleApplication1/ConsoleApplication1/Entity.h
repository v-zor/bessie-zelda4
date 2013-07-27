/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef ENTITY_H
#define ENTITY_H

#include"include/SDL.h"
#include<string>

#include<vector>

#include"Img.h"
#include"ImgSys.h"
//#include "Player.h"
//#include "../RayMantaPoint.h"

namespace zelda
{
namespace main 
{

class GameEngine;
class Player;

using namespace std;

class Entity 
{
	public:
		Entity(int xx, int yy, int ww, int hh);
		virtual ~Entity();
		virtual void moveLeft();
		virtual void moveRight();
		virtual void moveDown();
		virtual void moveUp();
		virtual void blit(SDL_Surface **screen);
		virtual void blitstatic(SDL_Surface **screen);
		void addPicture(std::string filename);

		virtual void updateanddraw(SDL_Surface **screen);
		virtual Entity* collision(Player const& player);

		inline int get_x() { return _x; }
		inline int get_y() { return _y; }
		inline int get_w() { return _w; }
		inline int get_h() { return _h; }
		inline void set_x(int x) { _x = x; }
		inline void set_y(int y) { _y = y; }
		inline void set_w(int w) { _w = w; }
		inline void set_h(int h) { _h = h; }

		virtual void doCollision(GameEngine const& engine, int fight);
		virtual int translate(double xx, double yy);

	private:
		//NOTE
		Entity(const zelda::image::Img& rhs);
		Entity operator=(const zelda::image::Img& rhs);
	protected:
		std::vector<SDL_Surface *> _surfaces;//down images in Enemy.cpp
		int _surfacesindex;
		int _x,_y,_w,_h;
	public:
};
}
}

#endif



