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

  //const int width = 250, height = 250, sampling = 250, superSamples = 2, fps = 15;
  const int width = 2000, height = 2000, sampling = 1, superSamples = 1, fps = 1;
  const double timeLimit = 1.0/fps*2;
  //const double timeLimit = 3.1482*0.5;

  vWriter writer = vWriter("output", fps, width, height);
  edupt::scene sceneData = edupt::scene();
  sTime time = sTime(fps, timeLimit);
  Animation anim = Animation(&time, &sceneData);
  anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.x,0,timeLimit,time,TrigonometricAnimation::e_TrigonType::sin,25,1,50));
  anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.y, 0, timeLimit, time, TrigonometricAnimation::e_TrigonType::cos, 25, 1, 40));
  anim.AddWork(&TrigonometricAnimation(sceneData.camera_position.z, 0, timeLimit, time, TrigonometricAnimation::e_TrigonType::cos, 0, 1, 125));
  anim.AddWork(&LookAt(sceneData, 0, timeLimit, time, Vec3(50, 40, 125), sceneData.camera_position));

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
