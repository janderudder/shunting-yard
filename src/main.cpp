#include "parse_infix_expression.hpp"
#include "parse_token.hpp"
#include "to_postfix_expression.hpp"
#include "to_string.hpp"
#include "Token.hpp"
#include <iostream>


int main(int const argc, char const* const* const argv)
{
    if (argc < 2) {
        std::cout << "Please enter an input string.\n";
        return -1;
    }

    auto const input = argv[1];

    std::cout << "\ninput string: " <<  input << "\n\n";

    auto const [tokens, erroneous_parsing_result] = parse_infix_expression(input);

    if (erroneous_parsing_result) {
        std::cout << to_string(*erroneous_parsing_result) << "\n\n";
    }

    std::cout << "tokens (" << tokens.size() << "):\n";

    for (auto const& token : std::as_const(tokens)) {
        std::cout << "'" << to_string(token) << "'\n";
    }
    std::cout << "\n";

    auto const prefix_expression = to_postfix_expression(tokens);

    std::cout << "postfix notation:\n";
    for (auto const& token : prefix_expression) {
        std::cout << to_string(token) << " ";
    }
    std::cout << "\n";
}
