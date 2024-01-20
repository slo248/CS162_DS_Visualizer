#include "Container.h"

Container::Container() : mSize(0) {}

Container::~Container() {
    // empty by default
}

int Container::size() const { return mSize; }

bool Container::empty() const { return !mSize; }
