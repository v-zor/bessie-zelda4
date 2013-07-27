#include "Enemy3d.h"

namespace zelda
{
namespace main 
{

Enemy3d::Enemy3d(int xx, int yy, int zz, int ww, int hh, int dd) : Entity3d(xx,yy,zz,ww,hh,dd),Enemy(xx,yy,ww,hh)
{}

}
}