#include "Cube.h"
#include "bessie/Draw.h"
#include "bessie/Draw2.h"
#include "bessie/Draw4.h"

#include "bessie/RayMantaMatrix3.h"
#include "bessie/RayMantaEngine.h"
#include <vector>
#include "Windows.h"

namespace ray3d {

Cube::Cube()
{
	//front square
	_points.push_back(Point(0,32,0));
	_points.push_back(Point(32,32,0));
	_points.push_back(Point(32,32,32));
	_points.push_back(Point(0,32,32));
	_points.push_back(Point(0,32,0));
	//back square
	_points.push_back(Point(0,0,0));
	_points.push_back(Point(32,0,0));
	_points.push_back(Point(32,0,32));
	_points.push_back(Point(0,0,32));
	_points.push_back(Point(0,0,0));

	_points.push_back(Point(0,32,0));
	_points.push_back(Point(0,32,32));
	_points.push_back(Point(0,0,32));
	_points.push_back(Point(0,0,0));
	_points.push_back(Point(0,32,0));
	
	_points.push_back(Point(32,32,0));
	_points.push_back(Point(32,0,0));
	_points.push_back(Point(32,0,32));
	_points.push_back(Point(32,32,32));
	_points.push_back(Point(32,32,0));


}

int Cube::draw(SDL_Surface *screen)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{

		int x1 = _points[i].get_x();
		int y1 = _points[i].get_y();
		int x2 = _points[i+1].get_x();
		int y2 = _points[i+1].get_y();

		drawline(screen,&x1,&y1,&x2,&y2, 0xff);
	}
	for (i = 5; i < 10; i++)
	{
		int x1 = _points[i].get_x();
		int y1 = _points[i].get_y();
		int x2 = _points[i+1].get_x();
		int y2 = _points[i+1].get_y();

		drawline(screen,&x1,&y1,&x2,&y2, 0xff);
	}
	for (i = 10; i < 15; i++)
	{
		int x1 = _points[i].get_x();
		int y1 = _points[i].get_y();
		int x2 = _points[i+1].get_x();
		int y2 = _points[i+1].get_y();

		drawline(screen,&x1,&y1,&x2,&y2, 0xff);
	}
	for (i = 15; i < 20; i++)
	{
		int x1 = _points[i].get_x();
		int y1 = _points[i].get_y();
		int x2 = _points[i+1].get_x();
		int y2 = _points[i+1].get_y();

		drawline(screen,&x1,&y1,&x2,&y2, 0xff);
	}

	return 0;

}

int Cube::translate(double xx, double yy, double zz)
{
	std::vector<Point> replacementvec;
	for (std::vector<Point>::iterator vi = _points.begin();
		vi != _points.end();
		vi++) {
			replacementvec.push_back((*vi)+=Point(xx,yy,zz));//((*vi).translate(xx,yy,zz));
		}

	_points = replacementvec;
	return 0;
}

int Cube::rotate(double xx, double yy, double zz)
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

int Cube::filltop(SDL_Surface *screen, Uint32 color)
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

}