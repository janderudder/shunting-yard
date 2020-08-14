#pragma once
#include "Token.hpp"
#include "parse_token.hpp"
#include <optional>
#include <string_view>
#include <tuple>
#include <vector>


auto parse_expression(std::string_view input)
 -> std::tuple<std::vector<Token>, std::optional<parsing_result_t<Token>>>;
