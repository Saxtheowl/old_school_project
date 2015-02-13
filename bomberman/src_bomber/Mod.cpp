
#include "../inc_bomber/Mod.hh"
#include <iostream>
#include <string>

Mod::Mod(float _x, float _y, float _z, int _scale, std::string text) : AObject(_x, _y, _z, _scale)
{
  _nametext = text;
  i = 0;
  _rotate = false;
  _anim = false;
  rot = UP;
  if (text == "marvin.fbx")
  {
    _color.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    _color.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    _color.z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  }
  else
  {
    _color.x = 1.0f;
    _color.y = 1.0f;
    _color.z = 1.0f;
  }
}

Mod::~Mod()
{

}

std::string Mod::getName() const
{
  return (this->_nametext);
}

glm::vec4 Mod::getColor() const
{
  return (this->_color);
}

bool Mod::initialize()
{
  std::string name = "assets/";
  
  name += _nametext;
  _speed = 10.0f;
  if (!_model.load(name) == true)
  {
    std::cerr << "Cannot load the cube texture" << std::endl;
    return (false);
  }
  
  _model.createSubAnim(0, "walk", 34, 53);
  _model.setCurrentSubAnim("walk", true);
  _model.pause(true);
  
  return (true);
}


void Mod::rotateLeft()
{
  rotate(glm::vec3(0.0f, -1.0f, 0.0f), 90.0f);
}

void Mod::rotateRight()
{
  rotate(glm::vec3(0.0f, 1.0f, 0.0f), 90.0f);

}

void Mod::rotateTurn()
{
  rotate(glm::vec3(0.0f, 1.0f, 0.0f), 180.0f);
}

void         Mod::move_up()
{
  if (!_anim)
  {
    _model.pause(false);
    _anim = true;
  }    
  if (!_rotate && rot != UP)
  {
    if (rot == DOWN)
      rotateTurn();
    else if (rot == RIGHT)
      rotateRight();
    else
      rotateLeft();
    rot = UP;
      _rotate = true;
  }
}

void         Mod::move_right()
{
  if (!_anim)
  {
    _model.pause(false);
    _anim = true;
  }
  if (!_rotate && rot != RIGHT)
  {
    if (rot == UP)
      rotateLeft();
    else if (rot == DOWN)
      rotateRight();
    else
      rotateTurn();
    rot = RIGHT;
    _rotate = true;
  }
}

void         Mod::move_left()
{
  if (!_anim)
  {
    _model.pause(false);
    _anim = true;
  }
  if (!_rotate && rot != LEFT)
  {
    if (rot == DOWN)
      rotateLeft();
    else if (rot == UP)
      rotateRight();
    else
      rotateTurn();
    rot = LEFT;
    _rotate = true;
  }
}

void         Mod::move_down()
{
  if (!_anim)
  {
    _model.pause(false);
    _anim = true;
  }
  if (!_rotate && rot != DOWN)
  {
    if (rot == RIGHT)
      rotateLeft();
    else if (rot == LEFT)
      rotateRight();
    else
      rotateTurn();
    rot = DOWN;
    _rotate = true;
  }
}

bool Mod::update(Dir dir, gdl::Clock &clock, bool speed)
{
  float	j;
  float _speed;

  if (speed)
    _speed = 1.5;
  else
    _speed = 1;
  j = clock.getElapsed() * _speed;
  if (i + clock.getElapsed() * _speed * 3 < 1)
    i += clock.getElapsed() * _speed * 3;
  else
  {
    j = (1 - i) / 3;
    i = 1;
  }
  if (dir == UP)
  {
    translate(glm::vec3(0, 0, j * 3));
    move_up();
  }
  if (dir == RIGHT)
  {
    translate(glm::vec3(-j * 3, 0, 0));
    move_right();
  }
  if (dir == LEFT)
  {
    translate(glm::vec3(j * 3, 0, 0));
    move_left();
  }
  if (dir == DOWN)
  {
    translate(glm::vec3(0, 0, -j * 3));
    move_down();
  }
  if (i == 1)
  {
    _model.pause(true);
    i = 0;
    _rotate = false;
    _anim = false;
    return (true);
  }
  return (false);
}

void Mod::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _model.draw(shader, getTransformation(), clock.getElapsed());
}