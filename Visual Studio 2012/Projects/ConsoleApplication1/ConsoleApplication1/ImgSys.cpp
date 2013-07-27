/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "include/SDL.h"
#include"ImgSys.h"
#include "util.h"

namespace zelda
{
namespace image
{

using namespace std;

int ImgSys::load(string filename, SDL_Surface **surface)
{
	if ( !filename.length() ) { *surface = NULL; return(-1); } 
	if ( filein(filename, surface) && surface != NULL) { return(0); }
	//never reached.
	return -1;
}

int ImgSys::load(string filename, map<std::string, SDL_Surface *> *surfaces)
{
	SDL_Surface *surface = (SDL_Surface *)0;
	if ( !filename.length() ) { delete surface; return(-1); } 
	if ( filein(filename, &surface) < 0 || surface == NULL ) { return(-1); }

	(*surfaces)[filename] = surface;
	//list<SDL_Surface *>::iterator vi;
	//for (vi = surfaces->begin(); vi != surfaces->end(); vi++)
	//	;

	//--vi;
	//memcpy ((*vi), surface, sizeof(surface));
			
	return 0;
}

int ImgSys::reload(string filename, SDL_Surface **surface)
{
	if ( !*surface ) { SDL_FreeSurface(*surface); *surface = NULL; }
	filein(filename, surface); 
	return(0);
}

int ImgSys::filein(string filename, SDL_Surface **surface)
{
	SDL_Surface *ts = SDL_LoadBMP(cs(filename));//cs returns c_str
	*surface = SDL_DisplayFormat(ts);
	SDL_SetColorKey (*surface,SDL_SRCCOLORKEY,_colorkey);
	return(0);
}

}
}
