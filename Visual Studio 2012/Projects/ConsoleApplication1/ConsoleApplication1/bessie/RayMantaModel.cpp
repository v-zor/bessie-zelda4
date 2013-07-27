/*
 Copyright (C) Johan Ceuppens 2011
*/

#include<fstream>

#include "../include/SDL.h"

#include "RayMantaModel.h"
#include<cstdlib>
//#include "Draw2.h"
#include "Draw.h"

namespace ray3d {	

#define VECTORSIZE (3)

int Model::filein(std::string const& filename)
{
	std::ifstream *ifs = new std::ifstream(filename.c_str());
	char *buf = new char[1024];//FIXME fiexed size
	char *buf2 = new char[1024];//FIXME fiexed size
	char *buf3 = new char[1024];//FIXME fiexed size
	char *buf4 = new char[1024];//FIXME fiexed size
	for (; !ifs->eof(); ) {
			(*ifs) >> buf;
			if (ifs->eof()) break;
			(*ifs) >> buf2;
			if (ifs->eof()) break;
			(*ifs) >> buf3;
			if (ifs->eof()) break;
			(*ifs) >> buf4;
			_points.push_back(Point(atof(buf),atof(buf2),atof(buf3),atof(buf4)));
	}

	return 0;
}

int Model::fileout(std::string const& filename)
{
	char buf[1024];
	std::ofstream *ofs = new std::ofstream(filename.c_str());
	for (int i = 0; i < _points.size(); i++) {
		sprintf(buf, "%e ", (double)(_points[i][0]));
		(*ofs) << buf; 
		sprintf(buf, "%e ", (double)(_points[i][1]));
		(*ofs) << buf; 
		sprintf(buf, "%e ", (double)(_points[i][2]));
		(*ofs) << buf; 
		sprintf(buf, "%e ", (double)(_points[i][3]));
		(*ofs) << buf; 
	}	
	return 0;
}

int Model::draw(SDL_Surface *screen)
{

	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {
		int x1 = (*vi).get_x();
		int y1 = (*vi).get_y();
		putpixel(screen, (*vi).get_y(),(*vi).get_x(),0xff);

	}
	return 0;
}


int Model::rotatex(Engine const& engine, double t)
{
	Matrix3 rotm(const_cast<Engine&>(engine).rotatex(t));
	std::vector <Point> retv;
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {

		retv.push_back(Point(rotm*static_cast<Vector3&>(*vi)));

	}
	_points = *&retv;
	return 0;
}
int Model::rotatey(Engine const& engine, double t)
{
	Matrix3 rotm(const_cast<Engine&>(engine).rotatey(t));
	std::vector <Point> retv;
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {

		retv.push_back(Point(rotm*static_cast<Vector3&>(*vi)));

	}
	_points = *&retv;
	return 0;
}
int Model::rotatez(Engine const& engine, double t)
{
	Matrix3 rotm(const_cast<Engine&>(engine).rotatez(t));
	std::vector <Point> retv;
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {

		retv.push_back(Point(rotm*static_cast<Vector3&>(*vi)));

	}
	_points = *&retv;
	return 0;
}
int Model::rotate(Engine const& engine, double t1, double t2, double t3)
{
	Matrix3 rotm(const_cast<Engine&>(engine).rotate(t1,t2,t3));
	std::vector <Point> retv;
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {

		retv.push_back(Point(rotm*static_cast<Vector3&>(*vi)));

	}
	_points = *&retv;
	return 0;
}
/*
int Model::raytrace(Display **dpy, Window *w)
{
}

int Model::dithersunray(Display **dpy, Window *w)
{
}

*/
} // namespace ray3d

