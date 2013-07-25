/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAY_CUBE_H_
#define _RAY_CUBE_H_
#include <vector>
#include "bessie/RayMantaPoint.h"
#include "include/SDL.h"
//#include "Draw4.h"

namespace ray3d {

class Cube {
public:
	Cube();
	virtual ~Cube() {}

	virtual int draw(SDL_Surface *screen);
	int translate(double xx, double yy, double zz);
	int rotate(double xx, double yy, double zz);
	int filltop(SDL_Surface *screen, Uint32 color);

protected:
	std::vector<Point> _points;

	

public:

};
}
#endif
