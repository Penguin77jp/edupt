#include "pWriter.h"

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

void pWrite(const std::string& filename, const Color* image, const int width, const int height) {
  std::cout << "output!!" << std::endl;
  cv::Mat mat = cv::Mat(cv::Size(width, height), CV_8UC3);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      mat.data[y * width * 3 + x * 3] = to_int(image[y * width + x].z);
      mat.data[y * width * 3 + x * 3 + 1] = to_int(image[y * width + x].y);
      mat.data[y * width * 3 + x * 3 + 2] = to_int(image[y * width + x].x);
    }
  }
  cv::imwrite("test.jpg", mat);
}
