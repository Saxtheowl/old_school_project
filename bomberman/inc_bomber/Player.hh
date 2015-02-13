
#ifndef _PLAYER_HH_
# define _PLAYER_HH_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Clock.hh>
#include "Case.hh"
#include "Map.hh"
#include "enum.hh"
#include "Bomb.hh"

class Map;
class Bomb;

class Player : public Case
{
private:
  int  x;
  int  y;
  int  nb_P;
  bool bonus_speed;
  int  nb_bomb;
  int  force_bomb;
  Dir  direction;
  Map  *map;
  bool alive;
  int  indexb;
  float timer;
public:
  Player(int nb, Map *map, Dir direction, int index, int force, int nb_b, int indt, bool speed);
  ~Player();

  virtual Type	getType() const;
  virtual bool	getUpdate() const;
  virtual void	setUpdate(bool up);
  virtual int	getIndex() const;
  virtual void  setIndex(int up);
  virtual void	setPos(int x, int y);
  virtual int	getTpos() const;
  virtual int	getX() const;
  virtual int	getY() const;
  int		getIndexb() const;
  void		setIndexb(int i);
  bool		getAlive() const;
  void		setAlive(bool _alive);
  int		getNbBomb() const;
  void		setNbBomb(int nb);
  int		getForceBomb() const;
  void		setForceBomb(int nb);
  bool		getBombOnMe() const;
  bool		getBonusSpeed() const;
  Dir		getDirection() const;
  int		get_nb_P() const;
  void		put_Bomb();

  void		check_floor(int mov_x, int mov_y, Dir direction);
  void		check_bonus(int mov_x, int mov_y, Dir direction);
  bool		move_Player(int mov_x, int mov_y, Dir direction);
};

#endif 