#pragma once

#include "Time.h"
#include "vec.h"
#include "scene.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace edupt;

class AnimationWork {
public:
  Time& time;
  double timeStart;
  double timeLimit;

  AnimationWork(double timeStart,double timeLimit,Time &time);

  virtual void UpdateAnimation()=0;
};

class LinerAnimation : public AnimationWork {
public:
  LinerAnimation(double& targetVar, double timeStart, double timeLimit,Time &time, double startValue, double targetValue);

  void UpdateAnimation();

private :
  double& targetVar;
  double startValue;
  double targetValue;

};

class TrigonometricAnimation : public AnimationWork {
public:
  enum e_TrigonType {
    sin, cos, tan,
  };
  
  TrigonometricAnimation(double& targetVar, double timeStart, double timeLimit,Time &tmie, e_TrigonType trigonType, double size, double speed , double offset);

  void UpdateAnimation() override;

private:
  double& targetVar;
  e_TrigonType trigonType;
  double speed;
  double offset;
  double size;
};

class LookAt : public AnimationWork {
public:
  LookAt(scene& sceneData, double timeStart, double timeLimit, Time& tmie,Vec lookPoint, Vec &originPoint);

  void UpdateAnimation() override;

private:
  scene& sceneData;
  Vec lookPoint;
  Vec &originPoint;
};
