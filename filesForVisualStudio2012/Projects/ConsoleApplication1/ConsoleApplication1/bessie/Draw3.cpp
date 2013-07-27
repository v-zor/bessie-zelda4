#include "Draw3.h"
#include "Draw.h"
#include<iostream>
#include<cmath>
/*
NOTE: make sure putpixel does not go beyond the surf surf
*/

/*
NOTE: x2 must be bigger than x1 !
*/

void swap3(int *x1, int *x2) {
	int *tempx = x1;
	*x1 = *x2;
	*x2 = *tempx;
}

void drawline3(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color)
{
	//FIXME1
	if ((*x1 >= 640 || *x2 >= 640 || *y1 >= 480 || *y2 >= 480)
		||
		(*x1 <= 0 || *x2 <= 0 || *y1 <= 0 || *y2 <= 0))
	{
		std::cout<<"drawline3 : pixel offset out of range"<<std::endl;
		return;
	}

  int w = 20, h = 20;//--fixme width height constant

 
  int deltax = *x2-*x1;
  int deltay = *y2-*y1;
  
  int xnum = 0;
  int ynum = 0;

  //assert("Needs to be fixed" && deltax != 0);//--fixme
  if (deltax == 0) {
    std::cout << "EntityFactory deltax=0 - needs debugging"<<std::endl;
    //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, 0, 1, 0, 0, new ShootVerticalFunc());
    //drawVertical3Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
	return;//FIXME1
  }
  
	
			

  if (x1 < x2 && y2 < y1) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //      for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant1Func());
	   while ( *x2 >= *x1 ) {
				drawline31Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant2Func());
      //for (y = y1; y <= y2; y++)
	   while ( *y2 >= *y1 ) {
				drawline32Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
    }
  }
  else if (x2 < x1 && y1 < y2) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = -deltax / 2;
      //      for (x = x1; x >= x2; x--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant3Func());
		while ( *x2 >= *x1 ) {
				drawline33Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	
	}
    else {
    //x = x1;
      xnum = deltay / 2;
      //for (y = y1; y <= y2; y++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant4Func());
		while ( *y2 >= *y1 ) {
				drawline34Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	}
  }
  else if (x1 > x2 && y1 > y2) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant5Func());
      while ( *x2 >= *x1 ) {
				drawline35Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
    }
    else {
      //x = x1;
      xnum = -deltay / 2;
      //for (y = y1; y >= y2; y--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant6Func());
	while ( *y2 >= *y1 ) {
				drawline36Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
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
				drawline37Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
     }
     else {
       //x = x1;
       xnum = -deltay / 2;
       //for (y = y1; y >= y2; y--)
       //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant8Func());
     while ( *y2 >= *y1 ) {
				drawline37Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	 }
  }
}

void drawline3old(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color)
{

	int xnum = 0;
	int ynum = 0;

	int deltax = (*x2 - *x1);
	int deltay = (*y2 - *y1);

	if (deltax == 0) {
		std::cout << "impossible line3 rico" << std::endl;
		return;
	}
	
	double rico = deltay / deltax;//(*y2 - *y1) / (*x2 - *x1);
	std::cout<<"rico = %e\n"<<rico<<std::endl; 
	fprintf(stdout, "rico=%f", rico);
	if (rico > 0) {
		if (*y2 >= *y1) {
			if (*x1 > *x2)
				swap3(x1,x2);
			
			//lower right
			while ( *x2 >= *x1 ) {
				drawline31Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		} else if (*y2 < *y1) {
			//upper right
			while ( *x2 >= *x1 ) {
				drawline35Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		}
	} else if (rico < 0) {
		if (*x1 < *x2)
				swap3(x1,x2);

		if (*y2 >= *y1) {
			//lower left
			while ( *x2 <= *x1 ) {
				drawline31Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		} else if (*y2 < *y1) {
			//upper left
			while ( *x2 <= *x1 ) {	
				drawline35Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		}
	}
}

//quadrant 3
void drawline31Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x += 1;
    *ynum += deltay;
    if (*ynum >= deltax)
      {
	*ynum -= deltax;
	(*y)++;
  //    }
    
  }
  //*y += SCROLLSPEED;
}
//quadrant 4
void drawline32Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += 1;
    *xnum += deltax;
    if (*xnum >= deltay)
      {
	*xnum -= deltay;
	(*x)++;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 5
void drawline33Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x -= 1;
    *ynum += deltay;
    if (*ynum >= -deltax)
      {
	*ynum -= -deltax;
	(*y)++;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 6
void drawline34Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += 1;
    *xnum += -deltax;
    if (*xnum >= deltay)
      {
	*xnum -= deltay;
	(*x)--;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 7
void drawline35Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x += 1;
    *ynum += -deltay;
    if (*ynum >= deltax)
      {
	*ynum -= deltax;
	(*y)--;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 2
void drawline36Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y -= 1;
    *xnum += deltax;
    if (*xnum >= -deltay)
      {
	*xnum -= -deltay;
	(*x)++;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 8
void drawline37Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x -= 1;
    *ynum += -deltay;
    if (*ynum >= -deltax)
      {
	*ynum -= -deltax;
	(*y)--;
      }
  //}
  //*y += SCROLLSPEED;
}
//quadrant 1
void drawline38Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y -= 1;
    *xnum += -deltax;
    if (*xnum >= -deltay)
      {
	*xnum -= -deltay;
	(*x)--;
      }
    //}
  //*y += SCROLLSPEED;
}

void drawVertical3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += *ynum;
  //}
  //*y += SCROLLSPEED;
}

