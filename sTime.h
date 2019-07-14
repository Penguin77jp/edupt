#pragma once

#include <time.h>

class sTime {
private:
	int fps;
	int currentFPS;
  clock_t clock_start;
  double timeLimit;

public:
  sTime(int fps, double getLimit);
  sTime& operator++ (int);
  const double getSceneTime();
  const int getFPS();
  const double getTimeLimit();
  const double Process();
  clock_t ElapsedTime();
};
