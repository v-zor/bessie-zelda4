/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYMODEL_H_
#define _RAYMODEL_H_
#include<string>
#include<vector>
#include "RayMantaPoint.h"
#include "RayMantaEngine.h"
#include "../include/SDL.h"

namespace ray3d {
// Model mixin class
//S = string class
//F = modelreader class
class Model {
public:
	Model () {}
	virtual ~Model() {}

	virtual int filein(std::string const& filename);
	virtual int fileout(std::string const& filename);

	int rotatex(Engine const& engine, double t);
	int rotatey(Engine const& engine, double t);
	int rotatez(Engine const& engine, double t);
	int rotate(Engine const& engine, double t1, double t2, double t3);

	virtual int draw(SDL_Surface *screen);
	virtual std::vector<Point> get_points() { return _points; }
	virtual void addpoint(Point p) { _points.push_back(p); }
	virtual void empty_points() { _points = std::vector<Point>(0);/* addpoint(Point(0,0,0));*//*FIXME (1)*/ }
	virtual void set_points(std::vector<Point> v) { _points = v; }
protected:
	std::vector<Point> _points;
	
};

}

#endif
