#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <fstream>
#include <list>
#include <vector>
#include <random>

template<typename Base, typename T>
inline bool isInstanceOf(const T*) {
    return std::is_base_of<Base, T>::value;
}

template<typename T>
T random(T range_from, T range_to) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<T> distr(range_from, range_to);
    return distr(generator);
}

#endif //GAME_UTILS_H
