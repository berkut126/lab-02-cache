// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#include <RandomIterator.h>
#include <Cache.h>
#include <header.hpp>

random_iterator::random_iterator(int position, cache* cache) noexcept
    : holder_(position), reference_(cache) {
  srand(time(nullptr));
}

random_iterator& random_iterator::operator++() noexcept {
  ++holder_;
  return *this;
}
// NOLINT(readability/casting)
random_iterator random_iterator::operator++(int) noexcept {
  const random_iterator temp(holder_, reference_);
  ++holder_;
  return temp;
}

bool random_iterator::operator!=(random_iterator other) noexcept {
  return holder_ != other.holder_;
}

uint32_t random_iterator::operator*() noexcept {
  return (*reference_)[rand() % (reference_ -> holder_.size())];
}
