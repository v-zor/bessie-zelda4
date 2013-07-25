#include "Entity3d.h"
#include "Player3d.h"

namespace zelda
{
namespace main 
{

Entity3d::Entity3d(int xx, int yy, int zz, int ww, int hh, int dd) : Entity(xx,yy,ww,hh)
{}

//NOTE Player3d
Entity* Entity3d::collision3d(Player3d const& player)
{
	//NOTE1
	if (const_cast<Player3d *>(&player)->get_x() < get_x() && 
		const_cast<Player3d *>(&player)->get_x() > get_x() + get_w() &&
		const_cast<Player3d *>(&player)->get_y() < get_y() && 
		const_cast<Player3d *>(&player)->get_y() > get_y() + get_h() &&
		const_cast<Player3d *>(&player)->get_z() < get_z() && 
		const_cast<Player3d *>(&player)->get_z() > get_z() + get_d()
		
		)
		return this;
	else
		return (Entity *)0;
}

}
}