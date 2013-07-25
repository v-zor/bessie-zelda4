/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _ENEMYKNIGHT_H
#define _ENEMYKNIGHT_H

#include "Enemy.h"

namespace zelda
{
namespace main
{
class GameEngine;

class EnemyKnight : public Enemy
{
public:
	EnemyKnight(int xx, int yy);
	virtual ~EnemyKnight();
	
	virtual void updateanddraw(SDL_Surface **screen);
	virtual void doCollision(GameEngine const& engine, int fight);

protected:
	int _count1, _count2;
};

}
}

#endif