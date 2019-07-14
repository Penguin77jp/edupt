#include "vWriter.h"

  vWriter::vWriter(std::string fileName, int fps, int width, int height) {
    cv::VideoWriter writer(fileName + ".avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));
    this->writer = writer;
    this->width = width;
    this->height = height;
    this->fps = fps;
  }

  void vWriter::Write(Color* Color) {
    cv::Mat frame(cv::Size(width, height), CV_8UC3);
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        frame.data[y * width * 3 + x * 3] = to_int(Color[y * width + x].z);
        frame.data[y * width * 3 + x * 3 + 1] = to_int(Color[y * width + x].y);
        frame.data[y * width * 3 + x * 3 + 2] = to_int(Color[y * width + x].x);
      }
    }
    writer << frame;

  }
