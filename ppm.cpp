#include "ppm.h"

namespace edupt {

  void save_ppm_file(const std::string& filename, const Color* image, const int width, const int height) {
    FILE* f = fopen(filename.c_str(), "wb");
    fprintf(f, "P3\n%d %d\n%d\n", width, height, 255);
    for (int i = 0; i < width * height; i++)
      fprintf(f, "%d %d %d ", to_int(image[i].x), to_int(image[i].y), to_int(image[i].z));
    fclose(f);
  }
}


