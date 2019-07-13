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
	Vector<AnimationWork> works;


	Animation(Time* time, edupt::scene* sceneData) {
		this->time = time;
		this->sceneData = sceneData;
    works = Vector<AnimationWork>();
	}

	void AddWork(AnimationWork getWork) {
		works.push_back(getWork);
	}

	void Update() {
		for (int i = 0; i < works.size(); i++) {
			works.at(i).UpdateAnimation();
		}
	}
};

