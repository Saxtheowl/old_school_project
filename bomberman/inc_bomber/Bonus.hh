
#ifndef _BONUS_HH_
# define _BONUS_HH_

#include "Case.hh"
#include "Map.hh"
#include "enum.hh"

class Bonus : public Case
{
private:
  int  x;
  int  y;
  TypeBonus bonus;
  bool	toDel;

public:
  Bonus();
  ~Bonus();
  TypeBonus getBonus() const;
  void	setDel(bool up);
  bool	getDel() const;
  virtual bool getUpdate() const;
  virtual void setUpdate(bool up);
  virtual Type getType() const;
  virtual void setPos(int x, int y);
  virtual int getTpos() const;
  virtual int getX() const;
  virtual int getY() const;
  virtual void set_Update(bool state);
  virtual bool get_Update() const;
  virtual int   getIndex() const;
  virtual void  setIndex(int up);
};

#endif 