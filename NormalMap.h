#pragma once

#include "Texture.h"

class NormalMap : public Texture {
public:
  float length;

  NormalMap(string fileName, double length) : Texture(fileName), length(length) {};

  inline Vec3 Vec2Normal(Vec3 getPosi) {
    Color getC = Normal2Color(getPosi);
    return Vec3((getC.x * 2 - 1)*length, (getC.y * 2 - 1) * length, (getC.z * 2 - 1) * length);
  }
};
