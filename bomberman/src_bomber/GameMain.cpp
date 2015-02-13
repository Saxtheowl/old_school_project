

#include <iostream>
#include <stdio.h>
#include "../inc_bomber/GameMain.hh"

GameMain::GameMain() : init(false)
{

}

GameMain::~GameMain()
{
}

bool	GameMain::checkEnd()
{
  if (!map->getPlayer1() && !map->getPlayer2())
  {
    std::cout << std::endl << "=====> Bot win <=====" << std::endl;
    return (true);
  }
  else if  (!map->getPlayer1())
  {
    std::cout << std::endl << "=====> Player 2 win <=====" << std::endl;
    return (true);
  }
  else if  (!map->getPlayer2())
  {
    std::cout << std::endl << "=====> Player 1 win <=====" << std::endl;
    return (true);
  }
  return (false);
}

bool	GameMain::initialize()
{
  if (!_context.start(800, 600, "Bon Barman"))
  {
    std::cout << "Error Opening Window" << std::endl;
    return false;
  }
  std::string name_map = "map/GDLmap";
  map = new Map(name_map);
  graphic = new Graphic();
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  if (!_shader.load("shaders/basic.fp", GL_FRAGMENT_SHADER))
    return (false);
  if (!_shader.load("shaders/basic.vp", GL_VERTEX_SHADER))
    return (false);
  if (!_shader.build())
    return false;
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(-map->getx_Map() / 2, map->gety_Map(), -map->gety_Map())
			       , glm::vec3(-map->getx_Map() /2, -map->gety_Map(), 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  _shader.setUniform("uColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
  graphic->init(map);
  return true;
}

bool    GameMain::update()
{
  _context.updateClock(_clock);
  _context.updateInputs(pinput.getInput());
  if (checkEnd())
  {    
    delete(map);
    delete(graphic);
    return false;
  }
  if (pinput.getInput().getKey(SDLK_ESCAPE) || pinput.getInput().getKey(SDL_QUIT))
  {
    delete(map);
    delete(graphic);
    return false;
  }
  if (init)
    pinput.checkKeyPush(map, _clock);
  size_t i = 0;
  bool up = true;
  while (i < map->vec_bomb.size())
  {
    if (map->vec_bomb[i]->actualize(_clock) && up)
    {
      map->vec_bomb[i]->explose();
      up = false;
    }
    i++;
  }
  graphic->actualize(map, _clock);
  return true;
}

void	GameMain::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  graphic->draw(_shader, _clock, map);
  _context.flush();
}

int	GameMain::run()
{
  if (this->initialize() == false)
    return (EXIT_FAILURE);
  while (this->update() == true)
  {
    this->draw();
    init = true;
  }
  return (EXIT_SUCCESS);
}