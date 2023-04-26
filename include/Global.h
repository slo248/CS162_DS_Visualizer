#ifndef HNEED_H
#define HNEED_H

#include "Colors.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <functional>
#include <cassert>
#include <cmath>
#include <vector>

typedef std::function<void(float)> functor;

enum VisualDir {FORWARD, BACKWARD};
enum VisualType {AUTO, STEP_BY_STEP};
enum NodeType {CIRCLE, SQUARE};

#endif // HNEED_H