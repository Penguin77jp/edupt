#pragma once
#include <opencv2/opencv.hpp>
#include "material.h"

using namespace edupt;

class vWriter {
private:
	int width, height,fps;

	inline double clamp(double x) {
		if (x < 0.0)
			return 0.0;
		if (x > 1.0)
			return 1.0;
		return x;
	}
	inline int to_int(double x) {
		return int(pow(clamp(x), 1 / 2.2) * 255 + 0.5);
	}

public:
	cv::VideoWriter writer;
  vWriter(std::string fileName, int fps, int width, int height);

  void Write(Color* Color);
};
