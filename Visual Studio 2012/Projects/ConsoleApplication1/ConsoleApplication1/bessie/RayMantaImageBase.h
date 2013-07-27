/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef RAYIMAGEBASE_H
#define RAYIMAGEBASE_H

#include<string>
#include "../include/SDL.h"

//interface
class RayMantaImageBase {
public:

  virtual int draw(SDL_Surface *screen, int xx, int yy) = 0;
  virtual int putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel) = 0;

protected:
	SDL_Surface *image;
  //XImage *image;


}; //class RayMantaImage

#endif
