#ifndef RM_DRAW3_H
#define RM_DRAW3_H

#include "../include/SDL.h"

void drawline3old(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color);
void drawline3(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color);

void drawline31Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline32Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline33Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline34Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline35Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline36Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline37Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline38Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawVertical3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed);

#endif