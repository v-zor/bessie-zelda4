/*
 Copyright (C) Johan Ceuppens 2011-2012
*/

#include "Wall.h"
#include "Player.h"

namespace zelda
{
namespace main 
{
using namespace std;

Wall::Wall(int xx, int yy, int ww, int hh) : Entity(xx,yy,ww,hh)
{}

Wall::~Wall() {}


Entity* Wall::collision(Player const& player)
{
	int xx = const_cast<Player&>(player).get_x();
	int yy = const_cast<Player&>(player).get_y();
	int ww = const_cast<Player&>(player).get_w();
	int hh = const_cast<Player&>(player).get_h();
	if (xx > _x && xx < _x + _w && yy > _y && yy < _y + _h)
		return (this);
	else
		return (Entity *)0;
	
}

void Wall::doCollision(GameEngine const& engine, int fight)
{/*empty*/}

}
}

