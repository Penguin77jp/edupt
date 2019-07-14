#include "sTime.h"

  sTime::sTime(int fps, double getLimit) {
    this->fps = fps;
    this->timeLimit = getLimit;
    currentFPS = 0;
    clock_start = clock();
  }
  sTime& sTime::operator++ (int) {
    currentFPS++;
    return *this;
  }
  const double sTime::getSceneTime() {
    return (double)currentFPS / fps;
  }
  const int sTime::getFPS() {
    return currentFPS;
  }
  const double sTime::getTimeLimit() {
    return timeLimit;
  }
  const double sTime::Process() {
    return (double)currentFPS / fps / timeLimit;
  }

  clock_t sTime::ElapsedTime() {
    return clock() - clock_start;
  }
