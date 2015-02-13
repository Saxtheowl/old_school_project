
#ifndef _FLOOR_HH_
# define _FLOOR_HH_

#include "Case.hh"
#include "Map.hh"
#include "enum.hh"

class Floor : public Case
{
private:
  int  x;
  int  y;
  bool update;
  bool fire;

public:
  Floor();
  Floor(bool fire);

  ~Floor();
  virtual Type getType() const;
  virtual bool getUpdate() const;
  virtual void setUpdate(bool up);
  virtual void setPos(int x, int y);
  virtual int getTpos() const;
  virtual int getX() const;
  virtual int getY() const;
  virtual void set_Update(bool state);
  virtual bool get_Update() const;
  virtual int   getIndex() const;
  virtual void  setIndex(int up);

  bool getFire() const;
  void setFire(bool);
};

#endif 