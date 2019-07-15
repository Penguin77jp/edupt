#include "AnimationWork.h"

AnimationWork::AnimationWork(double timeStart, double timeLimit, sTime& time): timeStart(timeStart), timeLimit(timeLimit), time(time){}

LinerAnimation::LinerAnimation(double& targetVar, double timeStart, double timeLimit, sTime& time, double startValue, double targetValue) : targetVar(targetVar),AnimationWork(timeStart, timeLimit, time), startValue(startValue), targetValue(targetValue) {}

void LinerAnimation::UpdateAnimation() {
  double tp = (time.getSceneTime() - timeStart) / (timeLimit - timeStart);
  if (tp >= 0 && tp < 1) {
    targetVar = (1 - tp) * startValue + tp * targetValue;
  }
}

TrigonometricAnimation::TrigonometricAnimation(double &targetVar, double timeStart,double timeLimit, sTime& time, e_TrigonType trigonType,double size, double speed,double offset) : targetVar(targetVar),AnimationWork(timeStart, timeLimit, time), trigonType(trigonType),size(size), speed(speed),offset(offset) {}

void TrigonometricAnimation::UpdateAnimation() {
  double tp = (time.getSceneTime() - timeStart) / (timeLimit - timeStart);
  if (tp >= 0 && tp < 1) {
    auto cal_time = (time.getSceneTime() - timeStart) * speed;
    double cal = 0;

    switch (trigonType)
    {
    case sin:
      cal = std::sin(cal_time);
      break;
    case cos:
      cal = std::cos(cal_time);
      break;
    case tan:
      cal = std::tan(cal_time);
      break;
    default:
      break;
    }
    targetVar = cal*size + offset;
  }
}

LookAt::LookAt(scene& sceneData, double timeStart, double timeLimit, sTime& tmie, Vec3 lookPoint, Vec3 &originPoint):sceneData(sceneData),AnimationWork(timeStart,timeLimit,time),lookPoint(lookPoint),originPoint(originPoint){}

void LookAt::UpdateAnimation() {
  Vec3 z = normalize(lookPoint - originPoint);
  Vec3 x = normalize(cross(Vec3(0,1,0), z));
  Vec3 y = normalize(cross(z, x));

  sceneData.camera_dir = z;
  sceneData.camera_up = y;
}
