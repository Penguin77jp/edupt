#pragma once

#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <opencv2/opencv.hpp>
#include "material.h"
#include "vWriter.h"

using namespace edupt;


inline double clamp(double x);
inline int to_int(double x);
void pWrite(const std::string& filename, const Color* image, const int width, const int height);
