
#include "../inc_bomber/Wall.hh"

Wall::Wall()
{

}

Wall::~Wall()
{

}

bool    Wall::getUpdate() const
{
  return (this->update);
}

void    Wall::setUpdate(bool up)
{
  this->update = up;
}

int    Wall::getIndex() const
{
  return (this->index);
}

void    Wall::setIndex(int up)
{
  this->index = up;
}


void     Wall::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
}

Type	Wall::getType() const
{
  return (WALL);
}


int	Wall::getTpos() const
{
  return(this->x * this->y);
}

int	Wall::getX() const
{
  return(this->x);
}

int	Wall::getY() const
{
  return(this->y);
}

void	Wall::set_Update(bool state)
{
  this->update = state;
}

bool	Wall::get_Update() const
{
  return(this->update);
}