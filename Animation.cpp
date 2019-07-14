#include "Animation.h"


Animation::Animation(sTime* time, edupt::scene* sceneData) {
  this->time = time;
  this->sceneData = sceneData;
}

void Animation::AddWork(AnimationWork* getWork) {
  works.emplace_back(getWork);
}

void Animation::Update() {
  for (auto& elm : works)
    elm->UpdateAnimation();
}

