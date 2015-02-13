
#ifndef _BLOCK_HH_
# define _BLOCK_HH_

#include "Case.hh"
#include "Map.hh"
#include "enum.hh"

class Block : public Case
{
private:
  int  x;
  int  y;
  bool update;

public:
  Block();
  ~Block();
  virtual bool	getUpdate() const;
  virtual void	setUpdate(bool up);
  virtual Type	getType() const;
  virtual void	setPos(int x, int y);
  virtual int	getTpos() const;
  virtual int	getX() const;
  virtual int	getY() const;
  virtual void	set_Update(bool state);
  virtual bool	get_Update() const;
  virtual int   getIndex() const;
  virtual void  setIndex(int up);
};

#endif 