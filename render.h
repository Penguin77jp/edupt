#ifndef _RENDER_H_
#define _RENDER_H_

#include <iostream>

#include "radiance.h"
#include "ppm.h"
#include "random.h"
#include "vWriter.h"
#include "scene.h"
#include "sTime.h"
#include "pWriter.h"

namespace edupt {

  void render(const int width, const int height, const int samples, const int supersamples, sTime time, scene* sceneData, vWriter writer);

};

#endif
