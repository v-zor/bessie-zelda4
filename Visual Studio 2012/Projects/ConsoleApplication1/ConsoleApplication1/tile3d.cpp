/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "tile3d.h"
#include "ImgSys.h"
#include "Player3d.h"
/*#include "../Draw2.h"
*/
#include "bessie/Draw.h"

//#include "Draw3.h"

#include "bessie/RayMantaMatrix3.h"
/*#include "../RayMantaEngine.h"
*/
#include "bessie/RayMantaPolygon.h"
#include "bessie/RayMantaImage.h"
#include "bessie/RayMantaSphereModel.h"

#include "Cube.h"

namespace zelda
{
namespace main
{

int Tile3d::init()
{
	_theta1 = 3.14;//sqrt(2)/2;////2.5;
	_theta2 = 0;//sqrt(2)/2;////2.5;
	_theta3 = sqrt(2)/2;//3.14;///2.5;

	_tx = 1;
	_ty = 1;
	_tz = 1;

	return 0;
}

int Tile3d::draw_tiles(SDL_Surface **screen, int tilemap[], double transx, double transy)
{
	volatile int i = 0;
	register int j = 0;
	for (j = 0; j < 15; j++) {
		for (i = 0; i < 20; i++) {
	
			switch (tilemap[i+j*20]){
			case 1:{
				draw_tile3d1grass(screen, i*32, j*32,transx,transy);
				break;
				   }
			case 2:{
				draw_tile3d2grass(screen, i*32, j*32,transx,transy);
				break;
				   }
			case 3:{
				draw_tile3d3door(screen, i*32, j*32,transx,transy);
				break;
				   }
			case 4:{
				draw_sphere(screen, i*32, j*32,transx,transy);
				break;
				   }
			default:{
				break;
					}
			}

		}
	}

	return 0;
}

int Tile3d::draw_tiles3d1(SDL_Surface **screen,double transx,double transy)
{
	draw_tiles(screen, tilemap3d1,transx,transy);
	return 0;
}

/*int Tile::draw_tiles2(SDL_Surface **screen)
{
	draw_tiles(screen, tilemap2);
	return 0;
}*/

int Tile3d::draw_tile3d1grass(SDL_Surface **screen, int x, int y, double transx, double transy)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 32;//FIXME param
	r.h = 32;
//	SDL_BlitSurface (_tile1surface,NULL,*screen,&r);

	//NOTE : rotate x,y coords for view
/*	int x1 = x, y1 = y, x2 = x1+20, y2 = y1;
	ray3d::Point p1(x1,y1,10);
	ray3d::Point p2(x2,y2,10);


	_theta1 *= 1.00000005;
	_theta2 *= 1.00000005;
	_theta3 *= 1.00000005;
*/
/*	ray3d::Matrix3 rotmx = ray3d::rotatex(_theta1);
	ray3d::Matrix3 rotmy = ray3d::rotatey(_theta2);
    ray3d::Matrix3 rotmz = ray3d::rotatez(_theta3);
*///	ray3d::Vector3 prot(p1.get_x(), p1.get_y(), p1.get_z());
	//ray3d::Vector3 prot2(p2.get_x(), p2.get_y(), p2.get_z());
//			prot = rotmz*prot;
//			prot = rotmy*prot;
//			prot = rotmx*prot;
//	prot2 = rotmz*prot2;
//			prot2 = rotmy*prot2;
//			prot2 = rotmx*prot2;
	//draw cube
/*	
	int getx1 = prot.get_x();
	int gety1 = prot.get_y();
	int getx2 = prot2.get_x();
	int gety2 = prot2.get_y();
	drawline(*screen, &getx1,&gety1,&getx2,&gety2,0xff);
*//*	x1 = x2; 
	x2 = x1+20; 
	y2 = y2+20;
	p1(x1,y1,0);
	p2(x2,y2,0);
	
	prot(p1.get_x(), p1.get_y(), p1.get_z());
	prot2(p2.get_x(), p2.get_y(), p2.get_z());
			prot = rotmz*prot;
			prot = rotmy*prot;
			prot = rotmx*prot;
	prot2 = rotmz*prot2;
			prot2 = rotmy*prot2;
			prot2 = rotmx*prot2;
	drawline(*screen, &x1,&y1,&x2,&y2,0xff);
	x1 = x1-20;
	x2 = x1;
	y1 = y2;
	y2 = y2 +20;
	drawline(*screen, &x1,&y1,&x2,&y2,0xff);
*/

	ray3d::Cube cube;
	cube.translate(x+transx,y+transy,0);
	cube.rotate(_theta1, _theta2, _theta3);
	//_tx++;
	//_ty++;
	//_tz++;
	//cube.translate(_tx,_ty,_tz);
	cube.filltop(*screen, 0x0000ff);
	cube.draw(*screen);

	return 0;

}

int Tile3d::draw_tile3d2grass(SDL_Surface **screen, int x, int y, double transx, double transy)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 32;//FIXME param
	r.h = 32;

	ray3d::Polygon poly;
	poly.add(ray3d::Point(x+transx,y+transy,0));
	poly.add(ray3d::Point(x+transx+32,y+transy,0));
	poly.add(ray3d::Point(x+transx+32,y+transy+32,0));
	poly.add(ray3d::Point(x+transx,y+transy+32,0));
	poly.add(ray3d::Point(x+transx,y+transy,0));

	poly.rotate(_theta1, _theta2, _theta3);
	poly.fill4sidepolygon(*screen, 0x0000ff);
	poly.draw(*screen);

	//SDL_BlitSurface (_tile2surface,NULL,*screen,&r);
	return 0;
}

int Tile3d::draw_tile3d3door(SDL_Surface **screen, int x, int y, double transx, double transy)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 32;//FIXME param
	r.h = 32;

	RayMantaImage img("./Zelda/pics/dungeondoor1.bmp");
	//img.draw(*screen, x,y);

	/*
	//NOTE : for rotated (un-anti-aliased) door
	ray3d::Matrix3 rotmx = ray3d::rotatex(_theta1);
	ray3d::Matrix3 rotmy = ray3d::rotatey(_theta2);
    ray3d::Matrix3 rotmz = ray3d::rotatez(_theta3);
	*/

	int i,j;
	//std::vector<Point> replacementvec;
	for (j = 0; j < 32; j++) {
		for (i = 0; i < 32; i++) {

			ray3d::Vector3 prot(i+x+transx, j+y+transy, 0);
			Uint32 pixelcolor = img.getpixel(i,j);
			/*prot = rotmz*prot;
			prot = rotmy*prot;
			prot = rotmx*prot;
			*/
			putpixel(*screen, prot.get_x()/*+i*/,prot.get_y()/*+j*/,pixelcolor);
		}
	}
	//SDL_BlitSurface (_tile2surface,NULL,*screen,&r);
	return 0;
}

int Tile3d::draw_sphere(SDL_Surface **screen, int x, int y, double transx, double transy)
{
	ray3d::SphereModel spheremodel;
	spheremodel.generatesphere(*screen,60+transx,60+transy,60);
	spheremodel.drawpoints(*screen);
	spheremodel.drawsunray(*screen);
	return 0;
}


int Tile3d::collide_tiles3d(Player3d *player, int tilemap[])
{
	volatile int i = 0;
	register int j = 0;
	for (j = 0; j < 15; j++) {
		for (i = 0; i < 20; i++) {
			if (player->get_x() > i*32 && player->get_x() < (i+1)*32 &&
				player->get_y() > j*32 && player->get_y() < (j+1)*32)
				// &&
				/*player->get_z() > i*32 && player->get_z() < (i+1)*32*/

				
			switch (tilemap[i+j*20]){			
			case 1:{//block
				return 1;
				break;
				   }
			case 2:{//square
				return 0;
				break;
				   }
			case 3:{//dungeon door 1
				return 1;
				break;
				   }
			case 4:{//sphere
				return 1;
				break;
				   }
			default:{
				break;
					}
			}

		}
	}

	return 0;
}




} // namespace main
} // namespace zelda