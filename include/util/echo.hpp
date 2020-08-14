#pragma once
#include <iostream>
#include <type_traits>

/**
 *  Debug macro printing expression on screen
 *  before evaluating it.
 */
#define ECHO(X)                             \
    ([&] (auto const& x)                    \
     -> std::remove_const_t<decltype(X)> {  \
        std::cout                           \
            << (#X) << " : "                \
            << (X);                         \
        return x;                           \
    }(X))

/**
 *  Same as ECHO and add a new line after
 *  output.
 */
#define ECHO_LN(X)                          \
    ([&] (auto const& x)                    \
     -> std::remove_const_t<decltype(X)> {  \
        std::cout                           \
            << (#X) << " : "                \
            << (X) << "\n";                 \
        return x;                           \
    }(X))
