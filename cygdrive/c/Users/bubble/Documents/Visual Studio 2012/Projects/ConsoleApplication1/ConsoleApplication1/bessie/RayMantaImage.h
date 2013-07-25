/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef RAYIMAGE_H
#define RAYIMAGE_H

#include "../include/SDL.h"
#include<string>

#include "RayMantaImageBase.h"

class RayMantaImage// : public RayMantaImageBase 
{
 public:
	 RayMantaImage(std::string const& filename);
  int init() { /*XInitImage(image);*/ return 0;}
  virtual ~RayMantaImage() {}

  int draw(SDL_Surface *screen, int xx, int yy);
  int putpixel(int x, int y, Uint32 pixel);
  unsigned long getpixel(int x, int y);

protected:
  //XImage *shape;
	SDL_Surface *image;

}; //class RayMantaImage

#endif
