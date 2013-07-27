/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef IMGSYS_H
#define IMGSYS_H

#include "include/SDL.h"
#include<string>
#include<map>
//#include<unistd.h>
namespace zelda
{
namespace image
{

using namespace std;

class ImgSys
{
	public:
		ImgSys() : _colorkey(0x000000) {}
		ImgSys(Uint32 colorkey) : _colorkey(colorkey) {}
		virtual ~ImgSys() {}

		int reload(string filename, SDL_Surface **surface);
		int load(string filename, SDL_Surface **surface);
		int load(string filename, map<std::string, SDL_Surface *> *surfaces);//FIXME map

	protected:

	private:
		int filein(string filename, SDL_Surface **surface = NULL);		
	private:
		uint32_t _colorkey;

};

}
}


#endif
