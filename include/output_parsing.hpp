#pragma once
#include "parse_token.hpp"
#include "Token.hpp"
#include <iosfwd>


void output_parsing_result(parsing_result_t<Token> const&, std::ostream&);
auto to_string(Operator_token::Id id) -> std::string_view;
auto to_string(Token const& token) -> std::string;
