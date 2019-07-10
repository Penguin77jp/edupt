#pragma once

#include <time.h>

class Time {
private:
	int fps;
	int currentFPS;
  clock_t clock_start;

public:
	Time(int fps) {
		this->fps = fps;
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

  inline clock_t ElapsedTime() {
    return clock() - clock_start;
  }
};
