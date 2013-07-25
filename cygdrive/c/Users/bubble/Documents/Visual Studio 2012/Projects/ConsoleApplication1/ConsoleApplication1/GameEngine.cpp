/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#include "GameEngine.h"
#include "Wall.h"
#include "Exit.h"
#include<iostream>
#include "include/SDL.h"
#include <windows.h>
#include <winbase.h>

namespace zelda
{
namespace main
{

void GameEngine::blitmoving(SDL_Surface **screen, SDL_Surface **_blanksurface)
{
		updateanddraw(screen);
		_player.blit(screen);
		SDL_Flip(*screen);
		//FIXME 
		SDL_BlitSurface (*_blanksurface,NULL,*screen,NULL);
}

void GameEngine::blitfight(SDL_Surface **screen, SDL_Surface **_blanksurface)
{
		updateanddraw(screen);
		_player.blitfight(screen);
		SDL_Flip(*screen);
		//FIXME 
		SDL_BlitSurface (*_blanksurface,NULL,*screen,NULL);
}

int GameEngine::collision(int fight)
{
	
	for (std::list<Entity *>::iterator vi = _entities.begin(); vi != _entities.end(); vi++) {
		Entity *collider = (Entity *)0;

		if ((collider = (*vi)->collision(_player)) != (Entity *)0) {
			collider->doCollision(*this, fight);
			if (fight) 
				_entities.erase(vi);
			//else
			//	loadNextRoom();//FIXME1
			return 1;		
		}
	}
	return 0;
}


void GameEngine::doLoop(SDL_Surface **screen)
{
  /*
   * fixme: put calibrating code in bogus loops
   */
  //double time = 0.0;
  //int ticks = 0;
  //int sleeptime = 0;
  //int fps = FPS;
  //int xv = 0, yv = 0, shoot = 0;
  //_player.rotate();
  //FIXME SEE FURTHER 
  //_player.translate(*this);
  _transx = 0;
  _transy = 0;

  Uint8 *keystate;
  int done=0;
  while(done == 0)
    {
	  //Sleep(10);
      SDL_Event event;
      //struct tms tmsstart;
      //clock_t start = times(&tmsstart);
	  //NOTE
     SDL_BlitSurface (_blanksurface,NULL,*screen,NULL); 
    while ( SDL_PollEvent(&event) )
	{
	  	  
	  switch (event.type) {
	  case SDL_QUIT:{
	    exit(0);
	    break;
	  }
	  case SDL_KEYUP:{
	    switch (event.key.keysym.sym) { 
	    case SDLK_ESCAPE:{
	      //pause();
			exit(0);
	      break;
	    }
	    case SDLK_q:{
	      //pause();
	    break;
	    }
	    case SDLK_n:{
	      //load_next_level();
	      break;
	    }

	    }
	  }
	  }
	}
      
      keystate = SDL_GetKeyState(NULL);
      if (keystate[SDLK_SPACE]) {
		if (!collision(1)) {
			//_player.fight(screen);
		}
		blitfight(screen, &_blanksurface);
		continue;//FIXME1
      }
      
      if ( keystate[SDLK_UP] ) {
		 
      if (!collision(0)) {
			 _transy += 1;//_player.moveUp();
			
	  } else {
			_transy -= 1;//_player.undoMove();
			translateentities(0,-1);
	  }
		//blitmoving(screen, &_blanksurface);
		//continue;
		

	  }
      if (keystate[SDLK_DOWN]){
		   
		if (!collision(0))
			_transy -= 1;//_player.moveDown();
		else {
			_transy += 1;//_player.undoMove();
			translateentities(0,1);
		}
		//blitmoving(screen, &_blanksurface);
		//continue;
		
	  }
      if ( keystate[SDLK_LEFT] ) {
		  
		if (!collision(0))
			_transx += 1;//_player.moveLeft();
		else {
			_transx -= 1;//_player.undoMove();
			translateentities(-1,0);
		}
		//blitmoving(screen, &_blanksurface);
		//continue;
		
	  }
	  if (keystate[SDLK_RIGHT]) {
		
		if (!collision(0)) {
			_transx -= 1;//_player.moveRight();
			//_player.translate(*this);		
		}
		else {
			_transx += 1;//_player.undoMove();
			translateentities(1,0);
			//_player.translate(*this);
		}
		//blitmoving(screen, &_blanksurface);
		//continue;
		
      }
		/*FIXME*/
	  if (tile.collide_tiles3d(&_player, tilemap1)) {

			_player.undoMove();

	  }
	  Exit *exit = (Exit *)0;
	  if (exit = doCollisionExits()) {

		  switch(exit->get_nextRoomId()){
			 case 1:{
			  loadRoom2();//exit(0);//FIXME1
			  break;
				 }
		  case 2:{
			  loadRoom2();//exit(0);//FIXME1
			  break;
				 }
		  }

	  }
	  //FIXME overwritten by tiles in updateanddraw()!
	 
	  updateanddraw(screen);
	  //NOTE
	  //_player.translate(0,0,0);//*this);
	  //_player.rotate();//FIXME rotate player pixel
	 _player.blitstatic(screen);
	 SDL_Flip(*screen);
	 
	 
	 
    }
  
  //endGame();
}


void GameEngine::updateanddraw(SDL_Surface **screen)
{
	//FIXME1
	//SDL_BlitSurface (_blanksurface,NULL,*screen,NULL); 
	

	switch(_roomid){
	case 1:{
		
		tile.draw_tiles3d1(screen,_transx,_transy);
		break;
		   }
	case 2:{
		tile.draw_tiles3d1(screen,_transx,_transy);
		break;
		   }
	default:{
		break;
			}
	}

	updateanddrawentities(screen);
}

void GameEngine::updateanddrawentities(SDL_Surface **screen)
{
	for (std::list<Entity *>::iterator vi = _entities.begin(); vi != _entities.end(); vi++)
	{
		
		(*vi)->updateanddraw(screen);
		
	}
}

void GameEngine::translateentities(double xx, double yy)
{
	for (std::list<Entity *>::iterator vi = _entities.begin(); vi != _entities.end(); vi++)
	{
		
		(*vi)->translate(xx,yy);
		
	}
}

void GameEngine::loadNextRoom()
{
	if (_roomid == 1)
		loadRoom2();
	else if (_roomid == 2)
		;

}

void GameEngine::loadRoom1()
{
	_roomid = 1;

	//NOTE gets loaded blank
//	zelda::image::ImgSys imgsys;
//	imgsys.load("./Zelda/pics/room1-320x200.bmp", &_blanksurface);
	_entities.erase(_entities.begin(),_entities.end());
	_player.set_x(100);
	_player.set_y(100);
	//load walls

	//_entities.push_back(new Wall(0,0,320,10));
	//_entities.push_back(new Wall(0,0,10,200));
	//_entities.push_back(new Wall(0,190,320,10));

	//load enemies FIXME images
	//_entities.push_back(new EnemyDemonRed(100,100)); 
	//_entities.push_back(new EnemyDemonBlue(100,120));
	//_entities.push_back(new Skeleton1(100,100)); 
	//load exits
	_entities.push_back(new Exit(600,0,10,480,2));
}

void GameEngine::loadRoom2()
{
	_roomid = 2;

	_entities.erase(_entities.begin(),_entities.end());

	//_entities.push_back(new EnemyDemonRed(100,100)); 
	//_entities.push_back(new EnemyDemonBlue(10,10));
//	zelda::image::ImgSys imgsys;
//	imgsys.load("./Zelda/pics/room1-320x200.bmp", &_blanksurface);
	_entities.erase(_entities.begin(),_entities.end());
	_player.set_x(100);
	_player.set_y(100);
	//load walls

	_entities.push_back(new Wall(0,0,320,10));
	_entities.push_back(new Wall(0,0,10,200));
	_entities.push_back(new Wall(0,190,320,10));

	//load enemies FIXME images
	_entities.push_back(new EnemyDemonRed(100,150)); 
	_entities.push_back(new EnemyDemonBlue(120,170));
	//_entities.push_back(new Skeleton1(100,100)); 
	//load exits
	//_entities.push_back(new Exit(310,0,10,200));
}

Exit *GameEngine::doCollisionExits()
{
	for (std::list<Exit *>::iterator vi = _exits.begin(); vi != _exits.end(); vi++)
	{
		if ((*vi)->collision(&_player) != (Entity *)0)
			return (*vi);
	}

	return (Exit *)0;
}

}
}