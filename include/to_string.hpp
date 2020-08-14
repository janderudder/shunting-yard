#pragma once
#include "parse_token.hpp"
#include "Token.hpp"
#include <string>


auto to_string(parsing_result_t<Token> const&) -> std::string;
auto to_string(Operator_token::Id id) -> std::string_view;
auto to_string(Token const& token) -> std::string;
