#pragma once

#include "Time.h"
#include <cmath>
#include <iostream>

class AnimationWork {
public:
  double* targetVar;
  Time* time;
  double timeStart;
  double timeLimit;

  AnimationWork(double *targetVar, double timeStart,double timeLimit);

  virtual void UpdateAnimation();
};

class LinerAnimation : public AnimationWork {
public:
  double startValue;
  double targetValue;


  LinerAnimation(double* getTargetVar, double timeStart, double timelimit, double startValue, double targetValue);

  void UpdateAnimation();
};

class TrigonometricAnimation : public AnimationWork {
public:
  enum e_TrigonType {
    sin, cos, tan,
  };
  double speed = 1;
  double offset = 0;
  TrigonometricAnimation(double* targetVar, double timeStart, double timeLimit, e_TrigonType trigonType);

  void UpdateAnimation();

private:
  e_TrigonType trigonType;
};
