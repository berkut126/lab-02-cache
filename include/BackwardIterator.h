// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#pragma once
#include <header.hpp>

class cache;

class backward_iterator {
 public:
  backward_iterator(int position, cache *cache) noexcept;
  backward_iterator &operator++() noexcept;
  backward_iterator operator++(int) noexcept;
  bool operator!=(backward_iterator other) noexcept;
  uint32_t operator*() noexcept;

 private:
  int holder_;
  cache *reference_;
};
