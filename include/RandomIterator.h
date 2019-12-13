// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#pragma once
#include <header.hpp>

class cache;

class random_iterator {
 public:
  random_iterator(int position, cache *cache) noexcept;
  random_iterator &operator++() noexcept;
  random_iterator operator++(int) noexcept;
  bool operator!=(random_iterator other) noexcept;
  uint32_t operator*() noexcept;

 private:
  int holder_;
  cache *reference_;
};
