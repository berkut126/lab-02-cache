// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#include <header.hpp>
#include <Cache.h>
#include <ForwardIterator.h>
#include <BackwardIterator.h>
#include <RandomIterator.h>

cache::cache(int size) noexcept : holder_(size){
    std::iota(holder_.begin(), holder_.end(), 1);
}

uint32_t cache::operator[](int position) noexcept {
    return holder_[position];
}

forward_iterator cache::begin() noexcept {
    return forward_iterator(0, this);
}

forward_iterator cache::end() noexcept {
  return forward_iterator(holder_.size(), this);
}

backward_iterator cache::rbegin() noexcept {
  return backward_iterator(static_cast<int>(holder_.size()), this);
}

backward_iterator cache::rend() noexcept {
  return backward_iterator(0, this);
}

random_iterator cache::begin_random() noexcept {
  return random_iterator(0, this);
}

random_iterator cache::end_random() noexcept {
  return random_iterator(holder_.size(), this);
}

int cache::size() noexcept {
return static_cast<int>(holder_.size()) * 32 / 1024 / 1024;
}
