
#ifndef _GAME_MAIN_
# define _GAME_MAIN_

#include <OpenGL.hh>

#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>

#include "enum.hh"
#include "Map.hh"
#include "AObject.hh"
#include "Cube.hh"
#include "Mod.hh"
#include "Graphic.hh"
#include "PInput.hh"

class GameMain : public gdl::Game
{
private:
  Map *map;
  Graphic *graphic;
  PInput pinput;
  bool	init;

  gdl::SdlContext _context;
  gdl::Clock _clock;
    gdl::BasicShader _shader;
  
public:
  GameMain();
  ~GameMain();

  bool	checkEnd();
  int	start();
  int	run();
  bool	initialize();
  bool	update(void);
  void	draw(void);
};

#endif