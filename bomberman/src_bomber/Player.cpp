
#include "../inc_bomber/Player.hh"
#include "../inc_bomber/Map.hh"

Player::Player(int nb, Map *_Map, Dir dir, int ind, int force, int nb_b, int indt, bool speed) : nb_P(nb), direction(dir), map(_Map)
{
  this->alive = true;
  this->update = false;
  this->index = ind;
  this->bonus_speed = speed;
  this->nb_bomb = nb_b;
  this->force_bomb = force;
  indexb = indt;
  timer = 0;
}

Player::~Player()
{

}


int   Player::getIndexb() const
{
  return (indexb);
}

void  Player::setIndexb(int i)
{
  indexb = i;
}

bool  Player::getAlive() const
{
  return (alive);
}

void  Player::setAlive(bool _alive)
{
  alive = _alive;
}

int   Player::getForceBomb() const
{
  return (this->force_bomb);
}

void  Player::setForceBomb(int nb)
{
  this->force_bomb = nb;
}

int    Player::getNbBomb() const
{
  return (nb_bomb);
}

void   Player::setNbBomb(int nb)
{
  this->nb_bomb += nb;
}

Dir    Player::getDirection() const
{
  return(direction);
}


bool	Player::getBonusSpeed() const
{
  return (bonus_speed);
}


Type    Player::getType() const
{
  return(PLAYER);
}

bool    Player::getUpdate() const
{
  return (this->update);
}

void    Player::setUpdate(bool up)
{
  this->update = up;
}

int    Player::getIndex() const
{
  return (this->index);
}

void    Player::setIndex(int up)
{
  this->index = up;
}


void	Player::setPos(int x, int y) {
  this->x = x;
  this->y = y;
}

int	Player::getTpos() const
{
  return(this->x * this->y);
}

int	Player::getX() const
{
  return(this->x);
}

int	Player::getY() const
{
  return(this->y);
}

int	Player::get_nb_P() const
{
  return(this->nb_P);
}

void	Player::check_floor(int mov_x, int mov_y, Dir direction)
{
  bool ok = true;
  size_t i  = 0;
  while (i < map->vec_bomb.size())
  {
    if (map->vec_bomb[i]->getPos() == map->fix_Pos(x + mov_x, y + mov_y))
      ok = false;
    i++;
  }
  if (ok)
  {
    map->set_pos_P(get_nb_P(), map->fix_Pos(x + mov_x, y + mov_y));
    map->addCasePlayer(x + mov_x, y + mov_y, get_nb_P(), direction, this->index, getForceBomb(), getNbBomb(), -1, false);
    map->addCaseFloor(this->x, this->y);
  }
}

void	Player::check_bonus(int mov_x, int mov_y, Dir direction)
{
  if (dynamic_cast<Bonus*>(map->getMatrix()[map->fix_Pos(x + mov_x, y + mov_y)])->getBonus() == SPEED)
    bonus_speed = true;
  else if (dynamic_cast<Bonus*>(map->getMatrix()[map->fix_Pos(x + mov_x, y + mov_y)])->getBonus() == NB)
    this->nb_bomb += 1;
  else
    this->force_bomb += 1;
  int	indext = dynamic_cast<Bonus*>(map->getMatrix()[map->fix_Pos(x + mov_x, y + mov_y)])->getIndex();
  map->addCasePlayer(x + mov_x, y + mov_y, get_nb_P(), direction, this->index, getForceBomb(), getNbBomb(), indext, bonus_speed);
    map->set_pos_P(get_nb_P(), map->fix_Pos(x + mov_x, y + mov_y));
    map->addCaseFloor(this->x, this->y);
}

bool	Player::move_Player(int mov_x, int mov_y, Dir direction)
{

  if (map->getMatrix()[map->fix_Pos(x + mov_x, y + mov_y)]->getType() == FLOOR)
    check_floor(mov_x, mov_y, direction);
  else if (map->getMatrix()[map->fix_Pos(x + mov_x, y + mov_y)]->getType() == BONUS)
    check_bonus(mov_x, mov_y, direction);
  else
    return (false);
  return (true);
}