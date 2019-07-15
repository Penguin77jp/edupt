#pragma once

#include <string>
#include <opencv2/opencv.hpp>
#include <cmath>

#include "material.h"
#include "vec.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
using namespace cv;
using namespace edupt;

class Texture {
private :
  Mat image;
  double radius;
public :
  Vec2 angle;
  Texture (string textureFname) {
    image = imread(textureFname);
    angle = Vec2();
  }

  Vec2 Normal2UV(Vec3 getPosi) {
    radius = getPosi.length();
    double theta = acos(getPosi.z / radius);
    double phi = asin(getPosi.y / radius / sin(theta));
    return Vec2(isnan(phi)?0:phi, isnan(theta) ? 0 : theta);
  }

  Color Normal2Color(Vec3 getPosi) {
    Vec2 uv = Normal2UV(getPosi);
    uv.x = (uv.x + M_PI) / (M_PI*2) + angle.x;
    uv.y = uv.y / (M_PI * 2) + angle.y;

    while (uv.x > 1)
      uv.x -= 1;
    while (uv.y > 1)
      uv.y -= 1;

    int x = uv.x * image.cols+0.5;
    int y = uv.y * image.rows+0.5;

    int pix = 0;
    Color avg = Color();
    for (int py = -pix; py <= pix; py++) {
      for (int px = -pix; px <= pix; px++) {
        
        avg.x += image.data[UV2arrayIndex(x + px, y + py, 2)];
        avg.y += image.data[UV2arrayIndex(x + px, y + py, 1)];
        avg.z += image.data[UV2arrayIndex(x + px, y + py, 0)];
      }
    }
    avg.x /= pow(1 + pix * 2, 2);
    avg.y /= pow(1 + pix * 2, 2);
    avg.z /= pow(1 + pix*2, 2);

    avg.x = image.data[UV2arrayIndex(x, y , 2)];
    avg.y = image.data[UV2arrayIndex(x, y , 1)];
    avg.z = image.data[UV2arrayIndex(x, y , 0)];

    return Color(avg.x/255,avg.y/255, avg.z/255);
  }

  int UV2arrayIndex(int getX, int getY,int bgr) {
    if (getX < 0)
      getX = 0;
    if (getX >= image.cols)
      getX = image.cols - 1;
    if (getY < 0)
      getY = 0;
    if (getY >= image.rows)
      getY = image.rows - 1;

    return getY * image.cols * 3 + getX * 3 + bgr;
  }
};
