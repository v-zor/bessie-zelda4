/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "tile.h"
#include "ImgSys.h"
#include "Player.h"

namespace zelda
{
namespace main
{

int Tile::init()
{

	zelda::image::ImgSys imgsys;
	imgsys.load("./Zelda/pics/tile1grass.bmp", &_tile1surface);
	imgsys.load("./Zelda/pics/tile2grass.bmp", &_tile2surface);
	return 0;
}

int Tile::draw_tiles(SDL_Surface **screen, int tilemap[])
{
	volatile int i = 0;
	register int j = 0;
	for (j = 0; j < 15; j++) {
		for (i = 0; i < 20; i++) {
	
			switch (tilemap[i+j*20]){
			case 1:{
				draw_tile1grass(screen, i*32, j*32);
				break;
				   }
			case 2:{
				draw_tile2grass(screen, i*32, j*32);
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

int Tile::draw_tiles1(SDL_Surface **screen)
{
	draw_tiles(screen, tilemap1);
	return 0;
}

int Tile::draw_tiles2(SDL_Surface **screen)
{
	draw_tiles(screen, tilemap2);
	return 0;
}

int Tile::draw_tile1grass(SDL_Surface **screen, int x, int y)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 32;//FIXME param
	r.h = 32;
	SDL_BlitSurface (_tile1surface,NULL,*screen,&r);
	return 0;
}
int Tile::draw_tile2grass(SDL_Surface **screen, int x, int y)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = 32;//FIXME param
	r.h = 32;
	SDL_BlitSurface (_tile2surface,NULL,*screen,&r);
	return 0;
}


int Tile::collide_tiles(Player *player, int tilemap[])
{
	volatile int i = 0;
	register int j = 0;
	for (j = 0; j < 15; j++) {
		for (i = 0; i < 20; i++) {
			if (player->get_x() > i*32 && player->get_x() < (i+1)*32 &&
				player->get_y() > j*32 && player->get_y() < (j+1)*32)
			switch (tilemap[i+j*20]){
			case 1:{
				return 0;
				break;
				   }
			case 2:{
				return 0;
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