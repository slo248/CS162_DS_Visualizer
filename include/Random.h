#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r){
    return std::uniform_int_distribution<int>(l, r)(rng);
}

#endif