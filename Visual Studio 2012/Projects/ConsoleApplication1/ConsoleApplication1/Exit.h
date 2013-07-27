#ifndef _EXIT_H
#define _EXIT_H

#include "Entity.h"

namespace zelda
{
namespace main
{

class Exit : public Entity
{
public:
	Exit(int xx, int yy, int ww, int hh, int nextRoomId);
	virtual ~Exit();

	Entity *collision(int xx, int yy, int ww, int hh);
	Entity *collision(Player *player);
	void doCollision(GameEngine const& engine, int fight);

	int get_nextRoomId() { return _nextRoomId; }

protected:

	int _nextRoomId;

};

}
}

#endif