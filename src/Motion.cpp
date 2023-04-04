#include "Motion.hpp"

#include <assert.h>

float Motion::linear(float time) {
	assert(0 <= time && time <= 1);
	return time;
}

float Motion::Bezier(float time) {
	assert(0 <= time && time <= 1);
	return time * time * (3.0f - 2.0f * time);
}

float Motion::parametric(float time) {
	assert(0 <= time && time <= 1);
	return time * time / (time * time + (1.0f - time) * (1.0f - time));
}