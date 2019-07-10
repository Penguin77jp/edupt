#pragma once

#include "Time.h"
#include "scene.h"
#include <vector>

template<typename T>
using Vector = std::vector<T>;

class Work {
public:
	double* targetVar;
	double startValue;
	double targetValue;
	double timelimit;

	Work(double* getTargetVar,double startValue, double targetValue, double timelimit) {
		this->targetVar = getTargetVar;
		this->startValue = startValue;
		this->targetValue = targetValue;
		this->timelimit = timelimit;
	}
};

class Animation{
public:
	Time *time;
	edupt::scene *sceneData;
	Vector<Work> works;
	

	Animation(Time *time, edupt::scene *sceneData) {
		this->time = time;
		this->sceneData = sceneData;
	}

	void AddWork(double* getTargetVar, double startValue,double targetValue,double timelimit) {
		auto temp = Work(getTargetVar,startValue,targetValue,timelimit);
		works.push_back(temp);
	}

	void Update() {
		for (int i = 0; i < works.size(); i++) {
			auto working = works.at(i);
			double tp = time->getSceneTime() / working.timelimit;
			*working.targetVar = (1 - tp) * working.startValue + tp * working.targetValue;
		}
	}

	//void Animation(int* targetVar, int targetValue, double target, ) {

	//}


};

