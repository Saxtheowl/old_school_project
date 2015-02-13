
#include "../inc_bomber/Bomb.hh"

Bomb::Bomb(int i, Map *_map, Player *_player) : pos(i), timer(0), draw(false), 
						 del(false), map(_map), player(_player)
{
  player->setNbBomb(-1);
  nb_p = player->get_nb_P();
  force = dynamic_cast<Player*>(map->getMatrix()[map->get_pos_P(nb_p)])->getForceBomb();
}

Bomb::~Bomb()
{

}

bool  Bomb::getDel() const
{
  return (del);
}

void  Bomb::setDel(bool up)
{
  del = up;
}

bool  Bomb::check_wall(int i, int nb)
{
  if (map->getMatrix()[pos + i * nb]->getType() == WALL)
    return (true);
  return (false);
}

bool Bomb::check_block(int i, int nb)
{
  if (map->getMatrix()[pos + i * nb]->getType() == BLOCK)
    {
      int ind = map->getMatrix()[pos + i * nb]->getIndex();
      map->addCaseBonus(pos + i * nb);
      map->getMatrix()[pos + i * nb]->setIndex(ind);
      map->getMatrix()[pos + i * nb]->setUpdate(true);	
      return (true);
    }
  return (false);
}

bool Bomb::check_player(int i, int nb)
{
  if (map->getMatrix()[pos + i * nb]->getType() == PLAYER)
    {
      int nb_player = dynamic_cast<Player*>(map->getMatrix()[pos + i * nb])->get_nb_P();
      dynamic_cast<Player*>(map->getMatrix()[map->get_pos_P(nb_player)])->setAlive(false);
      if (nb_player == 0)
	map->setPlayer1(false);
      else if (nb_player == 1)
	map->setPlayer2(false);
      return (true);
    }
  return (false);
}

bool  Bomb::check_bonus(int i, int nb)
{
  if (map->getMatrix()[pos + i * nb]->getType() == BONUS)
    {
      int ind = map->getMatrix()[pos + i * nb]->getIndex();
      map->addCaseFloor(pos + i * nb, true);
      map->getMatrix()[pos + i * nb]->setIndex(ind);
      map->getMatrix()[pos + i * nb]->setUpdate(true);
      return (false);
    }
  return (false);
}

bool  Bomb::check_other(int i, int nb)
{
  bool check = true;

  size_t j = 0;
  while (j < map->vec_bomb.size())
    {
      if (map->vec_bomb[j]->getPos() == pos + i * nb)
	{
	  check = false;
	  map->vec_bomb[j]->timer += 10;
	}
      j++;
    }
  map->addCaseFloor(pos + i * nb, true);
  if (check)
    return (false);
  return (true);
}

void  Bomb::check_direction(int nb)
{
  int	i = 1;
  bool	ok = true;
  
  while (ok && i <= force)
  {
    if (pos + i * nb < map->getx_Map() * map->gety_Map())
    {
      if (check_wall(i, nb))
	ok = false;
      else if (check_block(i, nb))
	ok = false;
      else if (check_player(i, nb))
	ok = false;
      else if (check_bonus(i, nb))
	ok = false;
      else if (check_other(i, nb))
	ok = false;
      i++;
    }
  }
}

void  Bomb::check_center()
{
  
  if (map->getMatrix()[pos]->getType() == PLAYER)
  {
    dynamic_cast<Player*>(map->getMatrix()[map->get_pos_P(nb_p)])->setAlive(false);
    if (nb_p == 0)
      map->setPlayer1(false);
    if (nb_p == 1)
      map->setPlayer2(false);
  }
  else
    map->addCaseFloor(pos, true);
}


void  Bomb::explose()
{
  del = true;
  if (dynamic_cast<Player*>(map->getMatrix()[map->get_pos_P(nb_p)]) != NULL)
    dynamic_cast<Player*>(map->getMatrix()[map->get_pos_P(nb_p)])->setNbBomb(1);
  check_direction(1);
  check_direction(-1);
  check_direction(map->getx_Map());
  check_direction(-map->getx_Map());
  check_center();
}

bool  Bomb::actualize(gdl::Clock clock)
{
  timer += clock.getElapsed();
  if (timer > 3)
    return (true);
  return (false);
}

bool  Bomb::getDraw() const
{
  return (draw);
}

void  Bomb::setDraw(bool _draw)
{
  draw = _draw;
}

float Bomb::getTimer() const
{
  return (timer);
}

void  Bomb::setTimer(float _timer)
{
  timer = _timer;
}

int   Bomb::getPos() const
{
  return (pos);
}

bool    Bomb::getUpdate() const
{
  return (this->update);
}

void    Bomb::setUpdate(bool up)
{
  this->update = up;
}

int    Bomb::getIndex() const
{
  return (this->index);
}

void    Bomb::setIndex(int up)
{
  this->index = up;
}


void     Bomb::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
}

Type	Bomb::getType() const
{
  return (BOMB);
}

int	Bomb::getTpos() const
{
  return(this->x * this->y);
}

int	Bomb::getX() const
{
  return(this->x);
}

int	Bomb::getY() const
{
  return(this->y);
}

void	Bomb::set_Update(bool state)
{
  this->up = state;
}

bool	Bomb::get_Update() const
{
  return(this->up);
}