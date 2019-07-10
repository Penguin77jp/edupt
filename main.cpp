#include <iostream>
#include<opencv2/opencv.hpp>

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
	int timelimit = 1;
	for (; time.getTime() < timelimit; time++) {
		std::cout << time.getTime() / timelimit * 100 << "%" << std::endl;
		anim.Update();
		edupt::Color *image = edupt::render(width, height, 4, sampling, time.getTime(),sceneData ,writer);
	}
	return 0;
}
