#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H

template<class Iterator, class Compare>
void bubble_sort(Iterator begin, Iterator end, Compare compare) {
    bool ordered;
    int k = 0;
    do {
        ordered = true;
        for(Iterator i = begin; i != std::prev(end, k); i++) {
            if(compare(*i, *(std::prev(i, 1)))) {
                std::iter_swap(i, std::prev(i, 1));
                ordered = false;
            }
        }
        k++;
    } while(!ordered);
}

#endif //GAME_UTILITY_H
