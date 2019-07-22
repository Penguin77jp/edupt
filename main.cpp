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

  const int width = 1000, height = 500, sampling = 200, superSamples = 2, fps = 1;
  const double timeLimit = 0.00001;
  //const double timeLimit = 3.1482*2;

  vWriter writer = vWriter("output", fps, width, height);
  edupt::scene sceneData = edupt::scene();
  sTime time = sTime(fps, timeLimit);
  Animation anim = Animation(&time, &sceneData);
  anim.AddWork(&LookAt(sceneData, 0, timeLimit, time, Vec3(30, 40, 125), sceneData.camera_position));

  //animation
  for (; time.getSceneTime() < time.getTimeLimit(); time++) {
    double process = time.getSceneTime() / time.getTimeLimit();
    std::cout << process * 100 << "% remaining time:" << std::to_string((double)time.ElapsedTime() / process * (1.0 - process) / CLOCKS_PER_SEC / 60) << " minutes" << std::endl;
    anim.Update();
    edupt::render(width, height, sampling, superSamples, time, &sceneData, writer);
  }

  return 0;
}
