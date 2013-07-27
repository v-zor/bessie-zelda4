/*
 Copyright (C) Johan Ceuppens 2011-2012
*/

#include "Entity.h"

#include"include/SDL.h"

#include "bessie/RayMantaPoint.h"

#include<string>

#include<list>

#include"Img.h"
#include"ImgSys.h"

#include "player.h"

namespace zelda
{
namespace main 
{
using namespace std;

Entity::Entity(int xx, int yy, int ww, int hh)
{ _x = xx; _y = yy; _w = ww; _h = hh; _surfacesindex = 0; }

Entity::~Entity() {}

void Entity::moveLeft()
{
	_x += -1;
}

void Entity::moveRight()
{
	_x += 1;
}

void Entity::moveDown()
{
	_y += -1;
}

void Entity::moveUp()
{
	_y += 1;
}


void Entity::blit(SDL_Surface **screen)
{ 
	if (_surfacesindex >= _surfaces.size())
		_surfacesindex = 0;

	SDL_Rect rectangle;
	rectangle.x = _x;
	rectangle.y = _y;
	rectangle.w = _w;
	rectangle.h = _h;
	SDL_BlitSurface (_surfaces[_surfacesindex],NULL,*screen,&rectangle);

	_surfacesindex++;

}

void Entity::blitstatic(SDL_Surface **screen)
{ 

	SDL_Rect rectangle;
	rectangle.x = _x;
	rectangle.y = _y;
	rectangle.w = _w;
	rectangle.h = _h;
	SDL_BlitSurface (_surfaces[0],NULL,*screen,&rectangle);

}

void Entity::addPicture(std::string filename)
{ 
	SDL_Surface *surf = NULL; 
	zelda::image::ImgSys imgsys; 
	imgsys.load(filename, &surf); 
	_surfaces.push_back(surf);
}

void Entity::updateanddraw(SDL_Surface **screen)
{/* empty */}

Entity* Entity::collision(Player const& player)
{
	//NOTE1
	if (const_cast<Player *>(&player)->get_x() < get_x() && 
		const_cast<Player *>(&player)->get_y() > get_x() + get_w() &&
		const_cast<Player *>(&player)->get_y() < get_y() && 
		const_cast<Player *>(&player)->get_y() > get_y() + get_h())
		return this;
	else
		return (Entity *)0;
}

/*FIXME
Entity* Entity::collision3d(Player const& player)
{
	//NOTE1
	if (const_cast<Player *>(&player)->get_x() < get_x() && 
		const_cast<Player *>(&player)->get_x() > get_x() + get_w() &&
		const_cast<Player *>(&player)->get_y() < get_y() && 
		const_cast<Player *>(&player)->get_y() > get_y() + get_h()
		const_cast<Player *>(&player)->get_z() < get_z() && 
		const_cast<Player *>(&player)->get_z() > get_z() + get_d()
		
		)
		return this;
	else
		return (Entity *)0;
}*/

void Entity::doCollision(GameEngine const& engine, int fight)
{/*empty*/}

int Entity::translate(double xx, double yy)
{

	ray3d::Point thisp(get_x(),get_y(),0);

	thisp+=ray3d::Point(xx,yy,0);
		
	set_x(thisp.get_x());
	set_y(thisp.get_y());
	//set_z(0);
	
	return 0;
}

}
}

