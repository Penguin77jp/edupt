#include "AnimationWork.h"

AnimationWork::AnimationWork(double& targetVar, double timeStart, double timeLimit, Time& time) : targetVar(targetVar), timeStart(timeStart), timeLimit(timeLimit), time(time) {}

/*

LinerAnimation::LinerAnimation(double& targetVar, double timeStart, double timeLimit, Time& time, double startValue, double targetValue) : AnimationWork(targetVar, timeStart, timeLimit, time), startValue(startValue), targetValue(targetValue) {}

void LinerAnimation::UpdateAnimation() {
  double tp = (time.getSceneTime() - timeStart) / (timeLimit - timeStart);
  if (tp >= 0 && tp < 1) {
    targetVar = (1 - tp) * startValue + tp * targetValue;
  }
}

*/

TrigonometricAnimation::TrigonometricAnimation(double &targetVar, double timeStart,double timeLimit, Time& time, e_TrigonType trigonType) : AnimationWork(targetVar, timeStart, timeLimit, time), trigonType(trigonType) {}

void TrigonometricAnimation::UpdateAnimation() {
  double tp = (time.getSceneTime() - timeStart) / (timeLimit - timeStart);
  if (tp >= 0 && tp < 1) {
    auto cal_time = (time.getSceneTime() - timeStart) * speed;
    double cal = 0;

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
    targetVar = cal + offset;
  }
}

