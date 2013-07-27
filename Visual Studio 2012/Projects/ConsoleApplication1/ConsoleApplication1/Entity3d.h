/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef ENTITY3D_H
#define ENTITY3D_H

#include"include/SDL.h"
#include<string>

#include<vector>

#include"Img.h"
#include"ImgSys.h"
#include "include/SDL.h"
#include "Entity.h"

namespace zelda
{
namespace main 
{

class GameEngine;
class Player3d;

using namespace std;

class Entity3d : public Entity
{
	public:
		Entity3d(int xx, int yy, int zz, int ww, int hh, int dd);
		virtual ~Entity3d() {}
		//NOTE Player3d
		virtual Entity* collision3d(Player3d const& player);

		inline int get_z() { return _z; }
		inline void set_z(int z) { _z = z; }
		inline int get_d() { return _d; }
		inline void set_d(int d) { _d = d; }

	private:
		//NOTE
		Entity3d(const zelda::image::Img& rhs);
		Entity3d operator=(const zelda::image::Img& rhs);
	protected:
		
		int _z,_d;
	public:
};
}
}

#endif



