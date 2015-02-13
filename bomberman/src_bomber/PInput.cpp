
#include "../inc_bomber/PInput.hh"

PInput::PInput() : _timerP1(0), _timerP2(0), _bombP1(false), _bombP2(false)
{

}

PInput::~PInput()
{

}

gdl::Input &PInput::getInput()
{
  return (this->_input);
}

bool  PInput::checkKeySPACE()
{
  if (_input.getKey(SDLK_SPACE))
    return (true);
  return (false);
}

bool  PInput::checkKeyCTRL()
{
  if (_input.getKey(SDLK_LCTRL) || _input.getKey(SDLK_RCTRL))
    return (true);
  return (false);
}


bool  PInput::checkPlayer1(Map *map, gdl::Clock &clock)
{
  float speed = 1;
  int pos;

  if (map->getPlayer1())
  {
    pos = map->get_pos_P(0);
  
    if (dynamic_cast<Player*>(map->getCase(pos))->getBonusSpeed())
      speed = 1.5;
    else
      speed = 1;
    if (_timerP1 == 0)
      {
	if(checkKeySPACE() && !_bombP1)
	  _bombP1 = true;
	if (_bombP1)
	  map->pos_bomb(0);
	if(checkKeyUP(map, clock) && _bombP1)
	  return (true);
	else if (checkKeyDOWN(map, clock) && _bombP1)
	  return (true);
	else if (checkKeyLEFT(map, clock) && _bombP1)
	  return (true);
	else if (checkKeyRIGHT(map, clock) && _bombP1)
	  return (true);
      }
    else if (_timerP1 > 0.35f / speed)
    {
      _timerP1 = 0;
      _bombP1 = false;
    }
    else
      _timerP1 += clock.getElapsed();
  }
  return (false);
}

bool  PInput::checkPlayer2(Map *map, gdl::Clock &clock)
{
  float speed2 = 1;
  int pos2;

  if (map->getPlayer2())
  {
    pos2 = map->get_pos_P(1);
    if (dynamic_cast<Player*>(map->getCase(pos2))->getBonusSpeed())
      speed2 = 1.5;
    else
      speed2 = 1;
    if (_timerP2 == 0)
      {
	if (checkKeyCTRL() && !_bombP2)
	  _bombP2 = true;
	if (_bombP2)
	  map->pos_bomb(1);
	if(checkKeyZ(map, clock))
	  return (true);
	else if (checkKeyS(map, clock))
	  return (true);
	else if (checkKeyQ(map, clock))
	  return (true);
	else if (checkKeyD(map, clock))
	  return (true);
      }
    else if (_timerP2 > 0.35f / speed2)
      {
	_timerP2 = 0;
	_bombP2 = false;
      }
    else
      _timerP2 += clock.getElapsed();
  }
  return (false);
}


bool PInput::checkKeyPush(Map *map, gdl::Clock &clock)
{
  if (checkPlayer1(map, clock))
    return (true);
  if (checkPlayer2(map, clock))
    return (true);
  return (true);
}


bool  PInput::checkKeyUP(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_UP))
  {
    map->move_up(0);
    _timerP1 += clock.getElapsed();
    return (true);
  }
  return (false);
}

bool  PInput::checkKeyDOWN(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_DOWN))
  {
    map->move_down(0);
    _timerP1 += clock.getElapsed();
    return (true);
  }
  return (false);

}

bool  PInput::checkKeyLEFT(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_LEFT))
  {
    map->move_left(0);
    _timerP1 += clock.getElapsed();
    return (true);
  }
  return (false);
}

bool  PInput::checkKeyRIGHT(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_RIGHT))
  {
    map->move_right(0);
    _timerP1 += clock.getElapsed();
    return (true);
  }
  return (false);
}



bool  PInput::checkKeyZ(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_z))
  {
    map->move_up(1);
    _timerP2 += clock.getElapsed();
    return (true);
  }
  return (false);
}

bool  PInput::checkKeyS(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_s))
  {
    map->move_down(1);
    _timerP2 += clock.getElapsed();
    return (true);
  }
  return (false);
}

bool  PInput::checkKeyQ(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_q))
  {
    map->move_left(1);
    _timerP2 += clock.getElapsed();
    return (true);
  }
  return (false);
}

bool  PInput::checkKeyD(Map *map, gdl::Clock &clock)
{
  if (_input.getKey(SDLK_d))
  {
    map->move_right(1);
    _timerP2 += clock.getElapsed();
    return (true);
  }
  return (false);
}