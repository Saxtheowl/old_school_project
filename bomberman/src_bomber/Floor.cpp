
#include "../inc_bomber/Floor.hh"

Floor::Floor() : fire(false)
{
  update = false;
}

Floor::Floor(bool _fire) : fire(_fire) 
{
}

Floor::~Floor()
{

}

bool	Floor::getFire() const
{
  return (this->fire);
}

void	Floor::setFire(bool bol)
{
  this->fire = bol;
}


bool    Floor::getUpdate() const
{
  return (this->update);
}

void    Floor::setUpdate(bool up)
{
  this->update = up;
}

int    Floor::getIndex() const
{
  return (this->index);
}

void    Floor::setIndex(int up)
{
  this->index = up;
}

void     Floor::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
}

int	Floor::getX() const
{
  return(this->x);
}

int	Floor::getY() const
{
  return(this->y);
}

int	Floor::getTpos() const
{
  return(this->x * this->y);
}

Type	Floor::getType() const
{
  return (FLOOR);
}

void	Floor::set_Update(bool state)
{
  this->update = state;
}

bool	Floor::get_Update() const
{
  return(this->update);
}