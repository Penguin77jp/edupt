#pragma once

#include "AnimationWork.h"
#include "sTime.h"
#include "scene.h"
#include <vector>


template<typename T>
using Vector = std::vector<T>;

class Animation {
public:
  sTime* time;
  edupt::scene* sceneData;
  Vector<AnimationWork*> works;


  Animation(sTime* time, edupt::scene* sceneData);

  void AddWork(AnimationWork* getWork);

  void Update();
};

