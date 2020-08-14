#pragma once
#include "Token.hpp"
#include "parse_token.hpp"
#include <optional>
#include <string_view>
#include <tuple>
#include <vector>


using Infix_expression = std::vector<Token>;


auto parse_infix_expression(std::string_view input)
 -> std::tuple<Infix_expression, std::optional<parsing_result_t<Token>>>;
