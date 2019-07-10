#pragma once

class Time {
private:
	int fps;
	int currentFPS;
public:
	Time(int fps) {
		this->fps = fps;
		currentFPS = 0;
	}
	Time& operator++ (int){
		currentFPS++;
		return *this;
	}
	const double getTime() {
		return (double)currentFPS / fps;
	}
	const int getFPS() {
		return currentFPS;
	}
};