// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#include <header.hpp>
#include <Cache.h>
#include <ForwardIterator.h>

forward_iterator::forward_iterator(int position, cache *cache) noexcept :
holder_(position), reference_(cache){}

forward_iterator& forward_iterator::operator++() noexcept {
  ++holder_;
  return *this;
}

forward_iterator forward_iterator::operator++(int) noexcept {// NOLINT
  const forward_iterator temp(holder_, reference_);
  ++holder_;
  return temp;
}

bool forward_iterator::operator!=(forward_iterator other) noexcept {
    return holder_ != other.holder_;
}

uint32_t forward_iterator::operator*() noexcept {
    return (*reference_)[holder_];
}
