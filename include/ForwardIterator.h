// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#pragma once
#include <header.hpp>

class cache;

class forward_iterator {

public:
  forward_iterator(int position, cache *cache) noexcept;
  forward_iterator& operator++() noexcept;
  forward_iterator operator++(int) noexcept;
  bool operator!=(forward_iterator other) noexcept;
  uint32_t operator*() noexcept;

private:
  int holder_;
  cache *reference_;

};
