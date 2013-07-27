/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaPolygon.h"
#include "RayMantaMatrix3.h"
#include "RayMantaEngine.h"
#include "Draw2.h"
#include "Draw4.h"

namespace ray3d {

int Polygon::draw(SDL_Surface *screen)
{
	#define NIL (0)
	std::vector<Point>::iterator pi = _points.begin();
      
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {//FIXME _points.begin()++
		int x1 = (*vi).get_x();
		int y1 = (*vi).get_y();
		int x2 = (*pi).get_x();
		int y2 = (*pi).get_y();
		drawline(screen, &x1,&y1,&x2,&y2,0xff);
		pi = vi;
	}
	return 0;
}



/*
	*   /---/   <- 4side polygon
	*  /---/
	* e.g. :
	ray3d::Polygon poly;
	poly.add(ray3d::Point(x+transx,y+transy,0));
	poly.add(ray3d::Point(x+transx+32,y+transy,0));
	poly.add(ray3d::Point(x+transx+32,y+transy+32,0));
	poly.add(ray3d::Point(x+transx,y+transy+32,0));
	poly.add(ray3d::Point(x+transx,y+transy,0));
*/
int Polygon::fill4sidepolygon(SDL_Surface *screen, Uint32 color)
{
	#define NIL (0)
	//std::vector<Point>::iterator pi = _points.begin();
      
	//FIXME1
	//for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {//FIXME _points.begin()++
		int x1 = _points[0].get_x();//(*vi).get_x();
		int y1 = _points[0].get_y();//(*vi).get_y();
		int x2 = _points[1].get_x();//(*pi).get_x();
		int y2 = _points[1].get_y();//(*pi).get_y();
		int x3 = _points[2].get_x();//(*vi).get_x();
		int y3 = _points[2].get_y();//(*vi).get_y();
		int x4 = _points[3].get_x();//(*pi).get_x();
		int y4 = _points[3].get_y();//(*pi).get_y();
		linefillrec(screen, &x1,&y1,&x3,&y3,&x2,&y2,&x4,&y4,color);
		//drawline(screen, &x1,&y1,&x2,&y2,0xff);
		//pi = vi;
	//}
	return 0;
}


int Polygon::rotate(double xx, double yy, double zz)
{
	ray3d::Matrix3 rotmx = ray3d::rotatex(xx);
	ray3d::Matrix3 rotmy = ray3d::rotatey(yy);
    ray3d::Matrix3 rotmz = ray3d::rotatez(zz);


	std::vector<Point> replacementvec;
	for (std::vector<Point>::iterator vi = _points.begin();
		vi != _points.end();
		vi++) {

			ray3d::Vector3 prot((*vi).get_x(), (*vi).get_y(), (*vi).get_z());

			prot = rotmz*prot;
			prot = rotmy*prot;
			prot = rotmx*prot;

			replacementvec.push_back((*vi)+=Point(prot.get_x(),prot.get_y(),prot.get_z()));
		}
	_points = replacementvec;
	return 0;
}

}
