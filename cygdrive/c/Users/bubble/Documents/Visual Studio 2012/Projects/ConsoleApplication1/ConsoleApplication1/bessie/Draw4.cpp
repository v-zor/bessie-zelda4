#include "Draw4.h"
#include "Draw2.h"
#include "Draw.h"
#include<iostream>
#include<cmath>

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int min(int x, int y)
{
	if (x <y)
		return x;
	else
		return y;
}

/*
* left to right edge scanline algo
*/
void linefill(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2,int *x3, int *y3, int *x4, int *y4, Uint32 color)
{

	if ((*x1 >= 640 || *x2 >= 640 || *y1 >= 480 || *y2 >= 480)
		|| 
		(*x1 >= 640 || *x2 >= 640 || *y1 >= 480 || *y2 >= 480)
		||
		(*x3 >= 640 || *x4 >= 640 || *y3 >= 480 || *y4 >= 480)
		|| 
		(*x3 >= 640 || *x4 >= 640 || *y3 >= 480 || *y4 >= 480)) 
	{
		//std::cout<<"drawline4 : pixel offset out of range"<<std::endl;
		return;
	}


	int xmax1 = max(*x1,*x2);
	int xmax2 = max(*x3,*x4);
	int xmax = max(xmax1,xmax2);
	int xmin1 = min(*x1,*x2);
	int xmin2 = min(*x3,*x4);
	int xmin = min(xmin1,xmin2);

	int ymax1 = max(*y1,*y2);
	int ymax2 = max(*y3,*y4);
	int ymax = max(ymax1,ymax2);
	int ymin1 = min(*y1,*y2);
	int ymin2 = min(*y3,*y4);
	int ymin = min(ymin1,ymin2);

	int numerator = xmax - xmin;
	int denominator = ymax - ymin;
	int increment = denominator;
	int y;
	int x = xmin;
	for (y = ymin; y <= ymax; y++) {
		for (x = xmin; x <= xmax; x++) {

			putpixel(surf, x,y,0xffff);
		//increment += numerator;
		//if (increment > denominator) {
		//	x++;
		//	increment -= denominator;
		}
	}

}



void linefillrec(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2,int *x3, int *y3, int *x4, int *y4, Uint32 color)
{
  int deltax = *x2-*x1;
  int deltay = *y2-*y1;
  
  int xnum = 0;
  int ynum = 0;

  //assert("Needs to be fixed" && deltax != 0);//--fixme
  if (deltax == 0) {
    //std::cout << "EntityFactory deltax=0 - needs debugging"<<std::endl;
    //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, 0, 1, 0, 0, new ShootVerticalFunc());
    drawVerticalFunc(x1,y1,&xnum,&ynum,deltax,deltay,1);
  }
  
	
			

  if (deltax >= 0 && deltay >= 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //      for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant1Func());
	   while ( *x2 >= *x1 ) {
				drawline1Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline1Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant2Func());
      //for (y = y1; y <= y2; y++)
	   while ( *y2 >= *y1 ) {
				drawline2Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline2Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
    }
  }
  else if (deltax < 0 && deltay >= 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = -deltax / 2;
      //      for (x = x1; x >= x2; x--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant3Func());
		while ( *x2 >= *x1 ) {
				drawline3Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline3Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
	
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //for (y = y1; y <= y2; y++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant4Func());
		while ( *y2 >= *y1 ) {
				drawline4Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline4Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
	}
  }
  else if (deltax >= 0 && deltay < 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant5Func());
      while ( *x2 >= *x1 ) {
				drawline5Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline5Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
    }
    else {
      //x = x1;
      xnum = -deltay / 2;
      //for (y = y1; y >= y2; y--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant6Func());
	while ( *y2 >= *y1 ) {
				drawline6Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline6Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
    }
  }
  else if (deltax < 0 && deltay <0) {
     if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
       // y = y1;
       ynum = -deltax / 2;
       //for (x = x1; x >= x2; x--)
       //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant7Func());
       while ( *x2 >= *x1 ) {
				drawline7Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline7Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
     }
     else {
       //x = x1;
       xnum = -deltay / 2;
       //for (y = y1; y >= y2; y--)
       //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant8Func());
     while ( *y2 >= *y1 ) {
				drawline8Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				drawline8Func(x3,y3,&xnum,&ynum,deltax,deltay,1);
				linefill(surf, x1,y1,x2,y2,x3,y3,x4,y4,0x0000ff);//putpixel(surf, *x1,*y1,color);
			}
	 }
  }
}


