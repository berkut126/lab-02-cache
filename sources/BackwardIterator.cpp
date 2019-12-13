// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#include <Cache.h>
#include <BackwardIterator.h>
#include <header.hpp>

backward_iterator::backward_iterator(int position, cache* cache) noexcept
    : holder_(position), reference_(cache) {}

backward_iterator& backward_iterator::operator++() noexcept {
  --holder_;
  return *this;
}

backward_iterator backward_iterator::operator++(int) noexcept {// NOLINT
  const backward_iterator temp(holder_, reference_);
  --holder_;
  return temp;
}

bool backward_iterator::operator!=(backward_iterator other) noexcept {
  return holder_ != other.holder_;
}

uint32_t backward_iterator::operator*() noexcept {
    return (*reference_)[holder_ - 1];
}
