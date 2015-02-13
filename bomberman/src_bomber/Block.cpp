
#include "../inc_bomber/Block.hh"

Block::Block()
{

}

Block::~Block()
{

}

bool    Block::getUpdate() const
{
  return (this->update);
}

void    Block::setUpdate(bool up)
{
  this->update = up;
}

int    Block::getIndex() const
{
  return (this->index);
}

void    Block::setIndex(int up)
{
  this->index = up;
}

void     Block::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
}

Type	Block::getType() const
{
  return (BLOCK);
}

int	Block::getTpos() const
{
  return(this->x * this->y);
}

int	Block::getX() const
{
  return(this->x);
}

int	Block::getY() const
{
  return(this->y);
}

void	Block::set_Update(bool state)
{
  this->update = state;
}

bool	Block::get_Update() const
{
  return(this->update);
}
