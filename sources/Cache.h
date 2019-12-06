//
// Created by rooted on 06.12.2019.
//

#include <header.hpp>

#ifndef TEMPLATE_CACHE_H
#define TEMPLATE_CACHE_H


class Cache {

public:
    explicit Cache(int n) noexcept;
    typedef int iterator;
    iterator begin();
    iterator end();



private:
    std::vector<int8_t> holder;
};

class CacheIterator:std::Ite


#endif //TEMPLATE_CACHE_H
