#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H

#include "Vector2D.h"

template<class Iterator, class Object>
void bubble_sort(Iterator begin, Iterator end, Object object) {
    bool ordered;
    int k = 0;
    do {
        ordered = true;
        for (Iterator i = begin; i != std::prev(end, k); i++) {
            if (object->compare(*i, *(std::prev(i, 1)))) {
                std::iter_swap(i, std::prev(i, 1));
                ordered = false;
            }
        }
        k++;
    } while (!ordered);
}

#endif //GAME_UTILITY_H
