#ifndef RM_DRAW2_H
#define RM_DRAW2_H

#include "../include/SDL.h"

void drawlineold(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color);
void drawline(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color);

void drawline1Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline2Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline4Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline5Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline6Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline7Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawline8Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void drawVerticalFunc(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed);

#endif
