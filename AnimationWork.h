#pragma once

#include "Time.h"
#include <cmath>
#include <iostream>

class AnimationWork {
public:
  double* targetVar;
  Time* time;
  double timeStart;
  double timelimit;

  virtual void UpdateAnimation(){}
};

class LinerAnimation : public AnimationWork {
public:
  double startValue;
  double targetValue;


  LinerAnimation(double* getTargetVar, double timeStart, double timelimit, double startValue, double targetValue) {
    this->timeStart = timeStart;
    this->targetVar = getTargetVar;
    this->startValue = startValue;
    this->targetValue = targetValue;
    this->timelimit = timelimit;
  }

  void UpdateAnimation() override{
    double tp = (time->getSceneTime() - timeStart) / (timelimit - timeStart);
    if (tp >= 0 && tp < 1) {
      *targetVar = (1 - tp) * startValue + tp * targetValue;
    }
  }
};

class TrigonometricAnimation : public AnimationWork {
public:
  enum e_TrigonType {
    sin, cos, tan,
  };
  double speed = 1;
  double offset = 0;
  TrigonometricAnimation(double* getTargetVar, double timeStart, double timelimit, e_TrigonType getType) {
    std::cout << "sin" << std::endl;
    this->targetVar = getTargetVar;
    this->timeStart = timeStart;
    this->timelimit = timelimit;
    this->trigonType = getType;
  }

  void UpdateAnimation() override{
    double tp = (time->getSceneTime() - timeStart) / (timelimit - timeStart);
    if (tp >= 0 && tp < 1) {
      auto cal_time = (time->getSceneTime() - timeStart) * speed;
      double cal=0;

      switch (trigonType)
      {
      sin:
        cal = std::sin(cal_time);
        break;
      cos:
        cal = std::cos(cal_time);
        break;
      tan:
        cal = std::tan(cal_time);
        break;
      default:
        break;
      }
      std::cout << cal << std::endl;
      *targetVar = cal + offset;
    }
  }

private:
  e_TrigonType trigonType;
};
