
#ifndef _MOD_HH_
# define _MOD_HH_

#include <glm/glm.hpp>                                                                                 
#include <glm/gtc/matrix_transform.hpp>   
#include <Clock.hh>
#include <Texture.hh>
#include <Model.hh>
#include <Geometry.hh>
#include "AObject.hh"
#include "enum.hh"

class Mod : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Model _model;
  std::string _nametext;
  float	i;

  Dir rot;

  bool	_anim;
  bool	_rotate;
  float _speed;
  void	       rotateLeft();
  void	       rotateRight();
  void	       rotateTurn();

  void	       move_up();
  void	       move_down();
  void	       move_left();
  void	       move_right();;

public:
  Mod(float x, float y, float z, int scale, std::string text);
  virtual ~Mod();

  glm::vec4    getColor() const;

  virtual std::string getName() const;
  virtual bool initialize();
  virtual bool update(Dir direction, gdl::Clock &clock, bool speed);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  
};

#endif 