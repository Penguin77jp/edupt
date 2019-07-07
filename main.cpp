#include <iostream>
#include<opencv2/opencv.hpp>

#include "render.h"

int main(int argc, char **argv) {
	std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

	// 640x480の画像、(2x2) * 4 sample / pixel
	edupt::render(100, 100, 4, 5);
}
