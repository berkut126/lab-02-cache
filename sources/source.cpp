// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#include <header.hpp>
#include <Cache.h>
#include <ForwardIterator.h>
#include <BackwardIterator.h>
#include <RandomIterator.h>

inline cache operator"" _mb(unsigned long long int size){// NOLINT
    return cache(static_cast<int>(size) * 1024 * 1024 / 32);
}

int main(){
    cache cache_sizes[]{1_mb, 2_mb, 4_mb, 8_mb};
    for (auto& current : cache_sizes) {
        std::for_each(current.begin(), current.end(),
        [&](uint32_t it) {
            ++it;
        });
        std::for_each(current.begin(), current.end(),
        [&](uint32_t it) {
            ++it;
        });
        std::for_each(current.begin(), current.end(),
        [&](uint32_t it) {
            ++it;
        });
        std::for_each(current.begin(), current.end(),
        [&](uint32_t it) {
            ++it;
        });
        std::for_each(current.begin(), current.end(),
        [&](uint32_t it) {
            it -= 4;
        });

        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < 1000; ++i){
            std::for_each(current.begin(), current.end(),
            [&](uint32_t it) {
                ++it;
            });
        }
        auto end = std::chrono::steady_clock::now();
        auto span = std::chrono::
                duration_cast<std::chrono::duration<double>>(end - start);
        std::cout << "Cache " << current.size() <<
        "mb forward: " << span.count() << " seconds.\n";

        start = std::chrono::steady_clock::now();
        for (int i = 0; i < 1000; ++i){
            std::for_each(current.rbegin(), current.rend(),
            [&](uint32_t it){
                --it;
            });
        }
        end = std::chrono::steady_clock::now();
        span = std::chrono::
                duration_cast<std::chrono::duration<double>>(end - start);
        std::cout << "Cache " << current.size() <<
        "mb backward: " << span.count() << " seconds.\n";

        start = std::chrono::steady_clock::now();
        for (int i = 0; i < 1000; ++i) {
            std::for_each(current.begin_random(), current.end_random(),
            [&](uint32_t it) {
                it *= 2;
                it /= 2;
            });
        }
        end = std::chrono::steady_clock::now();
        span = std::chrono::
                duration_cast<std::chrono::duration<double>>(end - start);
        std::cout << "Cache " << current.size() <<
        "mb random: " << span.count() << " seconds.\n";
    }
}
