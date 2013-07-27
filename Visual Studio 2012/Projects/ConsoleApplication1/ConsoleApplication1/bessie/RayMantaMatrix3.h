/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYMANTA_MATRIX_3_H_
#define _RAYMANTA_MATRIX_3_H_

#include "RayMantaPoint.h" 
#include "../include/SDL.h"

namespace ray3d {

class Vector3 : public Point
{
public:
	Vector3(){}
	Vector3(double xx, double yy, double zz) : Point(xx,yy,zz,0xff) {}//FIXME1 default color
	//not applicable Vector3(double xx, double yy, double zz, Uint32 cc) : Point(xx,yy,zz,cc) {}
	virtual ~Vector3() {}
	Vector3(Vector3 const& v) { 
		x = const_cast<Vector3&>(v).get_x(); y = const_cast<Vector3&>(v).get_y(); y = const_cast<Vector3&>(v).get_z(); }

protected:

public:
	Vector3 operator()(double const& t) { x *= t; y *= t; y *= t; return *this; }
	double operator*(Vector3 const& v);
	Vector3 Vector3::operator+(Vector3 const& v);
	Vector3 Vector3::translate(double t, double t2, double t3);
	Vector3 operator=(Vector3 const& v) { 
		x = const_cast<Vector3&>(v).get_x(); y = const_cast<Vector3&>(v).get_y(); y = const_cast<Vector3&>(v).get_z(); return *this; }
};

class Matrix3 {

public:
	Matrix3() {}
	Matrix3(Vector3 const& row1, Vector3 const& row2, Vector3 const& row3); 
	virtual ~Matrix3() {}

	Matrix3(double xx11,double xx12,double xx13,double xx21,double xx22,double xx23,double xx31,double xx32, double xx33) 
	: x11(xx11),
	  x12(xx12),
	  x13(xx13),
	  x21(xx21),
	  x22(xx22),
	  x23(xx23),
	  x31(xx31),
	  x32(xx32),
	  x33(xx33)
	{}

	double get_x11() { return x11; }
	double get_x12() { return x12; }
	double get_x13() { return x13; }
	double get_x21() { return x21; }
	double get_x22() { return x22; }
	double get_x23() { return x23; }
	double get_x31() { return x31; }
	double get_x32() { return x32; }
	double get_x33() { return x33; }

protected:
	double x11,x12,x13,x21,x22,x23,x31,x32,x33;
public:
	Matrix3 operator*(Matrix3 const& m);
	Vector3 operator*(Vector3 const& v);
};

} // namespace ray3d

#endif
