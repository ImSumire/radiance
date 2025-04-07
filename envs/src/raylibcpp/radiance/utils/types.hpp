#pragma once

#include <optional>
#include <variant>


// Option
template<class T>
using Option = std::optional<T>;

constexpr std::nullopt_t None = std::nullopt;

template <class T>
Option<T> Some(T value) {
    return std::make_optional(value);
}

// Modernize names
typedef size_t usize;
