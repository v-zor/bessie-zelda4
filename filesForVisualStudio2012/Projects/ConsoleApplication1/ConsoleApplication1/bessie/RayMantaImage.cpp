/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaImage.h"
//#include "RayManta.h"

RayMantaImage::RayMantaImage (std::string const& filename) 
{
//	init();
  
    /* Load the BMP file into a surface */
    image = SDL_LoadBMP(const_cast<std::string&>(filename).c_str());
    if (image == NULL) {
        fprintf(stderr, "Couldn't load %s: %s\n", filename.c_str(), SDL_GetError());
        return;
    }

    /*
     * Palettized screen modes will have a default palette (a standard
     * 8*8*4 colour cube), but if the image is palettized as well we can
     * use that palette for a nicer colour matching
     */
    //if (image->format->palette && screen->format->palette) {
    //SDL_SetColors(screen, image->format->palette->colors, 0,
    //             image->format->palette->ncolors);
    //}

    


//	int depth = DefaultDepth(*dpy, DefaultScreen(*dpy));
//  	Visual *visual = DefaultVisual(*dpy, DefaultScreen(*dpy));
//	image = XCreateImage(*dpy, visual, depth, XYPixmap,0,(char *)post_xpm,24,24,8,1); 
}

int RayMantaImage::draw(SDL_Surface *screen, int xx, int yy)
{
/*#define NIL (0)
  GC gc = XCreateGC(*dpy, *w, 0, NIL);
  XPutImage(*dpy, *w, gc, image, 0,0,destxx,destyy,500,500);
*//* Blit onto the screen surface */
	SDL_Rect r;
	r.x = xx;
	r.y = yy;
    if(SDL_BlitSurface(image, NULL, screen, &r) < 0)
        fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());

    SDL_UpdateRect(screen, 0, 0, image->w, image->h);

  
	return 0;
}

int RayMantaImage::putpixel(int x, int y, Uint32 pixel)
{
//	XPutPixel(image, xx,yy,value);
	int bpp = image->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)image->pixels + y * image->pitch + x * bpp;

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


unsigned long RayMantaImage::getpixel(int x, int y)
{
//	return XGetPixel(image, xx,yy);
	int bpp = image->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)image->pixels + y * image->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

