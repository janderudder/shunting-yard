#pragma once
#include "Expression_types.hpp"
#include "parse_token.hpp"
#include "Token.hpp"
#include <optional>
#include <string_view>
#include <tuple>
#include <vector>


auto parse_infix_expression(std::string_view input)
 -> std::tuple<Infix_expression, std::optional<parsing_result_t<Token>>>;
