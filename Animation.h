#pragma once

#include "Time.h"
#include "scene.h"
#include <cmath>
#include <vector>

template<typename T>
using Vector = std::vector<T>;

class Work {
public:
	double* targetVar;
	Time* time;
	double timeStart;
	double timelimit;

	virtual void UpdateAnimation();
};

class LinerAnimation : Work {
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

	void UpdateAnimation() {
		double tp = (time->getSceneTime() - timeStart) / (timelimit - timeStart);
		if (tp >= 0 && tp < 1) {
			*targetVar = (1 - tp) * startValue + tp * targetValue;
		}
	}
};

class TrigonometricAnimation : Work {
public:
	enum e_TrigonType {
		sin, cos, tan,
	};
	double speed = 1;
	double offset = 0;
	TrigonometricAnimation(double* getTargetVar, double timeStart, double timelimit, e_TrigonType getType) {
		this->targetVar = getTargetVar;
		this->timeStart = timeStart;
		this->timelimit = timelimit;
		this->trigonType = getType;
	}

	void UpdateAnimation() {
		double tp = (time->getSceneTime() - timeStart) / (timelimit - timeStart);
		if (tp >= 0 && tp < 1) {
			auto cal_time = (time->getSceneTime() - timeStart) * speed;
			double cal;
			
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
			*targetVar = cal + offset;
		}
	}

private:
	e_TrigonType trigonType;
};

class Animation {
public:
	Time* time;
	edupt::scene* sceneData;
	Vector<Work> works;


	Animation(Time* time, edupt::scene* sceneData) {
		this->time = time;
		this->sceneData = sceneData;
	}

	void AddWork(Work getWork) {
		works.push_back(getWork);
	}

	void Update() {
		for (int i = 0; i < works.size(); i++) {
			works.at(i).UpdateAnimation();
		}
	}

	//void Animation(int* targetVar, int targetValue, double target, ) {

	//}


};

