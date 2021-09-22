#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <fstream>
#include <list>
#include <vector>

template<typename Base, typename T>
inline bool isInstanceOf(const T*) {
    return std::is_base_of<Base, T>::value;
}

#endif //GAME_UTILS_H
