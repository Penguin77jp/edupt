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

LookAt::LookAt(scene& sceneData, double timeStart, double timeLimit, sTime& tmie, Vec lookPoint, Vec &originPoint):sceneData(sceneData),AnimationWork(timeStart,timeLimit,time),lookPoint(lookPoint),originPoint(originPoint){}

void LookAt::UpdateAnimation() {
  Vec z = normalize(lookPoint - originPoint);
  Vec x = normalize(cross(upVec, z));
  Vec y = normalize(cross(x, z));
  printf("%f, %f, %f\n", x.x, x.y, x.z);
  printf("%f, %f, %f\n", y.x, y.y, y.z);
  printf("%f, %f, %f\n",z.x,z.y,z.z);

  sceneData.camera_dir = z;
  sceneData.camera_up = x;
}
