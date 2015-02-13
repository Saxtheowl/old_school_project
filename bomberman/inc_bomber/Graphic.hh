
#ifndef _GRAPHIC_HH_
# define _GRAPHIC_HH_

#include <Input.hh>
#include <Clock.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.hh"
#include "Model.hh"
#include "AObject.hh"
#include "Cube.hh"
#include "Mod.hh"
#include "Map.hh"
#include "enum.hh"

class Graphic
{
private:
  std::vector<AObject*> _objects;
  std::vector<AObject*> _floor;
  std::vector<AObject*> _bombs;

  bool  add_floor(Map *map, int i);
  bool  add_wall(Map *map, int i);
  bool  add_box(Map *map, int i);
  bool	add_player(Map *map, int i);
  bool	add_bomb(Map *map, int i);
  bool	add_bonus(Map *map, int i, TypeBonus bonus);
  bool	add_fire(Map *map, int i);

  void	check_floor(Map *map, int i);
  void	check_bonus(Map *map, int i);
  void	check_player(Map *map, int i, gdl::Clock &clock);
  void	check_playeralive(Map *map, int i);
  void	check_bomb(Map *map);

  void	replace_index(Map *map, int i);
  void	replace_Bindex(Map *map, int i);

  bool	move_player(int index, Dir direction, gdl::Clock &clock, bool speed);
public:
  Graphic();
  ~Graphic();

  bool	init(Map *map);
  bool	actualize(Map *map, gdl::Clock &clock);

  void	draw(gdl::BasicShader &shader, gdl::Clock &clock, Map *map);
};

#endif