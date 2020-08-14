#pragma once
#include "Token.hpp"
#include <optional>
#include <string>
#include <tuple>


 template <typename T>
using parsing_result_t = std::tuple<std::optional<T>, std::string_view>;

auto parse_operator(std::string_view) -> parsing_result_t<Operator_token>;
auto parse_operand(std::string_view) -> parsing_result_t<Operand_token>;

auto parse_token(std::string_view) -> parsing_result_t<Token>;
