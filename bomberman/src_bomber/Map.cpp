
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
#include "../inc_bomber/Map.hh"

Map::Map(std::string dat_name)
{
  player1 = false;
  player2 = false;

  int i;

  i = 0;
  while(i < 100)
    {
      this->pos_P.push_back(1);       i++;
    }
  srand(time(NULL));
  get_size_map(dat_name);
  fill_map(dat_name);
  put_player(1);
  put_bot(0);
  load_cases();
}

Map::~Map()
{
  
  matrix.clear();
  vec_bomb.clear();
}

void Map::setPlayer1(bool alive)
{
  player1 = alive;
}

void Map::setPlayer2(bool alive)
{
  player2 = alive;
}

void  Map::addCasePlayer(int x, int y, int nb, Dir direction, int index, int force, int nb_b, int indt, bool speed)
{
  delete this->matrix[fix_Pos(x, y)];
  this->matrix[fix_Pos(x, y)] = new Player(nb, this, direction, index, force, nb_b, indt, speed);
  this->matrix[fix_Pos(x, y)]->setPos(x, y);
  this->matrix[fix_Pos(x, y)]->setUpdate(true);
  this->matrix[fix_Pos(x, y)]->setIndex(index);  
}

void Map::addCaseFloor(int x, int y)
{
  delete this->matrix[fix_Pos(x, y)];
  this->matrix[fix_Pos(x, y)] = new Floor();
  this->matrix[fix_Pos(x, y)]->setPos(x, y);
}

void Map::addCaseFloor(int i, bool up)
{
  delete this->matrix[i];
  this->matrix[i] = new Floor(up);
}

void Map::addCaseBonus(int i)
{
  delete this->matrix[i];
  this->matrix[i] = new Bonus();
}


int   Map::get_pos_P(int nb_P)
{
  return(this->pos_P[nb_P]);
}

void   Map::set_pos_P(int nb_P, int posi_P)
{
  this->pos_P[nb_P] = posi_P;
}

int   Map::getx_Map() const
{
  return(x_map);
}

int   Map::gety_Map() const
{
  return (y_map);
}

bool   Map::getPlayer1() const
{
  return (player1);
}

bool   Map::getPlayer2() const
{
  return (player2);
}


Case *Map::getCase(int x, int y) const
{
  return(this->matrix[fix_Pos(x, y)]);
}

Case *Map::getCase(int i) const
{
  return(this->matrix[i]);
}

int Map::fix_Pos(int x, int y) const
{
  return (x * x_map + y);
}

std::vector <Case*> Map::getMatrix() const
{
  return (matrix);
}



bool Map::move_up(int i)
{
    return (dynamic_cast<Player*>(matrix[pos_P[i]])->move_Player(-1, 0, UP));
}

bool Map::move_left(int i)
{
  return (dynamic_cast<Player*>(matrix[pos_P[i]])->move_Player(0, -1, LEFT));
}

bool Map::move_down(int i)
{
  return (dynamic_cast<Player*>(matrix[pos_P[i]])->move_Player(1, 0, DOWN));
}

bool Map::move_right(int i)
{
  return (dynamic_cast<Player*>(matrix[pos_P[i]])->move_Player(0, 1, RIGHT));
}

void Map::pos_bomb(int i)
{
  
  size_t	j = 0;
  bool		can_put_bomb = true;

  if (dynamic_cast<Player*>(matrix[pos_P[i]]) != NULL
      && dynamic_cast<Player*>(matrix[pos_P[i]])->getNbBomb() > 0)
  {
    while (j < vec_bomb.size())
    {
      if (vec_bomb[j] != NULL && vec_bomb[j]->getPos() == pos_P[i])
 	can_put_bomb = false;
      j++;
    }
    if (can_put_bomb)
      {
	put_a_bomb = true;
	if (dynamic_cast<Player*>(matrix[pos_P[i]]) != NULL)
	  vec_bomb.push_back(new Bomb(pos_P[i], this, dynamic_cast<Player*>(matrix[pos_P[i]]))); 
      } 
  }  
}

void Map::load_cases()
{
  int		i;
  int		end;
  int		end_l;
  int		x;
  int		y;

  x = 0;
  y = 0;
  end = x_map * y_map;
  end_l = 0;
  i = 0;
  while(i < end)
    {
      if (matrix[i]->getType() == PLAYER)
	this->pos_P[dynamic_cast<Player*>(matrix[i])->get_nb_P()] = i;
      matrix[i]->setPos(x, y);
      i++;
      end_l++;
      y++;
      if(end_l == x_map)
	{
	  y = 0;
	  x++;
	  end_l = 0;
	}
    }
}

void		Map::get_size_map(std::string &str)
{
  std::ifstream ifs;
  int x;
  int y;
  char c;
  const char *dat_name = str.c_str();

  x = 0;
  y = 0;
  c = 0;
  ifs.open (dat_name, std::ifstream::in);
  if(ifs.is_open())
    {
      while(!ifs.eof())
	{
	  c = ifs.get();
	  if(y == 0 && c != '\n')
	    x++;
	  if(c == '\n')
	    y++;
	}
    }
  this->x_map = x;
  this->y_map = y;
}

void		Map::fill_map(std::string &str)
{
  char		c;
  std::ifstream ifs;
  
  const char *dat_name = str.c_str();

  c = 0;
  ifs.open (dat_name, std::ifstream::in);
  if (ifs.is_open())
    {
      while (!ifs.eof())
	{
	  c = ifs.get();
	  if (c == 'w')
	    this->matrix.push_back(new Wall());
	  if (c == 'f')
	    this->matrix.push_back(new Floor());
	  if (c == 'b')
	    this->matrix.push_back(new Block());
	}
    }
  ifs.close();
}

void            Map::put_player(int player) {
  int           pos;
  int           end;

  end = this->x_map * this->y_map;
  pos = this->y_map + rand()%(this->y_map);
  if (player == 1)
  {
    player1 = true;
    player2 = true;
  }
  if (player == 0)
  {
    player1 = true;
  }
  while(player != -1)
    {
      while(matrix[pos]->getType() != FLOOR)
        {
          if(player == 0)
	    pos--;
          else if(player == 1)
	    pos++;
        }
      delete this->matrix[pos];
      this->matrix[pos] = new Player(player, this, NOTHING, 0, 2, 1, -1, false);
      pos = end - (pos + this->y_map);
      player--;
    }
}

void            Map::put_bot(int bot) {
  int pos;
  int end;

  bot += 1;
  pos = 0;
  end = this->x_map * this->y_map;
  while(bot > 1)
    {
      while(matrix[pos]->getType() != FLOOR)
        pos = rand()%(end);
      this->matrix[pos] = new Player(bot, this, NOTHING, 0, 2, 1, -1, false);
      pos = end - (pos + this->y_map);
      bot--;
    }
}

bool		Map::botAlive()
{
  size_t i = 2;
  bool	a_bot_alive = false;
  while (i < pos_P.size())
  {
    if (dynamic_cast<Player*>(matrix[pos_P[i]]) != NULL)
    {
      if (dynamic_cast<Player*>(matrix[pos_P[i]])->getAlive())
	a_bot_alive = true;
    }
    i++;
  }
  return (a_bot_alive);
}