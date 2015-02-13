
#ifndef _ENUM_HH_
# define _ENUM_HH_

enum Dir
  {
    NOTHING,
    UP,
    LEFT,
    DOWN,
    RIGHT,
  };

enum Type
  {
    FLOOR,
    WALL,
    BOMB,
    BLOCK,
    PLAYER,
    BOT,
    BONUS,
  };

enum TypeBonus
  {
    SPEED = 0,
    NB,
    FORCE,
  };

#endif