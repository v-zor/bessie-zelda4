/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _BESS_IMG_H_
#define _BESS_IMG_H_

#include "include/SDL.h"
#include<string>

namespace zelda
{
namespace image
{
using namespace std;
class Img
{
	public:
		Img(string filename, int ww, int hh);
		Img() : _surface(NULL),_w(0),_h(0) {}
		virtual ~Img() {}

	private:
		SDL_Surface *_surface;
		int _w,_h;
	public:
		Img(const Img& rhs);
		Img operator=(const Img& rhs);
};
}
}

#endif