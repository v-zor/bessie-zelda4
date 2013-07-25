/*
 Copyright (C) Johan Ceuppens 2011-2012
*/

#ifndef _TILEMAP3D_H_
#define _TILEMAP3D_H_

#include "include/SDL.h"

namespace zelda
{
namespace main
{
class Player3d;
static int tilemap3d1[] = { 1,1,1,1,1,1,1,1,1,3,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				};

static int tilemap3d2[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				};



class Tile3d
{

private:
//SDL_Surface *_tile1surface;
//SDL_Surface *_tile2surface;
	double _theta1, _theta2, _theta3;
	int _tx, _ty,_tz;
public:
int init();
int draw_tiles(SDL_Surface **screen, int tilemap[], double transx, double transy);
int draw_tiles3d1(SDL_Surface **screen, double transx, double transy);
//int draw_tiles2(SDL_Surface **screen);
int draw_tile3d1grass(SDL_Surface **screen, int x, int y, double transx, double transy);
int draw_tile3d2grass(SDL_Surface **screen, int x, int y, double transx, double transy);
int draw_tile3d3door(SDL_Surface **screen, int x, int y, double transx, double transy);
int draw_sphere(SDL_Surface **screen, int x, int y, double transx, double transy);
//int collide_tiles(Player *player, int tilemap[]);

int collide_tiles3d(Player3d *player, int tilemap[]);


};

} // namespace main
} // namespace zelda
#endif