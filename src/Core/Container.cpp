#include "Container.h"

using namespace Core;

Container::Container() : mSize(0) {}

int Container::size() const { return mSize; }

bool Container::empty() const { return !mSize; }
