#ifndef	_SPHERE_H_
#define	_SPHERE_H_

#include <cmath>

#include "vec.h"
#include "ray.h"
#include "material.h"
#include "constant.h"
#include "intersection.h"
#include "Texture.h"
#include "NormalMap.h"

namespace edupt {

class Sphere {
public:
	double radius;
	Vec3 position;
	Color emission;
	Color color;
	ReflectionType reflection_type;
  Texture *texture;
  NormalMap* normalMap;

	Sphere(const double radius, const Vec3 &position, const Color &emission, const Color &color, const ReflectionType reflection_type,Texture *texture,NormalMap *normalMap) :
	  radius(radius), position(position), emission(emission), color(color), reflection_type(reflection_type),texture(texture),normalMap(normalMap) {}

	// 入力のrayに対する交差点までの距離を返す。交差しなかったら0を返す。
	// rayとの交差判定を行う。交差したらtrue,さもなくばfalseを返す。
  bool intersect(const Ray& ray, Hitpoint* hitpoint) const;
};

};

#endif
