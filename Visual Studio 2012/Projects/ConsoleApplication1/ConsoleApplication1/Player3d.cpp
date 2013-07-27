/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include"Player3d.h"
#include "bessie/RayMantaMatrix3.h"
//#include "../RayMantaEngine.h"
#include "bessie/RayMantaPoint.h"

#include "gameengine.h"

namespace zelda
{
namespace main 
{

using namespace std;

Player3d::Player3d(int xx, int yy, int zz, int ww, int hh, int dd, int hp) : Player(xx,yy,32,32,hp), _z(zz),_d(dd)
{

	_theta1 = 3.14;//sqrt(2)/2;////2.5;
	_theta2 = 0;//sqrt(2)/2;////2.5;
	_theta3 = 0.70710678;//====sqrt(2)/2;//3.14;///2.5;
	
}

int Player3d::translate(GameEngine const& gameengine)
{

	/*FIX ray3d::Point thisp(get_x(),get_y(),get_z());

	thisp+=ray3d::Point(const_cast<GameEngine&>(gameengine).get_transx(),
					const_cast<GameEngine&>(gameengine).get_transy(),0);
		
	set_x(thisp.get_x());
	set_y(thisp.get_y());
	set_z(thisp.get_z());
	*/
	return 0;
}

int Player3d::translate(double xx, double yy, double zz)
{

	ray3d::Point thisp(get_x(),get_y(),get_z());

	thisp+=ray3d::Point(xx,yy,zz);
		
	set_x(thisp.get_x());
	set_y(thisp.get_y());
	set_z(thisp.get_z());
	
	return 0;
}

int Player3d::rotate()//double xx, double yy, double zz)
{

	//translation from begin coords after rotation
	//int oldx = get_x();
	//int oldy = get_y();
	//int oldz = get_z();


/*FIX	ray3d::Matrix3 rotmx = ray3d::rotatex(_theta1);
	ray3d::Matrix3 rotmy = ray3d::rotatey(_theta2);
    ray3d::Matrix3 rotmz = ray3d::rotatez(_theta3);
	

	ray3d::Vector3 prot(get_x(), get_y(), get_z());

	prot = rotmz*prot;
	prot = rotmy*prot;
	prot = rotmx*prot;

	set_x(prot.get_x());
	set_y(prot.get_y());
	set_z(prot.get_z());
*/
	//set_x(get_x()+oldx);
	//set_y(get_y()+oldy);
	//set_z(get_z()+oldz);

	return 0;
}

}
}
