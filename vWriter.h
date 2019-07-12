#pragma once
#include <opencv2/opencv.hpp>


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
	vWriter(std::string fileName,int fps ,int width, int height) {
		cv::VideoWriter writer(fileName + ".avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));
		this->writer = writer;
		this->width = width;
		this->height = height;
		this->fps = fps;
	}

	void Write(edupt::Color* Color) {
		cv::Mat frame(cv::Size(width,height), CV_8UC3);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				frame.data[y * width * 3 + x * 3] = to_int(Color[y * width + x].z);
				frame.data[y * width * 3 + x * 3 + 1] = to_int(Color[y * width + x].y);
				frame.data[y * width * 3 + x * 3 + 2] = to_int(Color[y * width + x].x);
			}
		}
		writer << frame;

	}
};
