#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H

#include "Vector2D.h"
#include <memory>

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

template<class T>
struct deleter {
    bool toDelete;
    
    explicit deleter(bool toDelete = true) : toDelete(toDelete) {}
    
    void operator()(T* p) const {
        if (toDelete) { delete p; }
    }
};

template<class T> using u_ptr = std::unique_ptr<T, deleter<T>>;

template<class T>
u_ptr<T> tmp_ptr(T* ptr) {
    return u_ptr<T>(ptr, deleter<T>(false));
}

/*
int* raw = new int(42);
std::unordered_set<u_ptr<int>> myset;
myset.insert(u_ptr<int>(raw));

auto it = myset.find(tmp_ptr(raw));
*/

template<typename Base, typename T>
inline bool isInstanceOf(const T*) {
    return std::is_base_of<Base, T>::value;
}

#endif //GAME_UTILITY_H
