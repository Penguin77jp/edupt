#pragma once

#include "AnimationWork.h"
#include "Time.h"
#include "scene.h"
#include <vector>

template<typename T>
using Vector = std::vector<T>;

class Animation {
public:
	Time* time;
	edupt::scene* sceneData;
	Vector<AnimationWork*> works;


	Animation(Time* time, edupt::scene* sceneData) {
		this->time = time;
		this->sceneData = sceneData;
	}

	void AddWork(AnimationWork *getWork) {
    works.emplace_back(getWork);
	}

	void Update() {
    for (auto& elm : works)
      elm->UpdateAnimation();
	}
};

