/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaMatrix3.h"
#include <iostream>

namespace ray3d {
	
double Vector3::operator*(Vector3 const& v)
{

	return (const_cast<Vector3&>(v).get_x()*get_x() + const_cast<Vector3&>(v).get_y()*get_y()+const_cast<Vector3&>(v).get_z()*get_z());

}

Vector3 Vector3::operator+(Vector3 const& v)
{

	return Vector3(const_cast<Vector3&>(v).get_x()+get_x(), 
					const_cast<Vector3&>(v).get_y()+get_y(),
					const_cast<Vector3&>(v).get_z()+get_z());

}


Vector3 Vector3::translate(double t, double t2, double t3)
{

	return Vector3(get_x()*t, 
					get_y()*t2,
					get_z()*t3);

}

Matrix3::Matrix3(Vector3 const& row1, Vector3 const& row2, Vector3 const& row3)
{
	x11 = const_cast<Vector3&>(row1).get_x();
	x12 = const_cast<Vector3&>(row1).get_y();
	x13 = const_cast<Vector3&>(row1).get_z();
	x21 = const_cast<Vector3&>(row2).get_x();
	x22 = const_cast<Vector3&>(row2).get_y();
	x23 = const_cast<Vector3&>(row2).get_z();
	x31 = const_cast<Vector3&>(row3).get_x();
	x32 = const_cast<Vector3&>(row3).get_y();
	x33 = const_cast<Vector3&>(row3).get_z();
}

Matrix3 Matrix3::operator*(Matrix3 const& m)
{
//	if (m == *this)
//		return *this;
	//compiler optimized	
	return Matrix3(const_cast<Matrix3&>(m).get_x11()*get_x11()+
			const_cast<Matrix3&>(m).get_x12()*get_x21()+
			const_cast<Matrix3&>(m).get_x13()*get_x31(),
			const_cast<Matrix3&>(m).get_x11()*get_x21()+
			const_cast<Matrix3&>(m).get_x12()*get_x22()+
			const_cast<Matrix3&>(m).get_x13()*get_x23(),
			const_cast<Matrix3&>(m).get_x11()*get_x31()+
			const_cast<Matrix3&>(m).get_x12()*get_x32()+
			const_cast<Matrix3&>(m).get_x13()*get_x33(),
			const_cast<Matrix3&>(m).get_x21()*get_x11()+
			const_cast<Matrix3&>(m).get_x22()*get_x21()+
			const_cast<Matrix3&>(m).get_x23()*get_x31(),
			const_cast<Matrix3&>(m).get_x21()*get_x21()+
			const_cast<Matrix3&>(m).get_x22()*get_x22()+
			const_cast<Matrix3&>(m).get_x23()*get_x23(),
			const_cast<Matrix3&>(m).get_x21()*get_x31()+
			const_cast<Matrix3&>(m).get_x22()*get_x32()+
			const_cast<Matrix3&>(m).get_x23()*get_x33(),
			const_cast<Matrix3&>(m).get_x31()*get_x11()+
			const_cast<Matrix3&>(m).get_x32()*get_x21()+
			const_cast<Matrix3&>(m).get_x33()*get_x31(),
			const_cast<Matrix3&>(m).get_x31()*get_x21()+
			const_cast<Matrix3&>(m).get_x32()*get_x22()+
			const_cast<Matrix3&>(m).get_x33()*get_x23(),
			const_cast<Matrix3&>(m).get_x31()*get_x31()+
			const_cast<Matrix3&>(m).get_x32()*get_x32()+
			const_cast<Matrix3&>(m).get_x33()*get_x33());
}

Vector3 Matrix3::operator*(Vector3 const& v)
{
	return Vector3(
			get_x11()*const_cast<Vector3&>(v).get_x()+
			get_x12()*const_cast<Vector3&>(v).get_y()+
			get_x13()*const_cast<Vector3&>(v).get_z(),
			get_x21()*const_cast<Vector3&>(v).get_x()+
			get_x22()*const_cast<Vector3&>(v).get_y()+
			get_x23()*const_cast<Vector3&>(v).get_z(),
			get_x31()*const_cast<Vector3&>(v).get_x()+
			get_x32()*const_cast<Vector3&>(v).get_y()+
			get_x33()*const_cast<Vector3&>(v).get_z());

}
} //namespace ray3d
