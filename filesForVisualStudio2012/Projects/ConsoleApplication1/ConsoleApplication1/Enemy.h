/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _ENEMY_H
#define _ENEMY_H

#include "Entity.h"
#include <string>

namespace zelda
{
namespace main
{
class Player;

class Enemy : public Entity
{
public:
	Enemy(int xx, int yy, int ww, int hh);
	virtual ~Enemy();

	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void undoMove();

	virtual Entity* collision(Player const& player, int fight);
	void addPictureUp(std::string filename);
	void addPictureDown(std::string filename);
	void addPictureLeft(std::string filename);
	void addPictureRight(std::string filename);
	void addFightPictureUp(std::string filename);
	void addFightPictureDown(std::string filename);
	void addFightPictureLeft(std::string filename);
	void addFightPictureRight(std::string filename);
	void blit(SDL_Surface **screen);
	void blitfight(SDL_Surface **screen);

protected:

	std::string _direction;
	int _fightsurfacesindex;
	std::vector<SDL_Surface *> _upsurfaces;
	std::vector<SDL_Surface *> _leftsurfaces;
	std::vector<SDL_Surface *> _rightsurfaces;

	std::vector<SDL_Surface *> _fightupsurfaces;
	std::vector<SDL_Surface *> _fightdownsurfaces;
	std::vector<SDL_Surface *> _fightleftsurfaces;
	std::vector<SDL_Surface *> _fightrightsurfaces;
};

}
}

#include "Player.h"

#endif