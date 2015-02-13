
#ifndef _BOMB_HH_
# define _BOMB_HH_

#include <Clock.hh>
#include "Case.hh"
#include "Player.hh"
#include "Map.hh"

class Map;
class Player;

class Bomb : public Case
{
private:
  int		pos;
  float		timer;
  bool		draw;
  bool		del;
  Map		*map;
  Player	*player;
  int		nb_p;
  int		force;
  int		x;
  int		y;
  bool		up;
public:
  Bomb(int i, Map *map, Player *player);
  ~Bomb();
  virtual Type	getType() const;
  virtual bool	getUpdate() const;
  virtual void	setUpdate(bool up);
  virtual int   getIndex() const;
  virtual void  setIndex(int up);
  virtual void	setPos(int x, int y);
  virtual int	getTpos() const;
  virtual int	getX() const;
  virtual int	getY() const;
  virtual void	set_Update(bool state);
  virtual bool	get_Update() const;
  bool		getDel() const;
  void		setDel(bool up);
  bool		getDraw() const;
  void		setDraw(bool _draw);
  float		getTimer() const;
  void		setTimer(float _timer);
  int		getPos() const;


  void		check_center();
  void		check_direction(int nb);
  bool		check_wall(int i, int nb);
  bool		check_block(int i, int nb);
  bool		check_player(int i, int nb);
  bool		check_bonus(int i, int nb);
  bool		check_other(int i, int nb);

  void		explose();
  bool		actualize(gdl::Clock clock);
};

#endif 