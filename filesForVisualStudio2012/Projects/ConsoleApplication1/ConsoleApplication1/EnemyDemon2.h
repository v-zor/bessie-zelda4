/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _ENEMYDEMON2_H
#define _ENEMYDEMON2_H

#include "Enemy.h"

namespace zelda
{
namespace main
{

class EnemyDemonBlue : public Enemy
{
public:
	EnemyDemonBlue(int xx, int yy);
	virtual ~EnemyDemonBlue();
	
	virtual void updateanddraw(SDL_Surface **screen);
	virtual void doCollision(GameEngine const& engine, int fight);
	int translate(double xx, double yy);

protected:
	int _count1, _count2;
	unsigned long _hitpoints;
	double _leftstop, _rightstop;
};

}
}

#endif