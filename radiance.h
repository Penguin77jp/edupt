#ifndef _RADIANCE_H_
#define _RADIANCE_H_

#include <algorithm>

#include "ray.h"
#include "scene.h"
#include "sphere.h"
#include "intersection.h"
#include "random.h"
#include "Texture.h"

namespace edupt {

const Color kBackgroundColor = Color(0.0, 0.0, 0.0);
const int kDepth = 5; // ロシアンルーレットで打ち切らない最大深度
const int kDepthLimit = 64;

// ray方向からの放射輝度を求める
Color radiance(const Ray& ray, Random* rnd, const int depth, scene* getSceneData);

};

#endif
