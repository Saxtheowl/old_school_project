
#include "../inc_bomber/Graphic.hh"

Graphic::Graphic()
{
}

Graphic::~Graphic()
{
  _objects.clear();
  _floor.clear();
  _bombs.clear();
}

bool	Graphic::actualize(Map *map, gdl::Clock &clock)
{
  size_t	i;
  int	index;
 
  i = 0;
  index = 0;
  while (map->getCase(i) != NULL)
  {
    check_floor(map, i);
    if (map->getCase(i)->update == true)
      {
	check_bonus(map, i);
	check_player(map, i, clock);
      }
    check_playeralive(map, i);
    i++;
  }
  check_bomb(map);
  return (true);
}

bool	Graphic::add_floor(Map *map, int i)
{
  AObject *cube;

    cube = new Cube(-map->getCase(i)->getY(), 0, -map->getCase(i)->getX(), \
		  "floor.tga");
  if (cube->initialize() == false)
      return (false);
  _floor.push_back(cube);
  
  return (true);
}

bool	Graphic::add_wall(Map *map, int i)
{
  AObject *cube;

  cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		  "wall.tga");
  if (cube->initialize() == false)
    return (false);
  _objects.push_back(cube);
  return (true);
}

bool	Graphic::add_box(Map *map, int i)
{
  AObject *cube;

  cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		  "box.tga");
  if (cube->initialize() == false)
    return (false);
  _objects.push_back(cube);
  return (true);
}

bool	Graphic::add_bonus(Map *map, int i, TypeBonus bonus)
{
  AObject *cube;

  if (bonus == SPEED)
    cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		    "bonus_speed.tga");
  else if (bonus == NB)
    cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		    "bonus_bomb.tga");
  else
    cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		    "bonus_force.tga");    
  if (cube->initialize() == false)
    return (false);
  _objects.push_back(cube);
  return (true);
}


bool	Graphic::add_player(Map *map, int i)
{
  
  AObject *model;


  model = new Mod(-map->getCase(i)->getY(), 0.5, -map->getCase(i)->getX(), \
		  500, "marvin.fbx");
  if (model->initialize() == false)
    return (false);
  _objects.push_back(model);
  return (true);
  
}

bool	Graphic::add_bomb(Map *map, int i)
{
  AObject *cube;

  cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		  "bomb.tga");
  if (cube->initialize() == false)
    return (false);
  _bombs.push_back(cube);
  return (true);
}

bool	Graphic::add_fire(Map *map, int i)
{
  AObject *cube;

  cube = new Cube(-map->getCase(i)->getY(), 1, -map->getCase(i)->getX(), \
		  "fire.tga");
  if (cube->initialize() == false)
    return (false);
  _objects.push_back(cube);
  return (true);
}

bool	Graphic::move_player(int index, Dir direction, gdl::Clock &clock, bool speed)
{ 
  return (_objects[index]->update(direction, clock, speed));
}

void	Graphic::check_floor(Map *map, int i)
{
  if (map->getCase(i)->getType() == FLOOR)
  {
    if (dynamic_cast<Floor*>(map->getCase(i))->getFire())
    {      
      add_fire(map, i); 
      dynamic_cast<Floor*>(map->getCase(i))->setFire(false);
    }
    if (map->getCase(i)->getUpdate() && map->getCase(i)->getIndex() > 5)
    {
      map->getCase(i)->setUpdate(false);
      replace_index(map, map->getCase(i)->getIndex());
      _objects.erase(_objects.begin() + map->getCase(i)->getIndex());
      add_floor(map, i);
    }
  }
}

void	Graphic::check_bonus(Map *map, int i)
{
  if (map->getCase(i)->getType() == BONUS)
  {
    _objects.erase(_objects.begin() + map->getCase(i)->getIndex());
    replace_index(map, map->getCase(i)->getIndex());
    add_bonus(map, i, dynamic_cast<Bonus*>(map->getCase(i))->getBonus());
    map->getCase(i)->setUpdate(false);
    map->getCase(i)->setIndex(_objects.size()-1);
  }
}

void	Graphic::check_player(Map *map, int i, gdl::Clock &clock)
{
  
  if (map->getCase(i)->getType() == PLAYER)
  {
    int index = map->getCase(i)->getIndex();
    bool speed = dynamic_cast<Player*>(map->getCase(i))->getBonusSpeed();
    if (move_player(index, dynamic_cast<Player*>(map->getCase(i))->getDirection(), clock, speed))
      map->getCase(i)->update = false;
    if (dynamic_cast<Player*>(map->getCase(i))->getIndexb() != -1)
    {
      _objects.erase(_objects.begin() + dynamic_cast<Player*>(map->getCase(i))->getIndexb());
      replace_index(map, dynamic_cast<Player*>(map->getCase(i))->getIndexb());
      dynamic_cast<Player*>(map->getCase(i))->setIndexb(-1);
    }   
  }
  
}

void	Graphic::check_playeralive(Map *map, int i)
{
  if (map->getCase(i)->getType() == PLAYER && !dynamic_cast<Player*>(map->getCase(i))->getAlive())
  {
    _objects.erase(_objects.begin() + dynamic_cast<Player*>(map->getCase(i))->getIndex());
    replace_index(map, map->getCase(i)->getIndex());
    dynamic_cast<Player*>(map->getCase(i))->setAlive(true);
    map->addCaseFloor(i, true);
  }
}

void	Graphic::check_bomb(Map *map)
{
  size_t i = 0;
  
  while (i < map->vec_bomb.size())
  {
    
    if (map->vec_bomb[i]->getDel())
    {
      _bombs.erase(_bombs.begin() + map->vec_bomb[i]->getIndex());
      map->vec_bomb.erase(map->vec_bomb.begin() + i);
      replace_Bindex(map, i);
    }    
    if (!map->vec_bomb[i]->getDraw())
      {
	add_bomb(map, map->vec_bomb[i]->getPos());
	map->vec_bomb[i]->setIndex(_bombs.size()-1);
	map->vec_bomb[i]->setDraw(true);
      } 
    i++;    
   }

}

void	Graphic::replace_Bindex(Map *map, int i)
{
  size_t j = 0;

  while (j < map->vec_bomb.size())
  {
    if (map->vec_bomb[j]->getIndex() > i)
      map->vec_bomb[j]->setIndex(map->vec_bomb[j]->getIndex() - 1);
    j++;
  }
}


void	Graphic::replace_index(Map *map, int i)
{
  size_t j = 0;

  while (map->getCase(j) != NULL)
  {
    if (map->getCase(j)->getIndex() > i)
      map->getCase(j)->setIndex(map->getCase(j)->getIndex() - 1);
    j++;
  }
}

bool	Graphic::init(Map *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map->getCase(i) != NULL)
  {
        if (add_floor(map, i) == false)
      return (false);
    if (map->getCase(i)->getType() == WALL)
    {
      map->getCase(i)->setIndex(j);
      j++;
      if (add_wall(map, i) == false)
	return (false);
    }
    else if (map->getCase(i)->getType() == BLOCK)
    {
      map->getCase(i)->setIndex(j);

      j++;
      if (add_box(map, i) == false)
	return (false);
    }
    else if (map->getCase(i)->getType() == PLAYER)
    {
      map->getCase(i)->setIndex(j);
      j++;
      if (add_player(map, i) == false)
	return (false);
    }
    i++;
  }
  return (true);
}



void  Graphic::draw(gdl::BasicShader &_shader, gdl::Clock &_clock, Map *map)
{
  size_t i;

  for (i = 0; i < _objects.size(); ++i)
    {
      _shader.bind();
      _shader.setUniform("uColor", _objects[i]->getColor());
      _objects[i]->draw(_shader, _clock);
      if (_objects[i]->getName() == "fire.tga")
      {
	_objects.erase(_objects.begin() + i);
	replace_index(map, i);
      }
    }
  for (i = 0; i < _floor.size(); ++i)
    {
      _shader.bind();
      _shader.setUniform("uColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    _floor[i]->draw(_shader, _clock);
    }
  for (i = 0; i < _bombs.size(); ++i)
    _bombs[i]->draw(_shader, _clock);

}