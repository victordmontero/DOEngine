#pragma once

#include <algorithm>
#include <random>

template <typename V1, typename V2>
struct Optional
{
    V1 v1;
    V2 v2;
};

template <typename T = long>
inline T getRandomInt(const T startRange, const T endRange)
{
    std::random_device rd;
    std::uniform_int_distribution<T> dist(startRange, endRange);
    return dist(rd);
}

template <typename T = double>
inline T getRandomReal(const T startRange, const T endRange)
{
    std::random_device rd;
    std::uniform_real_distribution<T> dist(startRange, endRange);
    return dist(rd);
}

template <typename T = double>
inline T getPercentageFrom(const T currentValue, const T maxValue)
{
    return currentValue;
}

template <typename T>
T clamp(const T v, const T min, const T max)
{
    return std::min(max, std::max(v, min));
}
