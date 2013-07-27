#include "Draw.h"
#include<iostream>
/*
NOTE: maker sure putpixel does not go beyond the screen surf
*/
int putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{

	if (x >= 640 || y >= 480 || x <= 0 || y <= 0) {
		std::cout<<"putpixel : pixel offset out of range"<<std::endl;
		return -1;
	}
	//FIXME return 0; should be void
	int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
	return 0;
}

