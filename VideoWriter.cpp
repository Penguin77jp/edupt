#include "VideoWriter.h"
#include <opencv2/opencv.hpp>


double clamp(double x) {
  if (x < 0.0)
    return 0.0;
  if (x > 1.0)
    return 1.0;
  return x;
}
int to_int(double x) {
  return int(pow(clamp(x), 1 / 2.2) * 255 + 0.5);
}

void VideoWrite(std::string fileName,edupt::Color *Color,int width,int height) {
  cv::VideoWriter writer(fileName+".avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 60, cv::Size(width, height));
  cv::Mat frame(width, height, CV_8UC3);;



  for (int f = 0; f < 60*width*height*3; f++) {
    frame.data[f] = 255;

    /*
    std::cout << (float)f / (60 * 60) << std::endl;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        frame.data[y * width * 3 + x * 3] = 255;
        frame.data[y * width * 3 + x * 3 + 1] = 0;
        frame.data[y * width * 3 + x * 3 + 2] = 0;
      }
    }
    */
  }

}
