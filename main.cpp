#include <iostream>
#include<opencv2/opencv.hpp>
#include <string>

#include "render.h"
#include "vWriter.h"
#include "sTime.h"
#include "scene.h"
#include "Animation.h"
#include "Texture.h"

int main() {
  std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

  const int width = 500, height = 500, sampling = 50, superSamples = 4, fps = 15;
  const double timeLimit = 0.00001;
  //const double timeLimit = 3.1482*2;

  vWriter writer = vWriter("output", fps, width, height);
  edupt::scene sceneData = edupt::scene();
  sTime time = sTime(fps, timeLimit);
  Animation anim = Animation(&time, &sceneData);
  //anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.x,0,timeLimit,time,TrigonometricAnimation::e_TrigonType::sin,40,1,50));
  //anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.y, 0, timeLimit, time, TrigonometricAnimation::e_TrigonType::cos, 0, 1, 40));
  //anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.z, 0, timeLimit, time, TrigonometricAnimation::e_TrigonType::cos, 40, 1, 125));
  anim.AddWork(&LookAt(sceneData, 0, timeLimit, time, Vec3(50, 40, 125), sceneData.camera_position));
  anim.AddWork(&LinerAnimation(sceneData.spheres[6].color.x, 0, 1, time, 0, 1));
  anim.AddWork(&LinerAnimation(sceneData.spheres[6].color.y, 0, 1, time, 0, 0));
  anim.AddWork(&LinerAnimation(sceneData.spheres[6].color.z, 0, 1, time, 0, 0));
  anim.AddWork(&LinerAnimation(sceneData.spheres[6].color.y, 1, 2, time, 0, 1));
  anim.AddWork(&LinerAnimation(sceneData.spheres[6].color.z, 1, 2, time, 0, 1));

  //animation
  for (; time.getSceneTime() < time.getTimeLimit(); time++) {
    double process = time.getSceneTime() / time.getTimeLimit();
    std::cout << process * 100 << "% remaining time:" << std::to_string((double)time.ElapsedTime() / process * (1.0 - process) / CLOCKS_PER_SEC / 60) << " minutes" << std::endl;
    anim.Update();
    edupt::render(width, height, sampling, superSamples, time, &sceneData, writer);
  }

  return 0;
}

/*

int main(int argc, char** argv) {
  std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

  //const int width = 250, height = 250, sampling = 250, superSamples = 2, fps = 15;
  const int width = 250, height = 250, sampling = 5, superSamples = 2, fps = 4;

  vWriter writer = vWriter("output", fps, width, height);
  edupt::scene* sceneData = &edupt::scene();
  Time time = Time(fps, 4);
  Animation anim = Animation(&time, sceneData);
  //anim.AddWork((AnimationWork)TrigonometricAnimation(&sceneData->camera_position.x, 0, 4, TrigonometricAnimation::e_TrigonType::sin));
  auto test = TrigonometricAnimation(&sceneData->camera_position.x, 0, 4, TrigonometricAnimation::e_TrigonType::sin);
  test.UpdateAnimation();



  //animation
  for (; time.getSceneTime() < time.getTimeLimit(); time++) {
    double process = time.getSceneTime() / time.getTimeLimit();
    std::cout << process * 100 << "% remaining time:" << std::to_string((double)time.ElapsedTime() / process * (1.0 - process) / CLOCKS_PER_SEC / 60) << " minutes" << std::endl;
    anim.Update();
    edupt::Color* image = edupt::render(width, height, sampling, superSamples, time, sceneData, writer);
  }
  return 0;
}


*/
