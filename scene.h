#ifndef	_SCENE_H_
#define	_SCENE_H_

#include "constant.h"
#include "sphere.h"
#include "intersection.h"
#include <vector>

namespace edupt {
  class scene {
  public:
    // レンダリングするシーンデータ
    Texture tex = Texture("4k.jpg");
    NormalMap normalMap = NormalMap("BumpMapColourMapStoneWallExample.jpg",10.0);
    Sphere spheres[10]{
  Sphere(1e5, Vec3(1e5 + 1, 40.8, 81.6), Color(),      Color(0.75, 0.25, 0.25), REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 左
  Sphere(1e5, Vec3(-1e5 + 99, 40.8, 81.6),Color(),      Color(0.25, 0.25, 0.75), REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 右
  Sphere(1e5, Vec3(50, 40.8, 1e5),      Color(),      Color(0.75, 0.75, 0.75), REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 奥
  Sphere(1e5, Vec3(50, 40.8, -1e5 + 250), Color(),      Color(),                 REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 手前
  Sphere(1e5, Vec3(50, 1e5, 81.6),      Color(),      Color(0.75, 0.75, 0.75), REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 床
  Sphere(1e5, Vec3(50, -1e5 + 81.6, 81.6),Color(),      Color(0.75, 0.75, 0.75), REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), // 天井
  Sphere(20,Vec3(30,40,125),           Color(),      Color(0.25, 0.75, 0.25), REFLECTION_TYPE_DIFFUSE,&tex,&normalMap), // 緑球
  Sphere(15.0,Vec3(50.0, 90.0, 125),   Color(36,36,36), Color(),              REFLECTION_TYPE_DIFFUSE,nullptr,nullptr), //照明
  Sphere(16.5,Vec3(27, 16.5, 47),       Color(),      Color(0.99, 0.99, 0.99), REFLECTION_TYPE_SPECULAR,nullptr,nullptr), // 鏡
  Sphere(16.5,Vec3(77, 16.5, 78),       Color(),      Color(0.99, 0.99, 0.99), REFLECTION_TYPE_REFRACTION,nullptr,nullptr), //ガラス
    };

    //カメラ
    //center = (50,40,125)
    Vec3 camera_position = Vec3(80, 40, 125);
    Vec3 camera_dir = normalize(Vec3(0.0, -0.04, -1.0));
    Vec3 camera_up = Vec3(0.0, 1.0, 0.0);


    double kIor = 1.5;
    // シーンとの交差判定関数
    inline bool intersect_scene(const Ray& ray, Intersection* intersection) {
      const double n = sizeof(spheres)/sizeof(Sphere);

      // 初期化
      intersection->hitpoint.distance = kINF;
      intersection->object_id = -1;

      // 線形探索
      for (int i = 0; i < int(n); i++) {
        Hitpoint hitpoint;
        if (spheres[i].intersect(ray, &hitpoint)) {
          if (hitpoint.distance < intersection->hitpoint.distance) {
            intersection->hitpoint = hitpoint;
            intersection->object_id = i;
          }
        }
      }

      return (intersection->object_id != -1);
    }

  };
}

#endif
