// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "include/SDL.h"

#include "ImgSys.h"

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen = SDL_SetVideoMode(640,480,32,SDL_DOUBLEBUF|SDL_HWSURFACE);

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 640;
	rectangle.h = 480;

	zelda::image::ImgSys imgsys;

	//SDL_Surface *opening = (SDL_Surface*)malloc(sizeof(SDL_Surface));
	//imgsys.load("./pics/demon2-up-32x32.bmp", &opening);
	for (;;)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			//int xx,yy;
			//Uint8 mousestate = SDL_GetMouseState(&xx,&yy);

			switch(e.type){
			case SDL_MOUSEBUTTONUP:
			case SDL_QUIT:
				goto labelmain;
			}
		}
	}
labelmain:

	return 0;
}

