#include "Container.h"

Container::Container() : mSize(0) {}

int Container::size() const { return mSize; }

bool Container::empty() const { return !mSize; }
