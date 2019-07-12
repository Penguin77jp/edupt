#pragma once

#include <time.h>

class Time {
private:
	int fps;
	int currentFPS;
  clock_t clock_start;
  double timeLimit;

public:
	Time(int fps, double getLimit) {
		this->fps = fps;
		this->timeLimit = getLimit;
		currentFPS = 0;
    clock_start = clock();
	}
	Time& operator++ (int){
		currentFPS++;
		return *this;
	}
	const double getSceneTime() {
		return (double)currentFPS / fps;
	}
	const int getFPS() {
		return currentFPS;
	}
	const double getTimeLimit() {
		return timeLimit;
	}
	const double Process() {
		return (double)currentFPS / fps / timeLimit;
	}

  inline clock_t ElapsedTime() {
    return clock() - clock_start;
  }
};
