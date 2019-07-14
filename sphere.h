#ifndef	_SPHERE_H_
#define	_SPHERE_H_

#include <cmath>

#include "vec.h"
#include "ray.h"
#include "material.h"
#include "constant.h"
#include "intersection.h"

namespace edupt {

struct Sphere {
	double radius;
	Vec position;
	Color emission;
	Color color;
	ReflectionType reflection_type;

	Sphere(const double radius, const Vec &position, const Color &emission, const Color &color, const ReflectionType reflection_type) :
	  radius(radius), position(position), emission(emission), color(color), reflection_type(reflection_type) {}

	// 入力のrayに対する交差点までの距離を返す。交差しなかったら0を返す。
	// rayとの交差判定を行う。交差したらtrue,さもなくばfalseを返す。
  bool intersect(const Ray& ray, Hitpoint* hitpoint) const;
};

};

#endif
