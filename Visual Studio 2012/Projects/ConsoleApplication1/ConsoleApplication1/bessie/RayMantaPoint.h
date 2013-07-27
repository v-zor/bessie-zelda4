/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _POINT_H_
#define _POINT_H_
#include<cmath>
#include<iostream>
#include "../include/SDL.h"
namespace ray3d {

class Point
{
public:
	Point(){}
	Point(double xx, double yy, double zz, Uint32 color) : x(xx),y(yy),z(zz),c(color) {}
	Point(double xx, double yy, double zz) : x(xx),y(yy),z(zz),c(0xff) {}
	virtual ~Point(){}

	double operator*(Point const&p) { return (const_cast<Point&>(p).x*x+const_cast<Point&>(p).y*y+const_cast<Point&>(p).z*z); }
	//double operator*(int const&p) { return (const_cast<Point&>(p).x*+const_cast<Point&>(p).y*y+const_cast<Point&>(p).z*z); }
	Point operator-(Point const&p) { return Point(const_cast<Point&>(p).x-x,const_cast<Point&>(p).y-y,const_cast<Point&>(p).z-z); }
	Point operator+(Point const&p) { return Point(const_cast<Point&>(p).x+x,const_cast<Point&>(p).y+y,const_cast<Point&>(p).z+z); }
	Point operator+=(Point const&p)
	{
		set_x(const_cast<Point&>(p).get_x()+get_x()); 
		set_y(const_cast<Point&>(p).get_y()+get_y());
		set_z(const_cast<Point&>(p).get_z()+get_z());
		return (*this);
	}
	bool operator==(Point const&p) { return (x==const_cast<Point&>(p).x&&y==const_cast<Point&>(p).y&&z==const_cast<Point&>(p).z); }
	Point scale(int i) { x*=i; y*=i; z*=i; return *this; }
	Point scalex(int i) { x*=i; return *this; }
	Point scaley(int i) { y*=i; return *this; }
	Point scalez(int i) { z*=i; return *this; }
	Point operator=(Point const&p) { return Point(const_cast<Point&>(p).x+x,const_cast<Point&>(p).y+y,const_cast<Point&>(p).z+z); }
	double operator[](int index) { if (index == 0) return x; if (index == 1) return y; if (index == 2) return z; if (index == 3) return c; if (index > 3) return -1;  }

	Point operator()(double const& t) { x *= t; y *= t; z *= t; return *this; }
	double get_x() {return x;}
	double get_y() {return y;}
	double get_z() {return z;}
	double get_c() {return c;}//return color
	void set_x(double xx) { x = xx;}
	void set_y(double yy) { y = yy;}
	void set_z(double zz) { z = zz;}
	void set_c(Uint32 cc) {  c = cc;}
	double get_color() {return c;}//return color
	double dist(Point const& p)
	{
		return (sqrt((get_x()-const_cast<Point&>(p).get_x()) * 
				(get_x()-const_cast<Point&>(p).get_x()) +
				(get_y()-const_cast<Point&>(p).get_y()) *
				(get_z()-const_cast<Point&>(p).get_z()) +
				(get_z()-const_cast<Point&>(p).get_z())));
	}
	int sqr(Point const& p)
	{
		x = get_x()*const_cast<Point&>(p).get_x(); y = get_y()*const_cast<Point&>(p).get_y(); z = get_z()*const_cast<Point&>(p).get_z();
		return 0;
	}
	Point normalize() { 
		double xx = x; 
		xx /= x*x+y*y+z*z;
		double yy = y; 
		yy /= x*x+y*y+z*z;
		double zz = z; 
		zz /= x*x+y*y+z*z;
		x = xx; y = yy; z = zz;

		return Point(xx,yy,zz);//FIXME
	}
protected:
	double x,y,z;
	Uint32 c;//color
};
}
#endif

