#include <iostream>
#include<opencv2/opencv.hpp>

#include "render.h"
#include "vWriter.h"

int main(int argc, char **argv) {
	std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

	// 640x480の画像、(2x2) * 4 sample / pixel
  vWriter writer = vWriter("test",100,100);
  int time = 60 * 3.14 * 2;
  for (int f = 0; f < time; f++) {
    std::cout << (float)f / time*100 << "%" << std::endl;
   edupt::render(100, 100, 4, 5,(float)f/60, writer);
  }
}
