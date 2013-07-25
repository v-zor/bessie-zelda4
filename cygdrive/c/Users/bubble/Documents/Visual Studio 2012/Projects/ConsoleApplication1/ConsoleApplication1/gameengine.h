#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "Player.h"
#include "Player3d.h"
#include "EnemyDemon.h"
#include "EnemyDemon2.h"
#include "Skeleton1.h"
#include "tile.h"
#include "tile3d.h"
#include "exit.h"

#include<list>

namespace zelda 
{
namespace main
{

class GameEngine
{
public: 
	GameEngine() : /*_player(0,0,32,32,20),*//*_player(100,400,0,32,32,32,20)*/_player(315,240,0,32,32,32,20), _entities(), _roomid(1) { 
		zelda::image::ImgSys imgsys;
		imgsys.load("./Zelda/pics/blank-800x600.bmp", &_blanksurface);
		loadRoom2(); 
		tile.init();
		Exit *exit = new Exit(620,0,20,480,1);
		_exits.push_back(exit);
	}
	virtual ~GameEngine() {}

	void doLoop(SDL_Surface **screen);
	void updateanddraw(SDL_Surface **screen);
	void blitmoving(SDL_Surface **screen, SDL_Surface **blanksurface);
	int collision(int fight);
	Exit *doCollisionExits();
	void blitfight(SDL_Surface **screen, SDL_Surface **blanksurface);
	void removeEntity(Entity *e);

	void loadNextRoom();
	void loadRoom1();
	void loadRoom2();

	double get_transx() { return _transx; }
	double get_transy() { return _transy; }

private:

	void updateanddrawentities(SDL_Surface **screen);
	void translateentities(double xx, double yy);

	Player3d _player;
	std::list<Entity *> _entities;
	SDL_Surface *_blanksurface;
	
	int _roomid;

	double _transx, _transy;

	Tile3d tile;
	std::list<Exit *> _exits; 
};

}
}

#endif