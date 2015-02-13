
#ifndef _CASE_HH_
# define _CASE_HH_

#include "enum.hh"

class Case
{

public:
  bool update;
  int  index;

  Case();
  virtual ~Case();
  virtual Type	getType() const = 0;
  virtual void	setPos(int x, int y) = 0;
  virtual int	getTpos() const = 0;
  virtual int	getX() const = 0;
  virtual int	getY() const = 0;
  virtual bool	getUpdate() const = 0;
  virtual void	setUpdate(bool up) = 0;
  virtual int	getIndex() const = 0;
  virtual void	setIndex(int up) = 0;
};

#endif 