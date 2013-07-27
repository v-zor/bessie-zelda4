/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYSPHEREMODEL_H_
#define _RAYSPHEREMODEL_H_

#include "../include/SDL.h"
#include<vector>
#include "RayMantaPoint.h"
//#include "RayMantaEngine.h"
#include "RayMantaModel.h"

namespace ray3d {

//S = string class
//F = modelreader class
class SphereModel : public Model {
public:
	SphereModel () : Model() {}
	virtual ~SphereModel() {}

	int generatesphere(SDL_Surface *screen, int ii, int jj, int kk);
	virtual int raycast(SDL_Surface *screen);
	virtual int raytrace(SDL_Surface *screen, Point const& p);
	virtual int raytrace2(SDL_Surface *screen, Point const& p);
	virtual int dithersunray(SDL_Surface *screen);
	virtual int drawsunray(SDL_Surface *screen);

	virtual int drawpoints(SDL_Surface *screen);

protected: 
	//NOTE : The base class contains identical _points vector
	// Thisi e.g. is for circumference and Volume 
	//std::vector<Point> _spherepoints;
};

}

#endif
