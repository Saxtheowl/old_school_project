
#ifndef _CUBE_HH_
# define _CUBE_HH_

#include <Clock.hh>
#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"
#include "enum.hh"

class Cube : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  std::string _nametext;

public:
  Cube(int x, int y, int z, std::string text);
  virtual ~Cube();

  virtual std::string getName() const;
  virtual bool initialize();
  virtual bool update(Dir direction, gdl::Clock &clock, bool speed);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  virtual glm::vec4 getColor() const;
};

#endif