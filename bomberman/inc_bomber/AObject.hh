
#ifndef AOBJECT_HH_
# define AOBJECT_HH_

#include <Clock.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <Model.hh>
#include <BasicShader.hh>
#include "enum.hh"

class AObject
{
public:
  AObject(float x, float y, float z, int scale);
  virtual ~AObject();
  virtual bool initialize();
  virtual bool update(Dir direction, gdl::Clock &clock, bool speed) = 0;
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  virtual glm::vec4 getColor() const = 0;

  virtual std::string getName() const = 0;

  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3 const& scale);
  glm::mat4 getTransformation();

protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
  glm::vec4 _color;
};

#endif