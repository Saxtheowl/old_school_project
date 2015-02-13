
#ifndef _PINPUT_HH_
# define _PINPUT_HH_

#include <iostream>
#include <Input.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include "Map.hh"
#include "Player.hh"
#include "enum.hh"

class PInput
{
private:
  gdl::Input _input;
  double _timerP1;
  double _timerP2;

  bool	_bombP1;
  bool	_bombP2;

public:
  PInput();
  ~PInput();

  gdl::Input &getInput();

  bool	checkKeyPush(Map *map, gdl::Clock &clock);
  bool	checkKeyUP(Map *map, gdl::Clock &clock);
  bool	checkKeyDOWN(Map *map, gdl::Clock &clock);
  bool	checkKeyLEFT(Map *map, gdl::Clock &clock);
  bool	checkKeyRIGHT(Map *map, gdl::Clock &clock);
  bool	checkKeySPACE();

  bool	checkKeyCTRL();
  bool	checkKeyZ(Map *map, gdl::Clock &clock);
  bool	checkKeyS(Map *map, gdl::Clock &clock);
  bool	checkKeyQ(Map *map, gdl::Clock &clock);
  bool	checkKeyD(Map *map, gdl::Clock &clock);

  bool	checkPlayer1(Map *map, gdl::Clock &clock);
  bool	checkPlayer2(Map *map, gdl::Clock &clock);
};

#endif