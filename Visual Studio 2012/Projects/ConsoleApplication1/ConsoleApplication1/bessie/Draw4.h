#ifndef RM_DRAW4_H
#define RM_DRAW4_H

#include "../include/SDL.h"

int max(int x, int y);
int min(int x, int y);
void linefill(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int *x4, int *y4, Uint32 color);
void linefillrec(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2,int *x3, int *y3, int *x4, int *y4, Uint32 color);

#endif