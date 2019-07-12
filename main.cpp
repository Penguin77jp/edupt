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

	//const int width = 640, height = 480, sampling = 10, fps = 15;
	const int width = 250, height = 250, sampling = 250, superSamples = 2, fps = 15;

	vWriter writer = vWriter("output", fps, width, height);
	edupt::scene* sceneData = &edupt::scene();
	Time time = Time(fps, 0.001);
	Animation anim = Animation(&time, sceneData);
	Work test = TrigonometricAnimation(&sceneData->camera_position.x, 0, 4, TrigonometricAnimation::e_TrigonType::sin);
	anim.AddWork((Work));
	

	//animation
	for (; time.getSceneTime() < time.getTimeLimit(); time++) {
		double process = time.getSceneTime() / time.getTimeLimit();
		std::cout << process * 100 << "% remaining time:" << std::to_string((double)time.ElapsedTime() / process * (1.0 - process) / CLOCKS_PER_SEC / 60) << " minutes" << std::endl;
		anim.Update();
		edupt::Color* image = edupt::render(width, height, sampling, superSamples, time, sceneData, writer);
	}
	return 0;
}
