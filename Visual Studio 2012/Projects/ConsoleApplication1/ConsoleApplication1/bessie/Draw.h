#ifndef _DRAW_H_
#define _DRAW_H_

#include "../include/SDL.h"

/*
NOTE: maker sure putpixel does not go beyond the screen surf
*/
int putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

#endif