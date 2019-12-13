// Copyright 2019 Andrey Ivanov <berkut126@gmail.com>

#pragma once
#include <header.hpp>

class forward_iterator;
class backward_iterator;
class random_iterator;

class cache {
  friend class forward_iterator;
  friend class backward_iterator;
  friend class random_iterator;
 public:
  explicit cache(int size) noexcept;
  uint32_t operator[](int position) noexcept;
  forward_iterator begin() noexcept;
  forward_iterator end() noexcept;
  backward_iterator rbegin() noexcept;
  backward_iterator rend() noexcept;
  random_iterator begin_random() noexcept;
  random_iterator end_random() noexcept;
  int size() noexcept;
 private:
  std::vector<uint32_t> holder_;
};