/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _ENEMYSKELETON1_H
#define _ENEMYSKELETON1_H

#include "Enemy.h"

namespace zelda
{
namespace main
{

class Skeleton1 : public Enemy
{
public:
	Skeleton1(int xx, int yy);
	virtual ~Skeleton1();
	
	virtual void updateanddraw(SDL_Surface **screen);
	virtual void doCollision(GameEngine const& engine, int fight);

protected:
	int _count1, _count2;
	unsigned long _hitpoints;
};

}
}

#endif