/*
 Copyright (C) Johan Ceuppens 2011
*/

#include<fstream>
#include "RayMantaSphereModel.h"
#include<cstdlib>
#include "Draw.h"
#include "Draw2.h"

namespace ray3d {	

int SphereModel::drawpoints(SDL_Surface *screen)
{
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {
		int x1 = (*vi).get_x();
		int y1 = (*vi).get_y();
		putpixel(screen, x1,y1,0xff);

	}
	return 0;
}


int SphereModel::generatesphere(SDL_Surface *screen, int ii, int jj, int kk)
{

  // sphere init
  double r = ii;//NOTE
  Point center(ii,jj,kk);
  int xx,yy,zz;
  //draw sphere
  for (zz = -ii; zz< ii; zz++) {
  for (xx = -jj; xx < jj; xx++) {
  for (yy = -kk; yy < kk; yy++) {
	Point p(xx,yy,zz);
	if (xx*xx  + yy*yy + zz*zz <= r*r) {
		int txx = xx + center.get_x();
		int tyy = yy + center.get_y();
		int tzz = zz + center.get_z();
  		//putpixel(screen, txx,tyy,0xff);
		_points.push_back(p);
	}
  }
  }
  }

  //draw sphere
/*
  for (zz = -1; zz< 1; zz++) {
  for (xx = -100; xx < 100; xx++) {
  for (yy = -100; yy < 100; yy++) {
      	GC gc = XCreateGC(dpy, w, 0, NIL);
	Point p(xx,yy,zz);
	if (xx*xx  + yy*yy + zz*zz <= r*r) {
		int txx = xx + center.get_x();
		int tyy = yy + center.get_y();
		int tzz = zz + center.get_z();
  		XDrawLine(dpy, w, gc, txx,tyy,txx,tyy);
	}
  }
  }
  }
*/
  return 0;
}

int SphereModel::raycast(SDL_Surface *screen)
{

  #define NIL (0)

  std::vector<Point> spherepoints;
  double r = 100;
  Point center(100,100,100);
  int xx, yy, zz;

  for (zz = -100; zz< 200; zz++) {
  for (xx = -100; xx < 800; xx++) {
  for (yy = -100; yy < 600; yy++) {

 	//Point s(xx*10,yy*10,zz*10);
  	Point s(xx,yy,zz);
  	Point v = s - center; 
  	Point d(1,1,0);
  	//double t = (2*v*d + sqrt(2*v*d-4(v*v-r*r))/2 
  	double discr = (v*d)*(v*d) - (v*v - r*r);
  	int t1 = - (v*d) - sqrt((v*d)*(v*d) - (v*v - r*r));
  	int t2 = - (v*d) + sqrt((v*d)*(v*d) - (v*v - r*r));

	_points.push_back(Point(t1,t2,1));
	_points.push_back(Point(t2,t1,1));
	//FIXME luminosity with proximity between t1 and t2
//  	if (discr >= 0) 
	{
		int xxx = 0;
  		drawline(screen, &xxx,&xxx,&t1,&t2,0xff);//FIXME t1 0
  		drawline(screen, &xxx,&xxx,&t2,&t1,0xff);//FIXME t1 0
	}

  }	
  }
  }
return 0;
}

int SphereModel::raytrace(SDL_Surface *screen, Point const& p)
{

  
	int k = 0;
  for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++,k++ ) {
	//normalize

	Point N(0,const_cast<Point&>(p).get_y(),0);
	Point L(p);
	
	double d = 0.1;

	N.normalize();
	L.normalize();

	Point NL(N-L);	
	double A = NL.dist(N);
	double B = NL.dist(L);
	//now sin(alpha) ~= alpha
	double alpha = 0;
	alpha = B*1/A; 

	double inner = N*L;
	int convolution = inner * cos(alpha);

	putpixel(screen,
			const_cast<Point&>(p).get_x(),
			const_cast<Point&>(p).get_y(),
			0xff);
	//FIXME modify color
  }	
	return 0;
}

int SphereModel::raytrace2(SDL_Surface *screen, Point const& p)
{

  generatesphere(screen,100,100,100); 
	return 0;
}
int SphereModel::dithersunray(SDL_Surface *screen)
{
  int xx,yy,zz;
  double r = 100;
  Point center(100,100,100);
  for (zz = 0; zz< 200; zz++) {
  for (xx = 0; xx < 200; xx++) {
  for (yy = 0; yy < 200; yy++) {
  	//Point s(xx*10,yy*10,zz*10);
  	Point s(xx,yy,zz);
  	Point v = s - center; 
  	Point d(1,1,0);
  	//double t = (2*v*d + sqrt(2*v*d-4(v*v-r*r))/2 
  	double discr = (v*d)*(v*d) - (v*v - r*r);
  	int t1 = - (v*d) - sqrt((v*d)*(v*d) - (v*v - r*r));
  	int t2 = - (v*d) + sqrt((v*d)*(v*d) - (v*v - r*r));

	_points.push_back(Point(t1,t2,1));
	_points.push_back(Point(t2,t1,1));
	//FIXME luminosity with proximity between t1 and t2
  	//if (discr >= 0) 
	{
      	int xxx = 0;
  		drawline(screen, &xxx,&xxx,&t1,&t2,0xff);//FIXME t1 0
  		drawline(screen, &xxx,&xxx,&t2,&t1,0xff);//FIXME t1 0
	}
}}}
//sleep(10);
  return 0;
}

int SphereModel::drawsunray(SDL_Surface *screen)
{
  for (int i = 0; i < _points.size(); i++) {
  
	double d = Point(0,0,0).dist(_points[i]);
	int x1 = _points[i].get_x();
	int y1 = _points[i].get_y();
	int x2 = _points[i].get_x();
	int y2 = _points[i].get_y();
//	if (d < 10)
	drawline(screen, &x1,&y1,&x2,&y2,0xff);	
//	else
//	XDrawLine(*dpy,*w,gc, x1,y1,x2,y2);	
  }
	return 0; 
}

} // namespace ray3d

