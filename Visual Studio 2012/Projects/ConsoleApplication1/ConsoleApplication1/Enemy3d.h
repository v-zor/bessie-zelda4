/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _ENEMY3D_H
#define _ENEMY3D_H

#include "Entity3d.h"
#include "Enemy.h"

#include <string>

namespace zelda
{
namespace main
{
class Player;

class Enemy3d : public Entity3d, public Enemy
{
public:
	Enemy3d(int xx, int yy, int zz, int ww, int hh, int dd);
	virtual ~Enemy3d() {}

protected:

};

}
}

#include "Player.h"

#endif