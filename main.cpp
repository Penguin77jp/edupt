#include <iostream>
#include<opencv2/opencv.hpp>
#include <string>

#include "render.h"
#include "vWriter.h"
#include "Time.h"
#include "scene.h"
#include "Animation.h"

int main(int argc, char** argv) {
  std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

	const int width = 640, height = 480, sampling = 10, fps = 30;

	vWriter writer = vWriter("output",fps, width, height);
	edupt::scene *sceneData = &edupt::scene();
	Time time = Time(fps);
	Animation anim = Animation(&time, sceneData);
	anim.AddWork(&sceneData->spheres[6].color.y,0.75,0.,1.);
	anim.AddWork(&sceneData->kIor, 1.5, 0, 1.);


	//animation
	double timelimit = 5;
	for (; time.getSceneTime() < timelimit; time++) {
    double process = time.getSceneTime() / timelimit;
		std::cout << process * 100 << "% remaining time:" << std::to_string((double)time.ElapsedTime() / process * (1.0 - process)/CLOCKS_PER_SEC/60) << " minutes" << std::endl;
		anim.Update();
		edupt::Color *image = edupt::render(width, height, 4, sampling, time.getSceneTime(),sceneData ,writer);
	}
	return 0;
}
