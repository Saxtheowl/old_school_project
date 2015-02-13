
#include "../inc_bomber/Bonus.hh"

#include <cstdlib>

Bonus::Bonus() : toDel(true)
{
  int nb = rand() % 3 + 1;

  if (nb == 1)
    bonus = SPEED;
  else if (nb == 2)
    bonus = NB;
  else
    bonus = FORCE;
  update = true;
}

Bonus::~Bonus()
{

}

bool	  Bonus::getDel() const
{
  return (toDel);
}

void	  Bonus::setDel(bool up)
{
  toDel = up;
}

TypeBonus Bonus::getBonus() const
{
  return (bonus);
}

bool    Bonus::getUpdate() const
{
  return (this->update);
}

void    Bonus::setUpdate(bool up)
{
  this->update = up;
}

int    Bonus::getIndex() const
{
  return (this->index);
}

void    Bonus::setIndex(int up)
{
  this->index = up;
}

void     Bonus::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
}

Type	Bonus::getType() const
{
  return (BONUS);
}

int	Bonus::getTpos() const
{
  return(this->x * this->y);
}

int	Bonus::getX() const
{
  return(this->x);
}

int	Bonus::getY() const
{
  return(this->y);
}

void	Bonus::set_Update(bool state)
{
  this->update = state;
}

bool	Bonus::get_Update() const
{
  return(this->update);
}